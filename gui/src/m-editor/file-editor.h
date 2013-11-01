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

#ifndef FILEEDITORMDISUBWINDOW_H
#define FILEEDITORMDISUBWINDOW_H

#include "main-window.h"
#include "file-editor-interface.h"
#include "file-editor-tab.h"
#include "octave-event-observer.h"

#include <QToolBar>
#include <QAction>
#include <QMenuBar>
#include <QStatusBar>
#include <QCloseEvent>
#include <QTabWidget>
#include <QsciOctUPM/qsciapis.h>
// Not available in the Debian repos yet!
//#include <Qsci/qscilexeroctave.h>
//#include "lexer-octave-gui.h"
#include <QsciOctUPM/qscilexermatlab.h>
#include <QString>
#include "octave-event.h"

const char UNNAMED_FILE[]     = "unnamed";
const char SAVE_FILE_FILTER[] = "Octave Files (*.m);;All Files (*.*)";
enum editor_markers
  {
    bookmark,
    breakpoint,
    debugger_position,
    debugger_line
  };

class file_editor : public file_editor_interface, public octave_event_observer
{
Q_OBJECT

public:
  file_editor (main_window *mainWindow);
  ~file_editor ();
  void loadFile (QString fileName);

  QsciLexer   *lexer ();
  main_window *     mainWindow ();

  void event_accepted (octave_event *e);
  void event_reject (octave_event *e);

  void release_lock () {_editor_update_mutex.unlock();};


public slots:
  void request_new_file ();
  void request_open_file ();
  void request_open_file (QString fileName);


  void handle_entered_debug_mode ();
  void handle_quit_debug_mode ();
  void handle_debug_in_progress ();

  void request_undo ();
  void request_redo ();
  void request_copy ();
  void request_cut ();
  void request_paste ();
  void request_find ();
  void request_save_file ();
  void request_save_file_as ();
  void request_close_file ();
  QString request_run_file ();
  void request_toggle_bookmark ();
  void request_next_bookmark ();
  void request_previous_bookmark ();
  void request_remove_bookmark ();
  void request_comment_selected_text ();
  void request_uncomment_selected_text ();

  void request_toggle_breakpoint ();
  void request_next_breakpoint ();
  void request_previous_breakpoint ();
  void request_remove_breakpoint ();

  void handle_file_name_changed (QString fileName);
  void handle_tab_close_request (int index);
  void handle_tab_close_request ();
  void active_tab_changed (int index);
  void handle_editor_state_changed ();

  bool save_all_tabs ();
  void notice_settings ();
  void set_current_directory (QString);
  QString get_current_directory () { return _current_directory;};

  bool copy_available ();
  bool editor_active ();
  bool file_modified ();

  QStringList get_all_open_files ();
  QString active_filename ();
  int find_filename_in_tabs (QFileInfo fn);

signals:
  void editor_changed ();

protected:
    void closeEvent (QCloseEvent *event)
    {
      if (!_main_window->is_closing())
      {
	if (save_all_tabs ())
	{
	  emit active_changed (false);
	  setVisible (false);
	  event->accept ();
	}
	else
	{
	  emit active_changed (true);
	  event->ignore ();
	}
      }
      else
	event->ignore ();
    }

    void focusInEvent (QFocusEvent * event)
    {
      this->repaint ();
      file_editor_tab *f = active_editor_tab ();
      if (f)
      {
	f->activateWindow ();
	f->setFocus ();
	event->accept ();
      }
    }

private:
  void construct ();
  void add_file_editor_tab(file_editor_tab *f);
  file_editor_tab *active_editor_tab();

  //QMenu *           _debug_menu;
  QTabWidget *      _tab_widget;
  int               _marker_bookmark;
  QsciLexer	    *_lexer;
  QsciAPIs *        _lexer_api;
  QString           _current_directory;

  QMutex _editor_update_mutex;
  QFileInfo _last_debug_file;
  int _last_line;
};

#endif // FILEEDITORMDISUBWINDOW_H
