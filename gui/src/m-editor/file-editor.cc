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

#include "file-editor.h"
#include <QVBoxLayout>
#include <QApplication>
#include <QFile>
#include <QFont>
#include <QFileDialog>
#include <QMessageBox>
#include <QStyle>
#include <QTextStream>

file_editor::file_editor (main_window *mainWindow)
  : file_editor_interface(mainWindow)
{
  construct ();

  _main_window = mainWindow;
  setVisible (false);

  _last_debug_file = QString ("");
  _last_line = -1;

}

file_editor::~file_editor ()
{
}

QsciLexer *
file_editor::lexer ()
{
  return _lexer;
}

main_window *
file_editor::mainWindow ()
{
  return _main_window;
}

void
file_editor::event_accepted (octave_event *e)
{
  if (!_editor_update_mutex.tryLock ())
  {
    delete e;
    return;
  }

  octave_highlight_debug_event *abe = dynamic_cast<octave_highlight_debug_event*> (e);

  if (!abe)
  {
    release_lock();
    delete e;
    return;
  }

  QFileInfo debug_file(QFileInfo(abe->get_path()).absoluteFilePath());
  int line = abe->get_line ();

  // Same file and line -> ignore
  if (line == _last_line && debug_file == _last_debug_file)
  {
    release_lock();
    delete e;
    return;
  }

  _last_debug_file = debug_file;
  _last_line = line;

  int current;
  if (active_editor_tab ())
    current = _tab_widget->indexOf (active_editor_tab ());
  else
    current = -1;

  int tab = find_filename_in_tabs (debug_file);

  // Tab not found
  if (tab < 0)
  {
    release_lock ();
    delete e;
    return;
  }


  file_editor_tab *t = dynamic_cast<file_editor_tab*> (_tab_widget->widget (tab));
  if (t && t == active_editor_tab ())
      t->set_debugger_position (line);
  else
      release_lock ();


  // If we have switched tabs, highlight again
  if (tab != current && _editor_update_mutex.tryLock ())
  {
    t->set_debugger_position (line);
  }

  mainWindow ()->get_workspace_dock_widget()->get_model ()->clear_scopes ();
  // Update workspace
  QStringList names = abe->get_names ();
  QList<int> scopes = abe->get_scopes ();
  for(int i = 0; i < names.length (); i++)
    mainWindow ()->get_workspace_dock_widget()->get_model()->add_scope (names.at (i), scopes.at (i));

  mainWindow ()->get_workspace_dock_widget ()->update_scopes ();
  //mainWindow ()->get_workspace_dock_widget ()->get_model ()->set_current_scope(abe->get_current_scope ());

  release_lock ();
  delete e;
}

void
file_editor::event_reject (octave_event *e)
{
  release_lock ();
  delete e;
}

void file_editor::handle_debug_in_progress()
{
   octave_link::instance ()->post_event
      (new octave_highlight_debug_event (*this));
}


void
file_editor::request_new_file ()
{
  file_editor_tab *fileEditorTab = new file_editor_tab (this);
  if (fileEditorTab)
    {
      add_file_editor_tab (fileEditorTab);
      fileEditorTab->new_file ();
    }
}

void
file_editor::request_open_file ()
{
  QString openFileName;
  QFileDialog fileDialog(this);
  fileDialog.setNameFilter(SAVE_FILE_FILTER);
  fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
  fileDialog.setViewMode(QFileDialog::Detail);
  fileDialog.setDirectory (this->get_current_directory ());
  if (fileDialog.exec () == QDialog::Accepted)
    {
      openFileName = fileDialog.selectedFiles().at(0);
      QFile f;
      f.setFileName(openFileName);
      if (openFileName.isEmpty () || !f.exists())
	      return;
      else
	      request_open_file (openFileName);
    }
}

void
file_editor::request_open_file (QString fileName)
{
  if (!isVisible ())
    {
      show ();
    }

  QFile file (fileName);

  if (!file.exists())
    return;

  int p = find_filename_in_tabs (file);

  // Tab not found
  if (p < 0)
  {
	  file_editor_tab *fileEditorTab = new file_editor_tab (this);
	  if (fileEditorTab)
	  {
		  add_file_editor_tab (fileEditorTab);
		  fileEditorTab->load_file (fileName);
	  }
  }
}


void
file_editor::handle_entered_debug_mode ()
{
  handle_debug_in_progress ();
}

void
file_editor::handle_quit_debug_mode ()
{
  // Erase marker
  for (int i=0; i < _tab_widget->count (); i++)
    {
      file_editor_tab *t = dynamic_cast <file_editor_tab*> (_tab_widget->widget (i));
      t->set_debugger_position (0);
    }

  _editor_update_mutex.unlock ();
  _last_line = -1;
  _last_debug_file = QString ("");
}


void
file_editor::request_undo ()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab)
    activeFileEditorTab->undo ();
}

void
file_editor::request_redo ()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab)
    activeFileEditorTab->redo ();
}

void
file_editor::request_copy ()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab)
    activeFileEditorTab->copy ();
}

void
file_editor::request_cut ()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab)
    activeFileEditorTab->cut ();
}

void
file_editor::request_paste ()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab)
    activeFileEditorTab->paste ();
}

void
file_editor::request_find()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab)
    activeFileEditorTab->find ();
}


void
file_editor::request_save_file ()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab)
    activeFileEditorTab->save_file ();
}

void
file_editor::request_save_file_as ()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab)
    activeFileEditorTab->save_file_as ();
}

void
file_editor::request_close_file()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab && activeFileEditorTab->close())
  {
   _tab_widget->removeTab (_tab_widget->indexOf (activeFileEditorTab));
   delete activeFileEditorTab;
  }
}


QString
file_editor::request_run_file ()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab)
    return activeFileEditorTab->run_file ();

  return QString("");
}

void
file_editor::request_toggle_bookmark ()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab)
    activeFileEditorTab->toggle_bookmark ();
}

void
file_editor::request_next_bookmark ()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab)
    activeFileEditorTab->next_bookmark ();
}

void
file_editor::request_previous_bookmark ()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab)
    activeFileEditorTab->previous_bookmark ();
}

void
file_editor::request_remove_bookmark ()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab)
    activeFileEditorTab->remove_bookmark ();
}

void
file_editor::request_toggle_breakpoint ()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab)
    activeFileEditorTab->toggle_breakpoint ();
}

void
file_editor::request_next_breakpoint ()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab)
    activeFileEditorTab->next_breakpoint ();
}

void
file_editor::request_previous_breakpoint ()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab)
    activeFileEditorTab->previous_breakpoint ();
}

void
file_editor::request_remove_breakpoint ()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab)
    activeFileEditorTab->remove_all_breakpoints ();
}


void
file_editor::request_comment_selected_text ()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab)
    activeFileEditorTab->comment_selected_text ();
}

void
file_editor::request_uncomment_selected_text ()
{
  file_editor_tab *activeFileEditorTab = active_editor_tab ();
  if (activeFileEditorTab)
    activeFileEditorTab->uncomment_selected_text ();
}

void
file_editor::handle_file_name_changed (QString fileName)
{
  QObject *senderObject = sender ();
  file_editor_tab *fileEditorTab = dynamic_cast<file_editor_tab*> (senderObject);
  if (fileEditorTab)
    {
      for(int i = 0; i < _tab_widget->count (); i++)
        {
          if (_tab_widget->widget (i) == fileEditorTab)
            {
              _tab_widget->setTabText (i, fileName);
            }
        }
    }
}

void
file_editor::handle_tab_close_request (int index)
{
  file_editor_tab *fileEditorTab = dynamic_cast <file_editor_tab*> (_tab_widget->widget (index));
  if (fileEditorTab)
    if (fileEditorTab->close ())
      {
        _tab_widget->removeTab (index);
        delete fileEditorTab;
      }
}

void
file_editor::handle_tab_close_request ()
{
  file_editor_tab *fileEditorTab = dynamic_cast <file_editor_tab*> (sender ());
  if (fileEditorTab)
    if (fileEditorTab->close ())
      {
        _tab_widget->removeTab (_tab_widget->indexOf (fileEditorTab));
        delete fileEditorTab;
      }
}

void
file_editor::active_tab_changed (int index)
{
  Q_UNUSED (index);
  handle_editor_state_changed ();
}

void
file_editor::handle_editor_state_changed ()
{
  emit editor_changed ();
}

bool
file_editor::copy_available()
{
  file_editor_tab *f = active_editor_tab ();
  if (f)
    return f->copy_available ();
  else
    return false;
}

bool
file_editor::editor_active()
{
  return active_editor_tab() != NULL;
}

bool
file_editor::file_modified()
{
  file_editor_tab *f = active_editor_tab ();

  if (f)
    return f->is_modified ();
  else
    return false;
}

void
file_editor::construct ()
{
  QWidget *widget = new QWidget (this);
  QSettings *settings = resource_manager::instance ()->get_settings ();
  QStyle *style = QApplication::style ();

  _tab_widget = new QTabWidget (widget);
  _tab_widget->setTabsClosable (true);
  _tab_widget->setMovable (true);
  _tab_widget->setDocumentMode (true);
  _tab_widget->setTabShape (QTabWidget::Rounded);
  _tab_widget->setUsesScrollButtons (true);

  QVBoxLayout *layout = new QVBoxLayout ();
  layout->addWidget (_tab_widget);
  layout->setMargin (0);
  widget->setLayout (layout);
  setWidget (widget);

  connect (_tab_widget, SIGNAL (tabCloseRequested (int)), this, SLOT (handle_tab_close_request (int)));
  connect (_tab_widget, SIGNAL (currentChanged(int)), this, SLOT (active_tab_changed (int)));

  // this has to be done only once, not for each editor
  //_lexer = new lexer_octave_gui ();
  _lexer = new QsciLexerMatlab ();
  //_lexer = new QsciLexerCPP();

  // Editor font (default or from settings)
  _lexer->setDefaultFont (QFont (
                             settings->value ("editor/fontName","Courier").toString (),
                             settings->value ("editor/fontSize",10).toInt ()));

  // TODO: Autoindent not working as it should
  _lexer->setAutoIndentStyle (QsciScintilla::AiMaintain ||
                               QsciScintilla::AiOpening  ||
                               QsciScintilla::AiClosing);


  // The API info that is used for auto completion
  // TODO: Where to store a file with API info (raw or prepared?)?
  // TODO: Also provide infos on octave-forge functions?
  // TODO: Also provide infos on function parameters?
  // By now, use the keywords-list from syntax highlighting
  _lexer_api = new QsciAPIs (_lexer);

  QString keyword;
  QStringList keywordList;
  keyword = _lexer->keywords (1);  // get whole string with all keywords
  keywordList = keyword.split (QRegExp ("\\s+"));  // split into single strings
  QStringList matlab_keywords = QString(resource_manager::instance ()->matlab_keywords ()).split(QRegExp ("\\s+"));

  for (int i=0; i < matlab_keywords.size (); i++)
  {
    if (!keywordList.contains(matlab_keywords.at (i)))
      keywordList.append(matlab_keywords.at (i));
  }

  int i;
  for (i = 0; i < keywordList.size (); i++)
    {
      _lexer_api->add (keywordList.at (i));  // add single strings to the API
    }
  _lexer_api->prepare ();           // prepare API info ... this make take some time
  resize (500, 400);
  setWindowIcon (QIcon::fromTheme ("accessories-text-editor", style->standardIcon (QStyle::SP_FileIcon)));
  setWindowTitle ("Editor");
}

void
file_editor::add_file_editor_tab (file_editor_tab *f)
{
  _tab_widget->addTab (f, "");
  connect (f, SIGNAL (file_name_changed(QString)),
           this, SLOT(handle_file_name_changed(QString)));
  connect (f, SIGNAL (editor_state_changed ()),
           this, SLOT (handle_editor_state_changed ()));
  _tab_widget->setCurrentWidget (f);
}

file_editor_tab *
file_editor::active_editor_tab ()
{
  return dynamic_cast<file_editor_tab*> (_tab_widget->currentWidget ());
}

bool
file_editor::save_all_tabs()
{
  for(int i=0; i < _tab_widget->count(); i++)
  {
    file_editor_tab *t = dynamic_cast <file_editor_tab*> (_tab_widget->widget (i));
    if (t)
    {
      if (!t->attempt_save ())
      {
	return false;
      }
    }
  }

  return true;
}

QStringList
file_editor::get_all_open_files ()
{
    QStringList open_files = QStringList();
    for (int i=0; i < _tab_widget->count (); i++)
    {
      file_editor_tab *t = dynamic_cast <file_editor_tab*> (_tab_widget->widget (i));
      open_files << t->get_file_name ();
    }

    return open_files;
}

void
file_editor::notice_settings()
{
  QSettings *settings = resource_manager::instance ()->get_settings ();

  _lexer->setFont (QFont (
                             settings->value ("editor/fontName","Consolas").toString (),
                             settings->value ("editor/fontSize",10).toInt ()));

  _lexer->setDefaultFont (QFont (
                             settings->value ("editor/fontName","Consolas").toString (),
                             settings->value ("editor/fontSize",10).toInt ()));

  for (int i=0; i < _tab_widget->count (); i++)
  {
    file_editor_tab *t = dynamic_cast <file_editor_tab*> (_tab_widget->widget (i));
    if (t)
      t->notice_settings ();
  }
}

void
file_editor::set_current_directory(QString directory)
{
  _current_directory = directory;
}

QString
file_editor::active_filename()
{
  file_editor_tab *t = active_editor_tab ();
  if (t)
    return t->get_file_name ();
  else
    return QString("");
}

int
file_editor::find_filename_in_tabs(QFileInfo fn)
{
    for (int i=0; i < _tab_widget->count (); i++)
    {
      file_editor_tab *t = dynamic_cast <file_editor_tab*> (_tab_widget->widget (i));
      QString f1 = QFileInfo(t->get_file_name()).absoluteFilePath();
      QString f2 = fn.absoluteFilePath();
      if (f1.toLower () == f2.toLower())
      {
	_tab_widget->setCurrentIndex (i);
	return i;
      }
    }

    return -1;
}

