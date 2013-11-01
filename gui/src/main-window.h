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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define OCTAVE_UPM_REL "R9+"

// Qt includes
#include <QtGui/QMainWindow>
#include <QThread>
#include <QTabWidget>
#include <QMdiArea>
#include <QStatusBar>
#include <QToolBar>
#include <QQueue>
#include <QMdiSubWindow>
#include <QCloseEvent>
#include <QToolButton>
#include <QComboBox>
#include <QTimer>
#include <QSplashScreen>
#include <QWhatsThis>
#include <QTemporaryFile>

// Editor includes
#include "file-editor-interface.h"

// QTerminal includes
#include "QTerminal.h"

// Own includes
#include "resource-manager.h"
#include "octave-link.h"
#include "workspace-view.h"
#include "history-dockwidget.h"
#include "files-dockwidget.h"
#include "terminal-dockwidget.h"
#include "octave-qt-event-listener.h"
#include "octave-event-observer.h"
#include "octave-model-checker-thread.h"

#include "ui_welcome-wizard.h"
#include "settings-dialog.h"
#include "preview-dialog.h"
#include "graphics-editor.h"
#include "profile_display.h"
#include "doc_viewer.h"

/**
  * \class MainWindow
  *
  * Represents the main window.
  */
class main_window
    : public QMainWindow, public octave_event_observer
{
Q_OBJECT public:
	main_window (QString open_file = QString (), QWidget * parent = 0);
  ~main_window ();

  void event_accepted (octave_event *e);
  void event_reject (octave_event *e);

  QTerminal *get_terminal_view () { return _terminal; }
  history_dock_widget *get_history_dock_widget () { return _history_dock_widget; }
  files_dock_widget *get_files_dock_widget () { return _files_dock_widget; }
  workspace_view *get_workspace_dock_widget () { return _workspace_view;}
  bool is_closing () { return _closing; }

public slots:
  void handle_save_workspace_request ();
  void handle_load_workspace_request ();
  void handle_clear_workspace_request ();
  void handle_command_double_clicked (QString command);
  void new_file ();
  void open_file ();
  void open_file (const QString &f);
  void save_file ();
  void save_file_as ();
  void close_file ();
  void undo ();
  void redo ();
  void copy ();
  void cut ();
  void paste ();
  void find ();
  void update_clipboard_actions ();
  void run_file ();
  void run_and_profile ();
  void stop_execution ();


  void toggle_breakpoint ();
  void next_breakpoint ();
  void previous_breakpoint ();
  void remove_breakpoint ();
  void comment_selected_text ();
  void uncomment_selected_text ();

  void process_settings_dialog_request ();
  void show_help_window ();
  void show_about_octave ();
  void show_about_octave_UPM ();
  void notice_settings ();
  bool prepare_for_quit ();
  void reset_windows ();
  void update_current_working_directory (QString directory);
  void change_current_working_directory ();
  void change_current_working_directory (QString directory);
  void current_working_directory_up ();
  void handle_hide_editor ();
  void finish_splash_screen ();
  void set_layout_default ();
  //void set_layout_editor ();
  //void set_layout_terminal ();

  void focus_workspace ();
  void focus_history ();
  void focus_terminal ();
  void focus_filebrowser ();
  void focus_editor ();


  void handle_entered_debug_mode ();
  void handle_quit_debug_mode ();
  void debug_continue ();
  void debug_step_into ();
  void debug_step_over ();
  void debug_step_out ();
  void debug_quit ();
  void handle_debug_in_progress ();

  void handle_refresh_plot ();
  void handle_clear_plots ();
  void handle_edit_plot ();
  void handle_export_image ();

  QMenu* createPopupMenu () { return NULL;};

  void check_available_toolkits ();
  void read_settings ();

  void check_stop_action ();
  void unset_stop_action ();

  void apply_graphics_editor_settings (int result);

  void block_octave_for_plot_edit ();
  void unblock_octave ();

signals:

  void restart_stop_action_timer ();
  void update_profile_info (QString);
  void profile_keeps_on ();

protected:
  void closeEvent (QCloseEvent * closeEvent);

  void write_settings ();

  void handle_preview_image (QString fn);

private slots:  
  void turn_off_profile ();

private:
  void construct ();
  void activate_tools (bool activate = true);

  QToolBar *		    _main_tool_bar;

  QTerminal *               _terminal;
  file_editor_interface *   _file_editor;
  QMenu *                   _debug_menu;
  QMenu *                   _plot_menu;

  QAction *                 _debug_continue;
  QAction *                 _debug_step_into;
  QAction *                 _debug_step_over;
  QAction *                 _debug_step_out;
  QAction *                 _debug_quit;

  // Dock widgets.
  workspace_view *          _workspace_view;
  history_dock_widget *     _history_dock_widget;
  files_dock_widget *       _files_dock_widget;
  terminal_dock_widget *    _terminal_dock_widget;
  profile_display *         _profiler_dock_widget;

  // Help browser
  doc_viewer *              _help_browser;
  
  // Toolbars.
  QStatusBar *              _status_bar;
  QComboBox *               _current_directory_combo_box;
  QToolButton *             _current_directory_tool_button;
  QToolButton *             _current_directory_up_tool_button;

  octave_qt_event_listener *_octave_qt_event_listener;

  // Flag for closing whole application
  bool                      _closing;
  QString                   _current_directory;
  QString                   _startup_filename_request;

  QAction *		    _copy_action;
  QAction *		    _cut_action;
  QAction *		    _paste_action;
  QAction *		    _find_action;
  QAction *		    _comment_selection_action;
  QAction *		    _uncomment_selection_action;
  QAction *		    _undo_action;
  QAction *		    _redo_action;
  QAction *		    _next_breakpoint_action;
  QAction *		    _previous_breakpoint_action;
  QAction *		    _toggle_breakpoint_action;
  QAction *		    _remove_breakpoint_action;
  QAction *		    _run_action;
  QAction *                 _run_and_profile;
  QAction *		    _stop_action;
  QAction *		    _save_action;
  QAction *		    _save_as_action;
  QAction *		    _close_action;

  QAction *		    _show_editor_action;
  QSplashScreen * 	    _splash_screen;

  QAction *		    _jump_to_editor_action;
  QAction *		    _jump_to_terminal_action;
  QAction *		    _jump_to_ws_action;
  QAction *		    _jump_to_history_action;
  QAction *		    _jump_to_file_action;
  QAction *                 _jump_to_profiler;

  QAction *		    _default_layout_action;
  //QAction *                 _only_editor_action;
  //QAction *                 _only_terminal_action;

  QAction *		    _show_command_window_action;
  QAction *		    _show_workspace_action;
  QAction *		    _show_history_action;
  QAction *		    _show_file_browser_action;
  QAction *                 _show_profiler_action;

  settings_dialog *	    _settings_dialog;

  bool			    _supress_warning;
  bool			    _first_read_settings;
  bool			    _matlab_compatible_warning;
  int			    _broadcasting_option;
  QStringList		    _graphics_toolkits;
  QString		    _current_graphics_toolkit;
  QTimer		    _check_toolkits_timer;
  QTimer		    _stop_action_available_timer;
  bool			    _already_stopped;

  bool			    _debugging;
  bool                      _profiling;

  octave_model_checker_thread *_checker_thread;

  GraphicsEditor            *_graphics_editor;
};

#endif // MAINWINDOW_H
