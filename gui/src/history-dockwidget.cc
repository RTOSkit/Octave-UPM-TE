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

#include "history-dockwidget.h"
#include <QVBoxLayout>

history_dock_widget::history_dock_widget (QWidget * parent)
  : QDockWidget (parent), octave_event_observer ()
{
  setObjectName ("HistoryDockWidget");
  construct ();
}

void
history_dock_widget::event_accepted (octave_event *e)
{
  if (dynamic_cast <octave_update_history_event*> (e) && _history_mutex.tryLock())
    {
      try {
	// Determine the client's (our) history length and the one of the server.
	int clientHistoryLength = _history_model->rowCount ();
	int serverHistoryLength = command_history::length ();

	// If were behind the server, iterate through all new entries and add
	// them to our history.
	if (clientHistoryLength < serverHistoryLength)
	  {
	    for (int i = clientHistoryLength; i < serverHistoryLength; i++)
	      {
		_history_model->insertRow (i);
		_history_model->setData (_history_model->index (i),
		  QString (command_history::get_entry (i).c_str ()));
	      }

	    if(_first_load)
	    {
	      _first_load = false;
	      emit load_finished ();
	    }
	  }
      }
      catch (...)
      {
	//std::cout << "% History exception!\n";
      }

      _history_mutex.unlock ();
    }

  delete e;

  emit restart_timer ();
}

void
history_dock_widget::event_reject (octave_event *e)
{
  emit restart_timer ();
  delete e;
}

void
history_dock_widget::construct ()
{
  _history_model = new QStringListModel ();
  _sort_filter_proxy_model.setSourceModel (_history_model);
  _history_list_view = new QListView (this);
  _history_list_view->setModel (&_sort_filter_proxy_model);
  _history_list_view->setAlternatingRowColors (true);
  _history_list_view->setEditTriggers (QAbstractItemView::NoEditTriggers);
  _history_list_view->setSelectionMode (QAbstractItemView::ExtendedSelection);
  _history_list_view->setStatusTip (tr ("Doubleclick a command to transfer it to the terminal."));
  _filter_line_edit = new QLineEdit (this);
  _filter_line_edit->setStatusTip (tr ("Enter text to filter the command history."));
  _copy_button = new QPushButton (QIcon(":/icons/media/Copy-icon.png"),"",this);
  _copy_button->setToolTip (tr("Copy the selected commands to the clipboard"));
  _copy_button->setStatusTip (tr("Copy the selected commands to the clipboard"));
  QVBoxLayout *layout = new QVBoxLayout ();
  QHBoxLayout *hlayout = new QHBoxLayout ();
  hlayout->addWidget (_copy_button);
  hlayout->addWidget (_filter_line_edit);

  _copy_button->setEnabled (false);

  setWindowTitle (tr ("Command History"));
  setWidget (new QWidget ());

  layout->addWidget (_history_list_view);
  layout->addLayout (hlayout);
  layout->setMargin (2);

  widget ()->setLayout (layout);

  connect (_filter_line_edit,
           SIGNAL (textEdited (QString)),
           &_sort_filter_proxy_model,
           SLOT (setFilterWildcard (QString)));

  connect (_history_list_view,
           SIGNAL (doubleClicked (QModelIndex)),
           this,
           SLOT (handle_double_click (QModelIndex)));

  connect (this,
           SIGNAL (visibilityChanged (bool)),
           this,
           SLOT (handle_visibility_changed (bool)));

  connect (_copy_button,
	   SIGNAL (clicked ()),
	   this,
	   SLOT (copy_selection ()));

  connect (_history_list_view,
	   SIGNAL (clicked (QModelIndex)),
	   this,
	   SLOT (item_selected (QModelIndex)));

  _update_history_model_timer.setInterval (500);
  _update_history_model_timer.setSingleShot (true);

  connect (&_update_history_model_timer,
           SIGNAL (timeout ()),
           this,
           SLOT (request_history_model_update ()));

  connect (_history_model,
	   SIGNAL (dataChanged(QModelIndex,QModelIndex)),
	   this,
	   SLOT (update_scroll(QModelIndex,QModelIndex)));

  connect (this,
	   SIGNAL(restart_timer()),
	   &_update_history_model_timer,
	   SLOT (start()));

  request_history_model_update ();
  _first_load = true;
  _update_history_model_timer.start ();
  _nCommands = -1;
}

void
history_dock_widget::handle_double_click (QModelIndex modelIndex)
{
  emit command_double_clicked (modelIndex.data().toString());
}

void
history_dock_widget::handle_visibility_changed (bool visible)
{
  if (visible)
    emit active_changed (true);
}

void
history_dock_widget::request_history_model_update ()
{
  if (!isHidden())
    octave_link::instance ()->post_event (new octave_update_history_event (*this));
  else
    _update_history_model_timer.start();
}

void
history_dock_widget::closeEvent (QCloseEvent *event)
{
  emit active_changed (false);
  QDockWidget::closeEvent (event);
}

void
history_dock_widget::copy_selection()
{
  QItemSelectionModel *m = _history_list_view->selectionModel();
  QModelIndexList s = m->selection ().indexes();
  QString copy = QString ("");
  for (int i = 0; i < s.size (); i++)
  {
    copy.append(s.at(i).data().toString ());
    copy.append("\n");
  }

  QApplication::clipboard()->setText(copy);
}

void history_dock_widget::item_selected(QModelIndex model)
{
  Q_UNUSED (model);
  QItemSelectionModel *m = _history_list_view->selectionModel();
  QModelIndexList s = m->selection ().indexes();
  if (s.size() > 0)
    _copy_button->setEnabled (true);
  else
    _copy_button->setEnabled (false);
}

void
history_dock_widget::update_scroll(QModelIndex a, QModelIndex b)
{
    Q_UNUSED (a);
    Q_UNUSED (b);

    _history_list_view->scrollToBottom ();
}


void
history_dock_widget::notice_settings()
{
  QSettings *settings = resource_manager::instance ()->get_settings ();
  QFont font = QFont();
  if (settings->value ("history/defaultFont").toBool())
  {
    font.setFamily (qApp->font().family ());
    font.setPointSize (qApp->font().pointSize ());
  }
  else
  {
    font.setFamily(settings->value("history/fontName").toString());
    font.setPointSize(settings->value("history/fontSize").toInt ());
  }

  this->setFont (font);

  int nCommands = settings->value ("history/numCommands").toInt ();

  if (nCommands != _nCommands)
  {
    _nCommands = nCommands;
    octave_link::instance ()
      ->post_event (new octave_clear_history_event (*this, nCommands));
  }
}
