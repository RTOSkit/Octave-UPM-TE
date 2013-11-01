/* OctaveGUI - A graphical user interface for Octave
 * Copyright (C) 2011 Jacob Dawid (jacob.dawid@googlemail.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QSettings>
#include <QStyle>
#include <QToolBar>
#include <QDesktopServices>
#include <QFileDialog>
#include <QMessageBox>
#include <QIcon>

#include "main-window.h"
#include "file-editor.h"


main_window::main_window (QString open_file, QWidget * parent)
	: QMainWindow (parent), octave_event_observer (), _startup_filename_request (open_file)
{
  // We have to set up all our windows, before we finally launch octave.
  _supress_warning = true;
  _matlab_compatible_warning = true;
  _first_read_settings = true;
  _broadcasting_option = 2; // Default broadcasting option
  _debugging = false;
  _profiling = false;
  construct ();
  octave_link::instance ()->launch_octave();

  connect (octave_link::instance()->main_thread(),
	   SIGNAL (ready()),
	   this,
	   SLOT (read_settings()));
}

main_window::~main_window ()
{
}

void
main_window::event_accepted (octave_event *e)
{
  bool update_debug = false;

  if (octave_debug_step_into_event *a = dynamic_cast<octave_debug_step_into_event*>(e))
  {
    update_debug = true;
    Q_UNUSED (a);
  }

  if (octave_debug_step_out_event *a = dynamic_cast<octave_debug_step_out_event*>(e))
  {
    update_debug = true;
    Q_UNUSED (a);
  }

  if (octave_debug_step_over_event *a = dynamic_cast<octave_debug_step_over_event*>(e))
  {
    update_debug = true;
    Q_UNUSED (a);
  }

  if (update_debug)
  {
      handle_debug_in_progress ();
  }

  if (octave_available_toolkits_event *a = dynamic_cast<octave_available_toolkits_event*>(e))
  {
    _current_graphics_toolkit = a->get_current_toolkit ();
    _graphics_toolkits = a->get_toolkits ();
    _settings_dialog->populate_combobox (_graphics_toolkits, _current_graphics_toolkit);
  }

  if (octave_exit_event *a = dynamic_cast<octave_exit_event*>(e))
  {
    Q_UNUSED (a);
    QApplication::quit();
  }

  if (octave_dummy_event *a = dynamic_cast<octave_dummy_event*>(e))
  {
    _already_stopped = false;
    Q_UNUSED (a);
    emit restart_stop_action_timer();
  }

  if (octave_plot_event *a = dynamic_cast<octave_plot_event*>(e))
  {
    Q_UNUSED (a);
    _status_bar->showMessage("");
  }

  if (octave_run_command_event *a = dynamic_cast<octave_run_command_event*> (e))
  {
	  
	  activate_tools (true);

	  if (a->is_profiling ())
	  {
		  octave_map m = a->get_profile_info ();
		  if (!m.is_empty ())
		  {
			  _profiler_dock_widget->set_profile_info (a->get_profile_info ());
			  emit update_profile_info (QString(a->get_cmd_timestamp ().c_str ()));
		  }
		  else
			  emit profile_keeps_on ();
	  }
	  _profiling = false;
  }

  if (octave_infofile_event *a = dynamic_cast<octave_infofile_event*>(e))
	  _help_browser->set_infofile (QString(a->get_infofile ().c_str ()));	  

  delete e;
}

void
main_window::event_reject (octave_event *e)
{
  delete e;
}

void
main_window::new_file ()
{
  _file_editor->request_new_file ();
}

void
main_window::open_file ()
{
  _file_editor->request_open_file ();
}

void
main_window::open_file (const QString &f)
{
	_file_editor->request_open_file (f);
}

void
main_window::save_file()
{
  _file_editor->request_save_file ();
}

void
main_window::save_file_as()
{
  _file_editor->request_save_file_as ();
}

void
main_window::close_file()
{
  _file_editor->request_close_file ();
}


void
main_window::undo()
{
  _file_editor->request_undo ();
}

void
main_window::redo()
{
  _file_editor->request_redo ();
}

void
main_window::copy()
{
  _file_editor->request_copy ();
}

void
main_window::cut()
{
  _file_editor->request_cut ();
}

void
main_window::paste()
{
  _file_editor->request_paste ();
}

void
main_window::find()
{
  _file_editor->request_find ();
}


void
main_window::update_clipboard_actions()
{
  _copy_action->setEnabled (_file_editor->copy_available ());
  _cut_action->setEnabled (_file_editor->copy_available ());
  _comment_selection_action->setEnabled (_file_editor->copy_available ());
  _uncomment_selection_action->setEnabled (_file_editor->copy_available ());
  _paste_action->setEnabled (_file_editor->editor_active ());
  _find_action->setEnabled (_file_editor->editor_active ());
  _undo_action->setEnabled (_file_editor->editor_active ());
  _redo_action->setEnabled (_file_editor->editor_active ());
  /*
  _toggle_bookmark_action->setEnabled (_file_editor->editor_active ());
  _remove_bookmark_action->setEnabled (_file_editor->editor_active ());
  _next_bookmark_action->setEnabled (_file_editor->editor_active ());
  _previous_bookmark_action->setEnabled (_file_editor->editor_active ());
  */
  _next_breakpoint_action->setEnabled (_file_editor->editor_active ());
  _remove_breakpoint_action->setEnabled (_file_editor->editor_active ());
  _previous_breakpoint_action->setEnabled (_file_editor->editor_active ());
  _toggle_breakpoint_action->setEnabled (_file_editor->editor_active ());

  if (!_debugging)
  {
    _run_action->setEnabled (_file_editor->editor_active ());
    _run_and_profile->setEnabled (_run_action->isEnabled());
  }
  _save_action->setEnabled (_file_editor->file_modified ());
  _close_action->setEnabled (_file_editor->editor_active ());
  _save_as_action->setEnabled (_file_editor->editor_active ());
  _jump_to_editor_action->setEnabled (_file_editor->editor_active ());
}

void
main_window::run_file()
{
  QString fn = _file_editor->request_run_file ();
  if (!fn.isEmpty())
  {
    activate_tools (false);
    if (!_terminal_dock_widget->isVisible())
	    _terminal_dock_widget->show();
	
    QFileInfo file_info (fn);
    QString path = file_info.absolutePath ();
    QString function_name = file_info.fileName ();
    function_name.chop (file_info.suffix ().length () + 1);
    if (QDir(path) != QDir(_current_directory))
    {
      QMessageBox msgBox;
      msgBox.setText(tr ("The file is not in the current directory. Do you want to change the current directory?"));
      msgBox.setInformativeText(tr ("New current directory: %1").arg(path));
      msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
      msgBox.setDefaultButton(QMessageBox::No);
      int ret = msgBox.exec();      
      if (QMessageBox::Yes == ret)
      {
	      _terminal->sendText (QString ("cd \'%1\'\n").arg(path));
	      std::string d = tr ("%% Running %1 ...").arg (function_name).toStdString ();
	      std::cout << std::endl << d << std::endl << std::endl;
	      octave_link::instance ()->post_event (new octave_run_command_event (*this, function_name.toStdString (), _profiling, false));
      }
      else
	      activate_tools (true); // Command not run
    }
    else
    {
	    std::string d = tr ("%% Running %1 ...").arg (function_name).toStdString ();
	    std::cout << std::endl << d << std::endl << std::endl;
	    octave_link::instance ()->post_event (new octave_run_command_event (*this, function_name.toStdString (), _profiling, false));
    }
  }
}

void
main_window::run_and_profile ()
{
	_profiling = true;
	run_file ();
}

void
main_window::turn_off_profile ()
{
	activate_tools (false);	
	rl_line_buffer[0] = '\0';
	rl_point = rl_end = 0;
	rl_done = 1;
	octave_link::instance ()->post_event (new octave_run_command_event (*this, "profile off;", false, true));
	_profiling = false;
}

/*
void
main_window::toggle_bookmark()
{
  _file_editor->request_toggle_bookmark ();
}

void
main_window::next_bookmark()
{
  _file_editor->request_next_bookmark ();
}

void
main_window::previous_bookmark()
{
  _file_editor->request_previous_bookmark ();
}

void
main_window::remove_bookmark()
{
  _file_editor->request_remove_bookmark ();
}
*/

void
main_window::comment_selected_text()
{
  _file_editor->request_comment_selected_text ();
}

void
main_window::uncomment_selected_text()
{
  _file_editor->request_uncomment_selected_text ();
}

void
main_window::next_breakpoint()
{
  _file_editor->request_next_breakpoint ();
}

void main_window::previous_breakpoint()
{
  _file_editor->request_previous_breakpoint ();
}

void main_window::remove_breakpoint()
{
  _file_editor->request_remove_breakpoint ();
}

void main_window::toggle_breakpoint()
{
  _file_editor->request_toggle_breakpoint ();
}


void
main_window::handle_save_workspace_request ()
{

  QFileDialog fileDialog(this, tr("Save Workspace"));
  fileDialog.setDirectory (_current_directory);
  fileDialog.setNameFilter ("MAT files (*.mat)");
  fileDialog.setDefaultSuffix ("mat");
  fileDialog.setAcceptMode (QFileDialog::AcceptSave);
  fileDialog.setViewMode (QFileDialog::Detail);

  if (fileDialog.exec ())
    {
      QString selectedFile = fileDialog.selectedFiles ().at (0);
      if (!selectedFile.isEmpty ())
	octave_link::instance ()->post_event (new octave_save_event (*this, selectedFile.toStdString ()));
    }
}

void
main_window::handle_load_workspace_request ()
{
  QFileDialog fileDialog(this, tr("Load Workspace"));
  fileDialog.setDirectory (_current_directory);
  fileDialog.setNameFilter ("MAT files (*.mat);;All Files (*.*)");
  fileDialog.setAcceptMode (QFileDialog::AcceptOpen);
  fileDialog.setViewMode (QFileDialog::Detail);

  if (fileDialog.exec())
    {
      QString selectedFile = fileDialog.selectedFiles (). at (0);
      octave_link::instance ()->post_event (new octave_load_event (*this, selectedFile.toStdString ()));
    }
}

void
main_window::handle_clear_workspace_request ()
{
  //_terminal->sendText ("clear\n");
  //_terminal->setFocus ();
    octave_link::instance ()
          ->post_event (new octave_clear_event (*this));
}

void
main_window::handle_command_double_clicked (QString command)
{
  _terminal->sendText(command);
  _terminal->setFocus ();
}

/*
void
main_window::open_bug_tracker_page ()
{
  QDesktopServices::openUrl (QUrl ("http://savannah.gnu.org/bugs/?group=octave"));
}

void
main_window::open_agora_page ()
{
  QDesktopServices::openUrl (QUrl ("http://agora.panocha.org.mx/"));
}

void
main_window::open_octave_forge_page ()
{
  QDesktopServices::openUrl (QUrl ("http://octave.sourceforge.net/"));
}
*/
void
main_window::process_settings_dialog_request ()
{
  _settings_dialog->read_settings ();
  _settings_dialog->exec ();
  //resource_manager::instance ()->update_network_settings ();
  notice_settings();
}

void
main_window::notice_settings ()
{
  // Set terminal font:
  QSettings *settings = resource_manager::instance ()->get_settings ();
  QFont font = QFont();
  font.setFamily(settings->value("terminal/fontName").toString());
  font.setPointSize(settings->value("terminal/fontSize").toInt ());
  _terminal->setTerminalFont(font);
  _file_editor->notice_settings ();
  _workspace_view->notice_settings ();
  _history_dock_widget->notice_settings ();
  _files_dock_widget->notice_settings ();

  // If it's not the first time, don't launch the event (it has already been executed)

  bool warning_changed = false;

  if (_first_read_settings || _supress_warning != settings->value("terminal/supressWarnings").toBool())
  {
  warning_changed = true;

  if (settings->contains ("terminal/supressWarnings"))
    _supress_warning = settings->value("terminal/supressWarnings").toBool();
  else
    _supress_warning = true;

    if (_supress_warning)
      octave_link::instance ()->post_event (new octave_warning_event (*this, "off"));
    else
      octave_link::instance ()->post_event (new octave_warning_event (*this, "on"));
  }

  if (_first_read_settings || _matlab_compatible_warning != settings->value ("terminal/matlabCompatible").toBool() || warning_changed)
  {
    if (settings->contains ("terminal/matlabCompatible"))
      _matlab_compatible_warning = settings->value("terminal/matlabCompatible").toBool();
    else
      _matlab_compatible_warning = false;

    if(_matlab_compatible_warning)
      octave_link::instance ()->post_event (new octave_matlab_compatible_event (*this, "on"));
    else
      octave_link::instance ()->post_event (new octave_matlab_compatible_event (*this, "off"));
  }

  if (_first_read_settings || _broadcasting_option != settings->value ("terminal/broadcasting").toInt () || warning_changed)
  {
    if (settings->contains ("terminal/broadcasting"))
      _broadcasting_option = settings->value ("terminal/broadcasting").toInt ();
    else
      _broadcasting_option = 2; // default option

    std::string cmd;
    switch (_broadcasting_option)
    {
      case 0:
	cmd = "off";
	break;
      case 1:
	cmd = "on";
	break;
      default:
	cmd = "error";
    }

    octave_link::instance ()->post_event(new octave_broadcasting_event (*this, cmd));
  }

  if (_first_read_settings || (_current_graphics_toolkit != settings->value ("graphics").toString() && settings->contains ("graphics")))
  {
    _current_graphics_toolkit = settings->value ("graphics").toString ();
    octave_link::instance ()->post_event (new octave_graphics_toolkit_event (*this, _current_graphics_toolkit.toStdString()));
  }

  if (_first_read_settings)
    _first_read_settings = false;
}

bool
main_window::prepare_for_quit ()
{
  if (_file_editor->save_all_tabs ())
  {
    QApplication::setOverrideCursor(Qt::WaitCursor);
    write_settings ();
    _checker_thread->quitting();
    _checker_thread->wait();
    delete _checker_thread;

    return true;
  }
  rl_line_buffer[0] = '\0';
  rl_point = rl_end = 0;
  rl_done = 1;

  return false;
}

void
main_window::reset_windows ()
{
  // TODO: Implement.
}

void
main_window::update_current_working_directory (QString directory)
{
  if (_current_directory_combo_box->count () > 31)
    {
      _current_directory_combo_box->removeItem (0);
    }
  _current_directory_combo_box->addItem (directory);
  int index = _current_directory_combo_box->findText (directory);
  _current_directory_combo_box->setCurrentIndex (index);

  _current_directory = directory;
}

void
main_window::change_current_working_directory ()
{
  QString selectedDirectory =
      QFileDialog::getExistingDirectory(this, tr ("Set working directory"), _current_directory);

  if (!selectedDirectory.isEmpty ())
    {
      QFileInfo selectedPath(selectedDirectory);
      octave_link::instance ()
          ->post_event (new octave_change_directory_event (*this,
							   selectedPath.absoluteFilePath().toStdString()));
    }
}

void
main_window::change_current_working_directory (QString directory)
{
  QFileInfo selectedPath(directory);

  octave_link::instance ()
      ->post_event (new octave_change_directory_event (*this,
						       selectedPath.absoluteFilePath().toStdString()));
}

void
main_window::current_working_directory_up ()
{
  //_terminal->sendText ("cd ..\n");
  //_terminal->setFocus ();
    octave_link::instance ()->post_event (new octave_change_directory_event (*this, ".."));

}


void
main_window::handle_entered_debug_mode ()
{
  setWindowTitle ("Octave UPM " OCTAVE_UPM_REL " (dbg)");
  //_debug_menu->setEnabled (true);

  _debug_continue->setEnabled (true);
  _debug_step_into->setEnabled (true);
  _debug_step_over->setEnabled (true);
  _debug_step_out->setEnabled (true);
  _debug_quit->setEnabled (true);

  _next_breakpoint_action->setEnabled (false);
  _toggle_breakpoint_action->setEnabled (false);
  _previous_breakpoint_action->setEnabled (false);
  _remove_breakpoint_action->setEnabled (false);
  _run_action->setEnabled (false);
  _run_and_profile->setEnabled (false);

  _file_editor->handle_entered_debug_mode ();
  _debugging = true;
}

void
main_window::handle_quit_debug_mode ()
{
  _debugging = false;
  setWindowTitle ("Octave UPM " OCTAVE_UPM_REL);
  //_debug_menu->setEnabled (false);
  _debug_continue->setEnabled (false);
  _debug_step_into->setEnabled (false);
  _debug_step_over->setEnabled (false);
  _debug_step_out->setEnabled (false);
  _debug_quit->setEnabled (false);


  _next_breakpoint_action->setEnabled (true);
  _toggle_breakpoint_action->setEnabled (true);
  _previous_breakpoint_action->setEnabled (true);
  _remove_breakpoint_action->setEnabled (true);
  _run_action->setEnabled (true);
  _run_and_profile->setEnabled (true);

  _file_editor->handle_quit_debug_mode ();
  _workspace_view->get_model()->clear_scopes ();
  _workspace_view->get_model ()->set_current_scope (-1);
  _workspace_view->update_scopes ();
  octave_link::instance ()->generate_events ();
}

void
main_window::debug_continue ()
{
  octave_link::instance ()
      ->post_event (new octave_debug_continue_event (*this));
}

void
main_window::debug_step_into ()
{
  octave_link::instance ()
      ->post_event (new octave_debug_step_into_event (*this));
}

void
main_window::debug_step_over ()
{

  octave_link::instance ()
      ->post_event (new octave_debug_step_over_event (*this));
}

void
main_window::debug_step_out ()
{

  octave_link::instance ()
      ->post_event (new octave_debug_step_out_event (*this));
}

void
main_window::debug_quit ()
{

  octave_link::instance ()
      ->post_event (new octave_debug_quit_event (*this));
}

void
main_window::handle_debug_in_progress ()
{
    _file_editor->handle_debug_in_progress ();
}


void
main_window::show_about_octave ()
{
  QString message =
      "GNU Octave\n"
      "Copyright (C) 2009 John W. Eaton and others.\n"
      "This is free software; see the source code for copying conditions."
      "There is ABSOLUTELY NO WARRANTY; not even for MERCHANTABILITY or"
      "FITNESS FOR A PARTICULAR PURPOSE.  For details, type `warranty'.\n"
      "\n"

      "Additional information about Octave is available at http://www.octave.org.\n"
      "\n"
      "Please contribute if you find this software useful."
      "For more information, visit http://www.octave.org/help-wanted.html\n"
      "\n"
      "Report bugs to <bug@octave.org> (but first, please read"
      "http://www.octave.org/bugs.html to learn how to write a helpful report).\n"
      "\n"
      "For information about changes from previous versions, type `news'.\n";

  QMessageBox::about (this, tr ("About Octave"), message);
}

void
main_window::show_about_octave_UPM()
{
  QDialog *d = new QDialog (this);
  Ui_welcome_wizard ui;
  ui.setupUi (d);
  d->setModal (true);
  d->show ();
}



void
main_window::closeEvent (QCloseEvent * closeEvent)
{
  closeEvent->ignore ();
  if (prepare_for_quit())
    octave_link::instance ()->post_event (new octave_exit_event (*this));
}

void
main_window::read_settings ()
{

  QSettings *settings = resource_manager::instance ()->get_settings ();
  restoreGeometry (settings->value ("MainWindow/geometry").toByteArray ());
  restoreState (settings->value ("MainWindow/windowState").toByteArray ());
  _current_directory = QDir(settings->value ("lastDirectory").toString ()).absolutePath();
  change_current_working_directory (_current_directory);

  QString open_files = settings->value ("openFiles").toString ();
  QStringList open_files_list = open_files.split (";", QString::SkipEmptyParts);

  if (!_startup_filename_request.isEmpty() && open_files_list.indexOf(_startup_filename_request) == -1)
	  open_files_list << _startup_filename_request;
  
  for (int i = 0; i < open_files_list.size (); i++)
  {
    _file_editor->request_open_file (open_files_list.at (i));

  }

  if (_startup_filename_request.isEmpty())	  
	  _file_editor->find_filename_in_tabs (settings->value ("currentFile").toString ());
  else
	  _file_editor->find_filename_in_tabs (_startup_filename_request);

  if (open_files_list.size () > 0)
    update_clipboard_actions ();

  _show_editor_action->setChecked(_file_editor->isVisible());
  _show_workspace_action->setChecked(_workspace_view->isVisible());
  _show_command_window_action->setChecked(_terminal_dock_widget->isVisible());
  _show_file_browser_action->setChecked(_files_dock_widget->isVisible());
  _show_history_action->setChecked(_history_dock_widget->isVisible());
  _show_profiler_action->setChecked (_profiler_dock_widget->isVisible ());
  
  // Force more on as soon as the Octave session is ready
  //octave_link::instance()->post_event(new octave_more_event(*this,true));
  notice_settings ();
}

void
main_window::write_settings ()
{
  QSettings *settings = resource_manager::instance ()->get_settings ();
  settings->setValue ("MainWindow/geometry", saveGeometry ());
  settings->setValue ("MainWindow/windowState", saveState ());
  settings->setValue ("lastDirectory", _current_directory);
  QStringList open_files_list = _file_editor->get_all_open_files ();
  QString open_files = "";
  for (int i = 0; i < open_files_list.size (); i++)
  {
    open_files.append(open_files_list.at(i));
    open_files.append(";");
  }
  settings->setValue ("openFiles", open_files);
  settings->setValue ("currentFile",_file_editor->active_filename ());
  settings->sync ();
}

void
main_window::construct ()
{
  QPixmap pixmap(":/images/media/loading.png");
  _splash_screen = new QSplashScreen(pixmap);
  _splash_screen->show ();
  _splash_screen->raise ();

  QStyle *style = QApplication::style ();
  setWindowIcon (resource_manager::instance ()->get_icon (resource_manager::octave));

  // Setup dockable widgets and the status bar.
  _workspace_view           = new workspace_view (this);
  _workspace_view->setStatusTip (tr ("View the variables in the active workspace."));
  _history_dock_widget      = new history_dock_widget (this);
  _history_dock_widget->setStatusTip (tr ("Browse and search the command history."));
  _files_dock_widget        = new files_dock_widget (this);
  _files_dock_widget->setStatusTip (tr ("Browse your files."));
  _profiler_dock_widget     = new profile_display (this);
  _status_bar               = new QStatusBar (this);

  _help_browser = new doc_viewer (this);
  
  
  _current_directory_combo_box = new QComboBox (this);
  _current_directory_combo_box->setFixedWidth (300);
  _current_directory_combo_box->setEditable (true);
  _current_directory_combo_box->setInsertPolicy (QComboBox::InsertAtTop);
  _current_directory_combo_box->setMaxVisibleItems (14);

  _current_directory_tool_button = new QToolButton (this);
  _current_directory_tool_button->setIcon (style->standardIcon (QStyle::SP_DirOpenIcon));

  _current_directory_up_tool_button = new QToolButton (this);
  _current_directory_up_tool_button->setIcon (style->standardIcon (QStyle::SP_FileDialogToParent));

  // Octave Terminal subwindow.
  _terminal = new QTerminal (this);
  _terminal->setObjectName ("OctaveTerminal");
  _terminal->setCursorType(QTerminalInterface::IBeamCursor, true);
  _terminal->setFocusPolicy (Qt::StrongFocus);
  _terminal_dock_widget = new terminal_dock_widget (_terminal, this);

  QWidget *dummyWidget = new QWidget ();
  dummyWidget->setObjectName ("CentralDummyWidget");
  dummyWidget->resize (10, 10);
  dummyWidget->setSizePolicy (QSizePolicy::Minimum, QSizePolicy::Minimum);
  dummyWidget->hide ();
  setCentralWidget (dummyWidget);

  _file_editor = new file_editor (this);

  QMenu *file_menu = menuBar ()->addMenu (tr ("&File"));
  QAction *new_file_action
    = file_menu->addAction (QIcon::fromTheme ("document-new",
      style->standardIcon (QStyle::SP_FileIcon)), tr ("New File"));
   //QAction *new_file_action = file_menu->addAction(QIcon(":/icons/media/new-document-icon.png"), tr("New File"));

  QAction *open_file_action
      = file_menu->addAction (QIcon::fromTheme ("document-open",
        style->standardIcon (QStyle::SP_DirIcon)), tr ("Open File"));

  _save_action = file_menu->addAction (QIcon::fromTheme("document-save",
	style->standardIcon (QStyle::SP_DriveHDIcon)),
        tr("&Save File"));

  _save_as_action = file_menu->addAction (
        QIcon::fromTheme("document-save-as",style->standardIcon (QStyle::SP_DriveFDIcon)),
        tr("Save File &As"));

  _close_action = file_menu->addAction(
        QIcon::fromTheme("document-close", style->standardIcon (QStyle::SP_DialogCloseButton)),
	tr("Close file"));


  file_menu->addSeparator ();
  QAction * load_workspace_action       = file_menu->addAction (tr ("Load workspace"));
  QAction * save_workspace_action       = file_menu->addAction (tr ("Save workspace"));
  QAction * clear_workspace_action      = file_menu->addAction (tr ("Clear workspace"));


  file_menu->addSeparator ();
  QAction *exit_action = file_menu->addAction (tr ("Exit"));

  QMenu *edit_menu = menuBar ()->addMenu (tr ("&Edit"));

  _undo_action = edit_menu->addAction (
        QIcon::fromTheme("edit-undo",style->standardIcon (QStyle::SP_ArrowLeft)),
        tr("&Undo"));

  _redo_action = edit_menu->addAction (
        QIcon::fromTheme("edit-redo",style->standardIcon (QStyle::SP_ArrowRight)),
        tr("&Redo"));

  edit_menu->addSeparator ();

  _copy_action = new QAction (resource_manager::instance()->get_icon(resource_manager::copy),tr ("Copy"), edit_menu);
  edit_menu->addAction (_copy_action);
  //copy_action->setShortcut (QKeySequence::Copy);


  _cut_action = new QAction (resource_manager::instance()->get_icon(resource_manager::cut),tr ("Cut"), edit_menu);
  edit_menu->addAction (_cut_action);
  //copy_action->setShortcut (QKeySequence::Copy);

  _paste_action = new QAction (resource_manager::instance()->get_icon(resource_manager::paste),tr ("Paste"), edit_menu);
  edit_menu->addAction (_paste_action);
  //paste_action->setShortcut (QKeySequence::Paste);

  edit_menu->addSeparator ();
  _find_action = new QAction (QIcon::fromTheme("edit-find"), tr ("Find"), edit_menu);
  edit_menu->addAction (_find_action);

  _comment_selection_action   = new QAction (tr ("&Comment Selected Text"), edit_menu);
  _uncomment_selection_action = new QAction (tr ("&Uncomment Selected Text"), edit_menu);
  edit_menu->addSeparator ();
  edit_menu->addAction (_comment_selection_action);
  edit_menu->addAction (_uncomment_selection_action);

  edit_menu->addSeparator();
  QAction *settings_action = edit_menu->addAction (QIcon(":/actions/icons/configure.png"), tr ("Settings"));


  _debug_menu = menuBar ()->addMenu (tr ("E&xecute"));

  _run_action = new QAction (
        QIcon::fromTheme ("media-play", style->standardIcon (QStyle::SP_MediaPlay)),
        tr("&Run/Debug File"), _debug_menu);
  _debug_menu->addAction (_run_action);
  _run_and_profile = new QAction (
        QIcon::fromTheme ("media-play", style->standardIcon (QStyle::SP_MediaPlay)),
        tr("Run/Debug and &profile file"), _debug_menu);
  _debug_menu->addAction (_run_action);
  _debug_menu->addAction (_run_and_profile);

  _stop_action = new QAction (QIcon::fromTheme("browser-stop", style->standardIcon(QStyle::SP_BrowserStop)),
			      tr("&Break infinite loop"), _debug_menu);
  _stop_action->setWhatsThis(tr("If you are in an infinite loop, use this button to stop execution"));
  _debug_menu->addAction (_stop_action);
  _stop_action->setEnabled (false);
  _debug_menu->addSeparator ();

  _next_breakpoint_action       = new QAction (tr ("&Next breakpoint"),_debug_menu);
  _previous_breakpoint_action   = new QAction (tr ("Pre&vious breakpoint"),_debug_menu);
  _toggle_breakpoint_action     = new QAction (tr ("Toggle &breakpoint"),_debug_menu);
  _remove_breakpoint_action     = new QAction (tr ("&Remove All breakpoints"),_debug_menu);

  _debug_menu->addAction (_toggle_breakpoint_action);
  _debug_menu->addAction (_next_breakpoint_action);
  _debug_menu->addAction (_previous_breakpoint_action);
  _debug_menu->addAction (_remove_breakpoint_action);

  _debug_menu->addSeparator ();

  _debug_step_over = _debug_menu->addAction (tr ("Step"));
  _debug_step_over->setEnabled (false);
  _debug_step_over->setShortcut (Qt::Key_F10);

  _debug_step_into = _debug_menu->addAction (tr ("Step in"));
  _debug_step_into->setEnabled (false);
  _debug_step_into->setShortcut (Qt::Key_F11);

  _debug_step_out = _debug_menu->addAction (tr ("Step out"));
  _debug_step_out->setEnabled (false);
  _debug_step_out->setShortcut (Qt::ShiftModifier + Qt::Key_F11);

  _debug_continue = _debug_menu->addAction (tr ("Continue"));
  _debug_continue->setEnabled (false);
  _debug_continue->setShortcut (Qt::Key_F5);

  _debug_menu->addSeparator ();

  _debug_quit = _debug_menu->addAction (tr ("Exit Debug Mode"));
  _debug_quit->setEnabled (false);
  _debug_quit->setShortcut (Qt::ShiftModifier + Qt::Key_F5);


  _plot_menu = menuBar()->addMenu(tr ("&Graphics"));

  QAction *refresh_plot = new QAction (tr ("Redraw last plot"), _plot_menu);
  QAction *clear_plot = new QAction (tr ("Erase all plots"), _plot_menu);

  _plot_menu->addSeparator ();
  _plot_menu->addAction (refresh_plot);
  _plot_menu->addAction (clear_plot);

  QAction *axis_properties = new QAction (tr ("Edit 2-D plot"), _plot_menu);
  _plot_menu->addSeparator ();
  _plot_menu->addAction (axis_properties);

  QAction *export_plot = new QAction (tr ("Export last plot as image"), _plot_menu);
  _plot_menu->addSeparator ();
  _plot_menu->addAction (export_plot);
  
  // Window menu
  QMenu *   view_menu = menuBar ()->addMenu (tr ("&Window"));
  _show_command_window_action  = view_menu->addAction (tr ("Command Window"));
            _show_command_window_action->setCheckable (true);
  _show_history_action         = view_menu->addAction (tr ("Command History"));
            _show_history_action->setCheckable (true);
  _show_file_browser_action    = view_menu->addAction (tr ("Current Directory"));
            _show_file_browser_action->setCheckable (true);
  _show_workspace_action       = view_menu->addAction (tr ("Workspace"));
            _show_workspace_action->setCheckable (true);
  _show_profiler_action        = view_menu->addAction (tr ("Profiler"));
  _show_profiler_action->setCheckable (true);
  view_menu->addSeparator ();
  _show_editor_action          = view_menu->addAction (tr ("Editor"));
            _show_editor_action->setCheckable (true);
  view_menu->addSeparator ();


  _default_layout_action = view_menu->addAction (tr ("Reset windows"));

  view_menu->addSeparator ();

  _jump_to_terminal_action = view_menu->addAction (tr ("Go to Command Window"));
  _jump_to_terminal_action->setShortcut (Qt::CTRL + Qt::Key_0);
  _jump_to_history_action = view_menu->addAction (tr ("Go to Command History"));
  _jump_to_history_action->setShortcut (Qt::CTRL + Qt::Key_1);
  _jump_to_file_action = view_menu->addAction (tr ("Go to File Browser"));
  _jump_to_file_action->setShortcut (Qt::CTRL + Qt::Key_2);
  _jump_to_ws_action = view_menu->addAction (tr ("Go to Workspace"));
  _jump_to_ws_action->setShortcut (Qt::CTRL + Qt::Key_3);
  _jump_to_profiler = view_menu->addAction (tr ("Go to Profiler"));
  _jump_to_profiler->setShortcut (Qt::CTRL + Qt::Key_4);
   view_menu->addSeparator ();
  _jump_to_editor_action = view_menu->addAction(tr("Go to Editor"));
  _jump_to_editor_action->setShortcut (Qt::CTRL+ Qt::SHIFT + Qt::Key_0);


  // Help menu
  QMenu *   help_menu = menuBar ()->addMenu (tr ("&Help"));
  QAction * show_help = help_menu->addAction("Help browser");
  help_menu->addSeparator ();
  QAction * about_octave_action         = help_menu->addAction (tr ("About Octave"));
  QAction *about_octave_upm_action = help_menu->addAction (tr("About Octave UPM"));


  // Toolbars
  _main_tool_bar = addToolBar (tr ("Main Toolbar"));
  _main_tool_bar->addAction (new_file_action);
  _main_tool_bar->addAction (open_file_action);
  _main_tool_bar->addAction (_save_action);
  _main_tool_bar->addSeparator ();
  //main_tool_bar->addAction (cut_action);
  _main_tool_bar->addAction (_undo_action);
  _main_tool_bar->addAction (_redo_action);
  _main_tool_bar->addAction (_copy_action);
  _main_tool_bar->addAction (_cut_action);
  _main_tool_bar->addAction (_paste_action);
  _main_tool_bar->addSeparator ();
  _main_tool_bar->addAction (_run_action);
  _main_tool_bar->addAction (_stop_action);
  _main_tool_bar->addSeparator ();
  _main_tool_bar->addWidget (new QLabel (tr ("Current Directory:")));
  _main_tool_bar->addWidget (_current_directory_combo_box);
  _main_tool_bar->addWidget (_current_directory_tool_button);
  _main_tool_bar->addWidget (_current_directory_up_tool_button);
_main_tool_bar->setObjectName("Toolbar");

  new_file_action->setShortcut                       (QKeySequence::New);
  //new_action->setShortcutContext                (Qt::WidgetShortcut);
  open_file_action->setShortcut                      (QKeySequence::Open);
  //open_action->setShortcutContext               (Qt::WidgetShortcut);
  _save_action->setShortcut                      (QKeySequence::Save);
  //save_action->setShortcutContext               (Qt::WidgetShortcut);
  _save_as_action->setShortcut                   (QKeySequence::SaveAs);
  _close_action->setShortcut 			 (QKeySequence::Close);
  _undo_action->setShortcut                      (QKeySequence::Undo);
  //undo_action->setShortcutContext               (Qt::WidgetShortcut);
  _redo_action->setShortcut                      (QKeySequence::Redo);
  //redo_action->setShortcutContext               (Qt::WidgetShortcut);
  _copy_action->setShortcut                     (QKeySequence::Copy);
  _copy_action->setShortcutContext              (Qt::WidgetShortcut);
  _cut_action->setShortcut                      (QKeySequence::Cut);
  _cut_action->setShortcutContext               (Qt::WidgetShortcut);
  _paste_action->setShortcut                     (QKeySequence::Paste);
  _paste_action->setShortcutContext              (Qt::WidgetShortcut);
  _find_action->setShortcut 			 (QKeySequence::Find);

  _comment_selection_action->setShortcut         (Qt::CTRL + Qt::Key_R);
  //comment_selection_action->setShortcutContext  (Qt::WidgetShortcut);
  _uncomment_selection_action->setShortcut       (Qt::SHIFT + Qt::CTRL + Qt::Key_R);

  _run_action->setShortcut                       (Qt::Key_F6);

  _copy_action->setEnabled (false);
  _cut_action->setEnabled (false);
  _paste_action->setEnabled (false);
  _find_action->setEnabled (false);
  _comment_selection_action->setEnabled (false);
  _uncomment_selection_action->setEnabled (false);

  _undo_action->setEnabled (false);
  _redo_action->setEnabled (false);
  _save_action->setEnabled (false);
  _close_action->setEnabled (false);
  _save_as_action->setEnabled (false);
  _run_action->setEnabled (false);
  _run_and_profile->setEnabled (false);
  _jump_to_terminal_action->setEnabled (false);
  _jump_to_history_action->setEnabled (false);
  _jump_to_ws_action->setEnabled (false);
  _jump_to_file_action->setEnabled (false);
  _jump_to_profiler->setEnabled (false);
  _jump_to_editor_action->setEnabled (false);
  _toggle_breakpoint_action->setEnabled (false);
  _previous_breakpoint_action->setEnabled (false);
  _remove_breakpoint_action->setEnabled (false);
  _next_breakpoint_action->setEnabled (false);

  connect (settings_action,             SIGNAL (triggered ()),
           this,                        SLOT   (process_settings_dialog_request ()));
  connect (exit_action,                 SIGNAL (triggered ()),
           this,                        SLOT   (close ()));
  connect (new_file_action,             SIGNAL (triggered ()),
           this,                        SLOT   (new_file ()));
  connect (open_file_action,            SIGNAL (triggered ()),
           this,                        SLOT   (open_file ()));
  connect (_save_action,			SIGNAL   (triggered ()),
	   this,			SLOT (save_file ()));
  connect (_save_as_action,		SIGNAL   (triggered ()),
	   this,			SLOT (save_file_as ()));
  connect (_close_action,		SIGNAL (triggered()),
	   this,			SLOT (close_file()));
  connect (_undo_action,			SIGNAL (triggered ()),
	   this,			SLOT (undo ()));
  connect (_redo_action,			SIGNAL (triggered ()),
	   this,			SLOT (redo ()));
  connect (_copy_action,		SIGNAL (triggered ()),
	   this,			SLOT (copy ()));
  connect (_cut_action,			SIGNAL (triggered ()),
	   this,			SLOT (cut ()));
  connect (_paste_action,		SIGNAL (triggered ()),
	   this,			SLOT (paste ()));
  connect (_find_action,		SIGNAL (triggered()),
	   this,			SLOT (find ()));

  connect (_run_action,                 SIGNAL (triggered ()), this, SLOT (run_file ()));
  connect (_run_and_profile,            SIGNAL (triggered ()), this, SLOT (run_and_profile ()));
  connect (_stop_action,		SIGNAL (triggered()), this, SLOT (stop_execution()));

  connect (_comment_selection_action,   SIGNAL (triggered ()), this, SLOT (comment_selected_text ()));
  connect (_uncomment_selection_action, SIGNAL (triggered ()), this, SLOT (uncomment_selected_text ()));

  connect (show_help,                   SIGNAL (triggered ()),
	   this,                        SLOT   (show_help_window ()));	   
  connect (about_octave_action,         SIGNAL (triggered ()),
           this,                        SLOT   (show_about_octave ()));
  connect (about_octave_upm_action,         SIGNAL (triggered ()),
           this,                        SLOT   (show_about_octave_UPM()));

  connect (_show_command_window_action,  SIGNAL (toggled (bool)),
           _terminal_dock_widget,       SLOT   (setVisible (bool)));
  connect (_terminal_dock_widget,       SIGNAL (active_changed (bool)),
           _show_command_window_action,  SLOT   (setChecked (bool)));
  connect (_show_command_window_action,  SIGNAL (toggled (bool)),
	   _jump_to_terminal_action,    SLOT   (setEnabled (bool)));

  connect (_show_workspace_action,       SIGNAL (toggled (bool)),
           _workspace_view,             SLOT   (setVisible (bool)));
  connect (_show_workspace_action,	SIGNAL (toggled (bool)),
	   _jump_to_ws_action,		SLOT   (setEnabled (bool)));
  connect (_workspace_view,             SIGNAL (active_changed (bool)),
           _show_workspace_action,       SLOT   (setChecked (bool)));

  connect (_show_history_action,         SIGNAL (toggled (bool)),
           _history_dock_widget,        SLOT   (setVisible (bool)));
  connect (_history_dock_widget,        SIGNAL (active_changed (bool)),
           _show_history_action,         SLOT   (setChecked (bool)));
  connect (_show_history_action,		SIGNAL (toggled (bool)),
	   _jump_to_history_action,	SLOT   (setEnabled (bool)));

  connect (_show_file_browser_action,    SIGNAL (toggled (bool)),
           _files_dock_widget,          SLOT   (setVisible (bool)));
  connect (_files_dock_widget,          SIGNAL (active_changed (bool)),
           _show_file_browser_action,    SLOT   (setChecked (bool)));
  connect (_show_file_browser_action,    SIGNAL (toggled (bool)),
	   _jump_to_file_action,	SLOT   (setEnabled (bool)));

  connect (_show_profiler_action,       SIGNAL  (toggled(bool)),
	   _profiler_dock_widget,       SLOT    (setVisible (bool)));
  connect (_profiler_dock_widget,       SIGNAL  (active_changed (bool)),
	   _show_profiler_action,       SLOT    (setChecked (bool)));
  connect (_show_profiler_action,       SIGNAL  (toggled (bool)),
	   _jump_to_profiler,           SLOT    (setEnabled (bool)));

  connect (_profiler_dock_widget,       SIGNAL  (open_file (QString)),
	   this,                        SLOT    (open_file (QString)));
  
  connect (_show_editor_action,         SIGNAL (triggered(bool)),
	  this,				SLOT (handle_hide_editor ()));
  connect (_file_editor,		SIGNAL (active_changed(bool)),
	  _show_editor_action,		SLOT (setChecked(bool)));
  connect (_file_editor,                SIGNAL (active_changed (bool)),
          _show_editor_action,         SLOT   (setChecked (bool)));
  
  connect (_default_layout_action,	SIGNAL(triggered()),
	   this,		        SLOT(set_layout_default()));
  /*connect (_only_editor_action,		SIGNAL(triggered()),
	   this,			SLOT(set_layout_editor()));
  connect (_only_terminal_action,	SIGNAL(triggered()),
	   this,			SLOT(set_layout_terminal()));
  */

  /*
  connect (reset_windows_action,        SIGNAL (triggered ()),
           this,                        SLOT   (reset_windows ()));
  */

  connect (_jump_to_ws_action,		SIGNAL (triggered ()),
	   this,			SLOT   (focus_workspace ()));
  connect (_jump_to_file_action,	SIGNAL (triggered ()),
	   this,			SLOT   (focus_filebrowser ()));
  connect (_jump_to_history_action,	SIGNAL (triggered ()),
	   this,			SLOT   (focus_history ()));
  connect (_jump_to_terminal_action,    SIGNAL (triggered ()),
	   this,			SLOT   (focus_terminal ()));
  connect (_jump_to_editor_action,	SIGNAL (triggered ()),
	   this,			SLOT   (focus_editor ()));
  connect (_files_dock_widget,          SIGNAL (open_file (QString)),
           _file_editor,                SLOT   (request_open_file (QString)));
  connect (_history_dock_widget,        SIGNAL (command_double_clicked (QString)),
           this,                        SLOT   (handle_command_double_clicked (QString)));
  connect (save_workspace_action,       SIGNAL (triggered ()),
           this,                        SLOT   (handle_save_workspace_request ()));
  connect (load_workspace_action,       SIGNAL (triggered ()),
           this,                        SLOT   (handle_load_workspace_request ()));
  connect (clear_workspace_action,      SIGNAL (triggered ()),
           this,                        SLOT   (handle_clear_workspace_request ()));
  connect (_current_directory_tool_button, SIGNAL (clicked ()),
           this,                        SLOT   (change_current_working_directory ()));
  connect (_current_directory_up_tool_button, SIGNAL (clicked ()),
           this,                        SLOT   (current_working_directory_up()));
  connect (_files_dock_widget,          SIGNAL (change_working_directory(QString)),
	   this,                        SLOT (change_current_working_directory(QString)));
  connect (_current_directory_combo_box, SIGNAL (activated (QString)),
           this,                        SLOT (change_current_working_directory (QString)));

  connect (_debug_continue,              SIGNAL (triggered ()),
           this,                        SLOT (debug_continue ()));
  connect (_debug_step_into,             SIGNAL (triggered ()),
           this,                        SLOT (debug_step_into ()));
  connect (_debug_step_over,             SIGNAL (triggered ()),
           this,                        SLOT (debug_step_over ()));
  connect (_debug_step_out,              SIGNAL (triggered ()),
           this,                        SLOT (debug_step_out ()));
  connect (_debug_quit,                  SIGNAL (triggered ()),
           this,                        SLOT (debug_quit ()));

  connect (_toggle_breakpoint_action,    SIGNAL (triggered ()), this, SLOT (toggle_breakpoint ()));
  connect (_next_breakpoint_action,      SIGNAL (triggered ()), this, SLOT (next_breakpoint ()));
  connect (_previous_breakpoint_action,      SIGNAL (triggered ()), this, SLOT (previous_breakpoint ()));
  connect (_remove_breakpoint_action,    SIGNAL (triggered ()), this, SLOT (remove_breakpoint ()));

  connect (refresh_plot,		SIGNAL (triggered()), this, SLOT (handle_refresh_plot ()));
  connect (clear_plot,		SIGNAL (triggered()), this, SLOT (handle_clear_plots()));

  connect (axis_properties,	SIGNAL (triggered()), this, SLOT (handle_edit_plot()));
  connect (export_plot,		SIGNAL (triggered()), this, SLOT (handle_export_image()));

  connect (_history_dock_widget,	SIGNAL (load_finished ()),
	   this,			SLOT (finish_splash_screen ()));

  setWindowTitle ("Octave UPM " OCTAVE_UPM_REL);
  setDockOptions(QMainWindow::AnimatedDocks | QMainWindow::AllowNestedDocks | QMainWindow::AllowTabbedDocks);
  addDockWidget (Qt::RightDockWidgetArea, _workspace_view);
  addDockWidget (Qt::RightDockWidgetArea, _history_dock_widget);
  addDockWidget (Qt::LeftDockWidgetArea, _files_dock_widget);
  addDockWidget (Qt::LeftDockWidgetArea, _file_editor);
  addDockWidget (Qt::RightDockWidgetArea, _terminal_dock_widget);
  addDockWidget (Qt::LeftDockWidgetArea, _profiler_dock_widget);
  
  setStatusBar (_status_bar);
  _splash_screen->raise ();


  _check_toolkits_timer.setSingleShot (true);
  _check_toolkits_timer.setInterval (1000);
  _check_toolkits_timer.start ();

  _stop_action_available_timer.setInterval (3000);
  _already_stopped = false;

  _settings_dialog = new settings_dialog (this);


  connect (_file_editor,
	   SIGNAL (editor_changed ()),
	   this,
	   SLOT (update_clipboard_actions ()));

  _octave_qt_event_listener = new octave_qt_event_listener ();
  octave_link::instance ()->register_event_listener (_octave_qt_event_listener);

  connect (_octave_qt_event_listener,
           SIGNAL (current_directory_has_changed_signal (QString)),
           this,
           SLOT (update_current_working_directory (QString)));

  connect (_octave_qt_event_listener,
           SIGNAL (current_directory_has_changed_signal (QString)),
           _files_dock_widget,
           SLOT (on_working_dir_changed(QString)));


  connect (_octave_qt_event_listener,
           SIGNAL (current_directory_has_changed_signal (QString)),
           _file_editor,
	   SLOT (set_current_directory (QString)));


  connect (_octave_qt_event_listener,
           SIGNAL (entered_debug_mode_signal ()),
           this,
           SLOT(handle_entered_debug_mode ()));

  connect (_octave_qt_event_listener,
           SIGNAL (quit_debug_mode_signal ()),
           this,
           SLOT (handle_quit_debug_mode ()));

  connect (_octave_qt_event_listener,
           SIGNAL (debugging_in_progress ()),
           this,
           SLOT (handle_debug_in_progress ()));

  connect (&_check_toolkits_timer,
	   SIGNAL (timeout()),
	   this,
	   SLOT (check_available_toolkits()));

  connect (&_stop_action_available_timer,
	   SIGNAL (timeout()),
	   this,
	   SLOT (check_stop_action()));

  connect (this,
	   SIGNAL (restart_stop_action_timer()),
	   &_stop_action_available_timer,
	   SLOT (start()));

  connect (this,
	   SIGNAL (restart_stop_action_timer()),
	   this,
	   SLOT (unset_stop_action()));

  connect (this,
	   SIGNAL (update_profile_info (QString)),
	   _profiler_dock_widget,
	   SLOT (update_profiler_info (QString)));

  connect (this,
	   SIGNAL (profile_keeps_on ()),
	   this,
	   SLOT (turn_off_profile ()));
  
  /*
  _update_performance_information_timer.setInterval (500);
  _update_performance_information_timer.setSingleShot (false);
  connect (&_update_performance_information_timer, SIGNAL (timeout ()),
           this, SLOT (update_performance_information ()));
  _update_performance_information_timer.start ();
  */

  _checker_thread = new octave_model_checker_thread ();
  _checker_thread->set_model (_workspace_view->get_model());
  _checker_thread->set_view (_workspace_view);

  _graphics_editor = new GraphicsEditor (this);

  connect (_graphics_editor, SIGNAL(finished(int)), this, SLOT(apply_graphics_editor_settings(int)));



}
void
main_window::handle_hide_editor()
{
  bool show = _show_editor_action->isChecked ();
  if (!show && _file_editor->isVisible ())
  {
    if (_file_editor->save_all_tabs ())
    {
      _file_editor->setVisible (false);
      _jump_to_editor_action->setEnabled (false);
    }
    else
    {
      _show_editor_action->setChecked (true);
      _jump_to_editor_action->setEnabled (true);
    }
  }
  else if (show)
  {
    _jump_to_editor_action->setEnabled (true);
    _file_editor->setVisible (true);
  }
}

void
main_window::finish_splash_screen()
{
  // Octave is loaded, close splash screen
  _splash_screen->close ();
  delete _splash_screen;
  _checker_thread->start();
  _stop_action_available_timer.start();

  // Get config info for help file
  octave_link::instance ()->post_event (new octave_infofile_event (*this, "infofile"));
}

void
main_window::focus_editor()
{
  _file_editor->activateWindow ();
  _file_editor->setFocus ();
}

void
main_window::focus_filebrowser ()
{
  _files_dock_widget->activateWindow ();
  _files_dock_widget->setFocus ();
}

void
main_window::focus_history ()
{
  _history_dock_widget->activateWindow ();
  _history_dock_widget->setFocus ();
}

void
main_window::focus_terminal ()
{
  _terminal_dock_widget->activateWindow ();
  _terminal_dock_widget->setFocus (Qt::MouseFocusReason);
}

void
main_window::focus_workspace ()
{
  _workspace_view->activateWindow ();
  _workspace_view->setFocus ();
}

void
main_window::check_available_toolkits()
{
  // Keep trying until the toolkits appear in Octave
  if (_graphics_toolkits.length() == 0)
  {
    octave_link::instance ()->post_event (new octave_available_toolkits_event (*this));
    _check_toolkits_timer.start ();
  }
  else
    _settings_dialog->populate_combobox (_graphics_toolkits, _current_graphics_toolkit);
}

void
main_window::stop_execution()
{
  std::stringstream redirectStream;
  std::streambuf*     oldbuf  = std::cout.rdbuf( redirectStream.rdbuf() );

      // Capture stderr
  std::stringstream errStreamIgn;
  std::streambuf*     oldErrBuf = std::cerr.rdbuf (errStreamIgn.rdbuf ());
 	  
  // TODO: Don't allow if profiling
  if (!_profiling)
	  feval("dbquit", octave_value_list (), 0);

  std::cout.rdbuf(oldbuf);
  std::cerr.rdbuf(oldErrBuf);

  // Finish readline event
  rl_line_buffer[0] = '\0';
  rl_point = rl_end = 0;
  rl_done = 1;
}

void main_window::activate_tools (bool active)
{

	if (!active && _profiling)
		_stop_action->setEnabled (false);
	else
		_stop_action->setEnabled (!active);
	
	_run_action->setEnabled (active);
	_run_and_profile->setEnabled (active);
	_plot_menu->setEnabled (active);

	_next_breakpoint_action->setEnabled (active);
	_previous_breakpoint_action->setEnabled (active);
	_toggle_breakpoint_action->setEnabled (active);
	_remove_breakpoint_action->setEnabled (active);
}

void main_window::check_stop_action()
{
  if (_already_stopped)
  {
    // TODO: Show tooltip
    _already_stopped = false;
    activate_tools (false);

    _status_bar->showMessage(tr("If you are blocked, use the red button to stop execution"));
    //QWhatsThis::showText(QCursor::pos(), tr("If you are blocked, use the red button to stop execution"), _main_tool_bar);

  }
  else
    _already_stopped = true;

  octave_link::instance()->post_event (new octave_dummy_event(*this));
}

void main_window::unset_stop_action()
{
	activate_tools ();
	_status_bar->clearMessage();
}

void main_window::handle_clear_plots()
{
  _status_bar->showMessage (tr ("Erasing plots..."));
  std::string f = "clf";
  octave_value_list vl;
  vl.append("reset");

  octave_link::instance ()->post_event (new octave_plot_event (*this, f, vl));
}

void main_window::handle_refresh_plot()
{
  _status_bar->showMessage (tr ("Refreshing plot window..."));
  octave_link::instance ()->post_event (new octave_plot_event (*this, "refresh"));
  /*
  octave_value_list gcf = feval("gcf",octave_value_list (), 1);
  octave_value_list args;
  args.append(gcf(0));
  args.append("visible");
  args.append("on");
  octave_link::instance ()->post_event (new octave_plot_event (*this, "set", args));
  */
}

void main_window::handle_export_image()
{
  if (_stop_action->isEnabled())
    return;

  block_octave_for_plot_edit ();

  _status_bar->showMessage (tr ("Generating preview..."));
  QTemporaryFile f;
  f.setAutoRemove (true);
  f.open();
  std::string filename = f.fileName().toStdString ();
  filename.append(".png");

  octave_value_list gcf = feval("gcf", octave_value_list (), 1);
  octave_value_list saveargs;
  saveargs.append(gcf(0));
  saveargs.append(filename);
  saveargs.append("png");
  feval("saveas", saveargs, 0);

  _status_bar->showMessage("");
  handle_preview_image(QString::fromStdString(filename));

}

void main_window::handle_preview_image(QString preview_filename)
{
  preview_dialog *d = new preview_dialog (this);
  d->setPreviewFilename (preview_filename);
  d->setModal (true);

  bool fileOk = false;

  while (!fileOk)
  {
    int result = d->exec ();

    if(result == QDialog::Accepted)
    {

      QString fn = d->getFilename ();
      if (fn.isEmpty ())
	continue;

      // Get extension
      int ext = d->getExtension ();
      QString exts;
      switch (ext)
      {
	case 0:
	  exts = "png";
	  break;
	case 1:
	  exts = "jpg";
	  break;
	case 2:
	  exts = "pdf";
	  break;
	case 3:
	  exts = "eps";
	  break;
	case 4:
	  exts = "ps";
	  break;
	case 5:
	  exts = "emf";
	  break;
      }

      // check if file exists

      if (!fn.endsWith(exts))
	fn = fn + "." + exts;

      if (QFile(fn).exists())
      {
	// Show warning message
	QMessageBox msgBox;

	msgBox.setText(tr ("The file %1 already exists. Do you want to overwrite the file?").arg(fn));
	msgBox.setStandardButtons (QMessageBox::Yes | QMessageBox::No);
	msgBox.setDefaultButton (QMessageBox::No);
	int ret = msgBox.exec ();
	if (QMessageBox::No == ret)
	{
	  fileOk = false;
	  continue;
	}
      }

      octave_value_list saveargs;
      octave_value_list gcf = feval("gcf", octave_value_list (), 1);
      saveargs.append (gcf(0));
      saveargs.append (fn.toStdString());
      saveargs.append (exts.toStdString());
      unblock_octave ();

      octave_link::instance ()->post_event (new octave_plot_event (*this, "saveas", saveargs));
      _status_bar->showMessage (tr ("Saving image file..."));
      fileOk = true;

    }
    else
      fileOk = true;
  }

  unblock_octave ();
  delete d;
}

void main_window::handle_edit_plot()
{
    if (_stop_action->isEnabled())
      return;


  // Avoid more than one instantiation
      // Check if 2D plot
    block_octave_for_plot_edit ();
    if (!_graphics_editor->is_2d_plot ())
    {
      QMessageBox msgbox (this);
      msgbox.setText (tr("The editor only works with 2D plots"));
      msgbox.addButton(QMessageBox::Ok);
      msgbox.setModal (true);
      msgbox.exec ();

      unblock_octave ();

      return;
    }


  _graphics_editor->set_plot_visible (false);
  _graphics_editor->recreate ();
  _graphics_editor->exec ();
}

void main_window::apply_graphics_editor_settings(int result)
{
  if (result == QDialog::Accepted)
    _graphics_editor->apply_all_settings ();

  _graphics_editor->set_plot_visible (true);
  unblock_octave ();
  handle_refresh_plot ();
}

void main_window::block_octave_for_plot_edit()
{
  octave_link::instance()->ignore_events ();
  _run_action->setEnabled (false);
  _run_and_profile->setEnabled (false);
  //_checker_thread->quitting();
  //_checker_thread->wait();
}

void main_window::unblock_octave()
{
  octave_link::instance()->retake_events ();
  _run_action->setEnabled (!_stop_action->isEnabled());
  _run_and_profile->setEnabled (_run_action->isEnabled());
  //_checker_thread->restart();
}

void main_window::set_layout_default()
{
  QString origsettings("/usr/share/octave-upm/config/settings");

  if (QFile::exists(origsettings))
  {
    QSettings *settings = new QSettings(origsettings, QSettings::IniFormat);
    restoreGeometry (settings->value ("MainWindow/geometry").toByteArray ());
    restoreState (settings->value ("MainWindow/windowState").toByteArray ());
    delete settings;
  }
}

/*
void main_window::set_layout_editor()
{

}

void main_window::set_layout_terminal()
{

}*/

void
main_window::show_help_window ()
{
	_help_browser->show_help_browser ();
}
