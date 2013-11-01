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

#ifndef WORKSPACEVIEW_H
#define WORKSPACEVIEW_H

#include <QDockWidget>
#include <QTimer>
#include <QTreeView>
#include <QComboBox>
#include <QSemaphore>
#include <QLabel>
#include <QApplication>
#include <QInputDialog>

#include "octave-link.h"
#include "workspace-model.h"
#include "octave-event.h"

class workspace_view : public QDockWidget, octave_event_observer
{
  Q_OBJECT
public:
  workspace_view (QWidget * parent = 0);
  ~workspace_view ();

public slots:
  void handle_visibility_changed (bool visible);
  
  workspace_model* get_model () { return _workspace_model;}
  
  void highlight_scope (int s);
  void update_scopes ();
  
  void event_accepted (octave_event *e);
  void event_reject (octave_event *e);
  
  void notice_settings ();

signals:
  /** Custom signal that tells if a user has clicke away that dock widget. */
  void active_changed (bool active);

protected:
  void closeEvent (QCloseEvent *event);

protected slots:
  void item_double_clicked (QModelIndex index);
  void item_changed (QModelIndex index, QModelIndex other_index);
  void model_changed ();

private:


  QTreeView *_workspace_tree_view;

  /** Stores the current workspace model. */
  workspace_model *_workspace_model;

  QComboBox *_scope_cb;
  QLabel *_scope_label;
  
  QModelIndex _current_index;
};

#endif // WORKSPACEVIEW_H
