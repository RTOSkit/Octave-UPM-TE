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

#ifndef FILESDOCKWIDGET_H
#define FILESDOCKWIDGET_H

#include <QListView>
#include <QDate>
#include <QObject>
#include <QWidget>
#include <QListWidget>
#include <QFileSystemModel>
#include <QToolBar>
#include <QToolButton>
#include <QVBoxLayout>
#include <QAction>
#include <QTreeView>
#include <QFocusEvent>
#include <QDockWidget>
#include <QLineEdit>
#include <QApplication>

#include "octave-adapter/octave-link.h"

class files_dock_widget : public QDockWidget
{
  Q_OBJECT
public:
  files_dock_widget (QWidget *parent = 0);

public slots:
  /** Slot for handling a change in directory via double click. */
  void item_double_clicked (const QModelIndex & index);

  /** Slot for handling the up-directory button in the toolbar. */
  void do_up_directory ();
  void set_current_directory (QString currentDirectory);
  void current_directory_entered ();

  /** Tells the widget to notice settings that are probably new. */
  void notice_settings ();
  void handle_visibility_changed (bool visible);

  void on_working_dir_changed (QString dirname);

  
signals:
  void open_file (QString fileName);

  /** Custom signal that tells if a user has clicke away that dock widget. */
  void active_changed (bool active);
  
  void change_working_directory (QString dirName);

protected:
  void closeEvent (QCloseEvent *event);
  
  void focusInEvent (QFocusEvent *e)
  {
    _file_tree_view->activateWindow ();
    _file_tree_view->setFocus ();
    e->accept ();
  }

private:
  // TODO: Add toolbar with buttons for navigating the path, creating dirs, etc

  /** Toolbar for file and directory manipulation. */
  QToolBar *        _navigation_tool_bar;

  /** Variables for the up-directory action. */
  QIcon             _directory_icon;
  QAction *         _directory_up_action;
  QToolButton *     _up_directory_button;

  /** The file system model. */
  QFileSystemModel *_file_system_model;

  /** The file system view. */
  QTreeView *       _file_tree_view;
  QLineEdit *       _current_directory;
};

#endif // FILESDOCKWIDGET_H
