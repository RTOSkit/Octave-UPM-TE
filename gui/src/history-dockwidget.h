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

#ifndef HISTORYDOCKWIDGET_H
#define HISTORYDOCKWIDGET_H

#include <QDockWidget>
#include <QLineEdit>
#include <QListView>
#include <QSortFilterProxyModel>
#include <QStringListModel>
#include <QTimer>
#include <QPushButton>
#include <QApplication>
#include <QClipboard>
#include <QFocusEvent>
#include <QMutex>
#include <QApplication>

#include "resource-manager.h"
#include "octave-link.h"
#include "octave-event-observer.h"

class history_dock_widget : public QDockWidget, public octave_event_observer
{
Q_OBJECT
public:
  history_dock_widget (QWidget *parent = 0);

  void event_accepted (octave_event *e);
  void event_reject (octave_event *e);

public slots:
  void handle_visibility_changed (bool visible);
  void request_history_model_update ();
  void copy_selection ();
  void item_selected (QModelIndex);
  
  void notice_settings ();

signals:
  void command_double_clicked (QString command);
  void active_changed (bool active);
  void load_finished ();
  void restart_timer ();
  
protected:
  void closeEvent (QCloseEvent *event);
   
  void focusInEvent (QFocusEvent *e)
  {
    _history_list_view->activateWindow ();
    _history_list_view->setFocus ();
    e->accept ();
  }
  
private slots:
  void handle_double_click (QModelIndex modelIndex);
  void update_scroll (QModelIndex, QModelIndex);
  
 

private:
  void construct ();
  QListView *_history_list_view;
  QLineEdit *_filter_line_edit;
  QPushButton * _copy_button;
  QSortFilterProxyModel _sort_filter_proxy_model;

  /** Stores the current history_model. */
  QStringListModel *_history_model;

  QTimer _update_history_model_timer;
  bool _first_load;
  
  QMutex _history_mutex;
  int _nCommands;
};

#endif // HISTORYDOCKWIDGET_H
