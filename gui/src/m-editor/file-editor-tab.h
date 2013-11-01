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

#ifndef FILEEDITORTAB_H
#define FILEEDITORTAB_H

#include <QsciOctUPM/qsciscintilla.h>
#include <QsciOctUPM/qscilexermatlab.h>
#include <QWidget>
#include <QCloseEvent>
//#include <QFileSystemWatcher>
#include <QFileDialog>
#include <QTextStream>
#include "octave-event-observer.h"
#include "find-dialog.h"

class file_editor;
class file_editor_tab : public QWidget, public octave_event_observer
{
  Q_OBJECT
public:
  file_editor_tab (file_editor *fileEditor);
  bool copy_available ();

  void event_accepted (octave_event *e);
  void event_reject (octave_event *e);


public slots:
  void new_title(bool modified);
  void handle_copy_available(bool enableCopy);
  void handle_margin_clicked (int line, int margin, Qt::KeyboardModifiers state);
  void comment_selected_text ();
  void uncomment_selected_text ();
  void remove_bookmark ();
  void toggle_bookmark ();
  void next_bookmark ();
  void previous_bookmark ();
  void remove_all_breakpoints ();
  void toggle_breakpoint ();
  void next_breakpoint ();
  void previous_breakpoint ();
  void cut ();
  void copy ();
  void paste ();
  void undo ();
  void redo ();
  void set_debugger_position (int line);
  void find ();

  void set_modified (bool modified = true);

  void load_file (QString fileName);
  void new_file ();
  bool save_file ();
  bool save_file(QString saveFileName);
  bool save_file_as();
  QString run_file ();
  bool attempt_save ();
  void save_backup ();
  void remove_backup_file ();
  void check_backup_file (QString);

  void notice_settings();

  bool is_modified () {return _edit_area->isModified();}

  QString get_file_name () { return _file_name;};

  void set_autosave (bool active, int period);

signals:
  void file_name_changed (QString fileName);
  void editor_state_changed ();

protected:
  void closeEvent (QCloseEvent *event);
  void set_file_name (QString fileName);

private:
  void request_add_breakpoint (int line);
  void request_remove_breakpoint (int line);
  bool check_file_modified (QString msg);
  void do_comment_selected_text (bool comment);

  void focusInEvent (QFocusEvent *event)
  {
    _edit_area->setFocus ();
    event->accept ();
  }

  file_editor *         _file_editor;
  QsciScintilla *       _edit_area;

  QString               _file_name;

  bool                  _long_title;
  bool                  _copy_available;

  QTimer		_autosave_timer;
  QString		_backup_filename;
  static int 		_num_files_created;
  bool			_is_unnamed;

  bool			_autosave;
};

#endif // FILEEDITORTAB_H
