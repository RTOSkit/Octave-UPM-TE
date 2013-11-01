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

#ifndef FILEEDITORINTERFACE_H
#define FILEEDITORINTERFACE_H

#include <QDockWidget>
#include <QCloseEvent>
#include <QFileInfo>


class QTerminal;
class main_window;

class file_editor_interface : public QDockWidget
{
  Q_OBJECT

  public:
    file_editor_interface (main_window *mainWindow)
      : QDockWidget ((QWidget*)mainWindow) // QDockWidget constructor is explicit, hence the cast.
    {
      setObjectName ("FileEditor");
      _main_window = mainWindow;

      connect (this, SIGNAL (visibilityChanged (bool)), this, SLOT (handle_visibility_changed (bool)));
    }

    virtual ~file_editor_interface () { }
  public slots:
    virtual void request_new_file () = 0;
    virtual void request_open_file () = 0;
    virtual void request_open_file (QString fileName) = 0;
    virtual void request_save_file () = 0;
    virtual void request_save_file_as () = 0;
    virtual void request_close_file () = 0;
    virtual void request_undo () = 0;
    virtual void request_redo () = 0;
    virtual void request_copy () = 0;
    virtual void request_cut () = 0;
    virtual void request_paste () = 0;
    virtual void request_find () = 0;
    virtual QString request_run_file () = 0;
    virtual void request_toggle_bookmark () = 0;
    virtual void request_next_bookmark () = 0;
    virtual void request_previous_bookmark () = 0;
    virtual void request_remove_bookmark () = 0;
    virtual void request_comment_selected_text () = 0;
    virtual void request_uncomment_selected_text () = 0;
    virtual void request_next_breakpoint () = 0;
    virtual void request_previous_breakpoint () = 0;
    virtual void request_toggle_breakpoint () = 0;
    virtual void request_remove_breakpoint () = 0;    
    
    virtual bool copy_available () = 0;
    virtual bool editor_active () = 0;
    virtual bool file_modified () = 0;
    virtual QStringList get_all_open_files () = 0;
    virtual QString active_filename () = 0;
    virtual int find_filename_in_tabs (QFileInfo) = 0;
    

    
    virtual void handle_entered_debug_mode () = 0;
    virtual void handle_quit_debug_mode () = 0;
    virtual void handle_debug_in_progress () = 0;
    

    virtual void notice_settings () = 0;
    virtual bool save_all_tabs () = 0;

  signals:
      void active_changed (bool active);
      void editor_changed ();

  protected:
    main_window* _main_window;

    

  protected slots:
    void handle_visibility_changed (bool visible)
    {
      if (visible)
        emit active_changed (true);
    }
    
};

#endif // FILEEDITORINTERFACE_H
