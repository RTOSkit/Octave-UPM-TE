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

#include "workspace-view.h"
#include "resource-manager.h"
#include <octave-event.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

workspace_view::workspace_view (QWidget * parent) : QDockWidget (parent)
{
  _current_index = QModelIndex();
  
  setObjectName ("WorkspaceView");
  setWindowTitle (tr ("Workspace"));

  // Create a new workspace model.
  _workspace_model = new workspace_model ();

  _workspace_tree_view = new QTreeView (this);            // Create a new tree view.
  _workspace_tree_view->setHeaderHidden (false);          // Do not show header columns.
  _workspace_tree_view->setAlternatingRowColors (true);   // Activate alternating row colors.
  _workspace_tree_view->setAnimated (false);              // Deactivate animations because of strange glitches.
  _workspace_tree_view->setTextElideMode (Qt::ElideRight);// Elide text to the right side of the cells.
  _workspace_tree_view->setWordWrap (false);              // No wordwrapping in cells.
  _workspace_tree_view->setModel (_workspace_model);      // Assign model.
  _workspace_tree_view->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

  _scope_cb = new QComboBox (this);
  _scope_cb->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
  _scope_label = new QLabel (tr ("Scope: "), this);
  _scope_label->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);  
  
  QHBoxLayout *hlayout = new QHBoxLayout ();  
  hlayout->addWidget (_scope_label);
  hlayout->addWidget (_scope_cb);
  
  // Set an empty widget, so we can assign a layout to it.
  setWidget (new QWidget (this));

  // Create a new layout and add widgets to it.
  QVBoxLayout *layout = new QVBoxLayout ();
  layout->addWidget (_workspace_tree_view);
  layout->addLayout (hlayout);
  layout->setMargin (2);
  
  _scope_cb->setEnabled (false);
  _scope_label->setEnabled (false);

  // Set the empty widget to have our layout.
  widget ()->setLayout (layout);

  // Connect signals and slots.
  connect (this, SIGNAL (visibilityChanged (bool)),
           this, SLOT(handle_visibility_changed (bool)));
/*
  connect (_workspace_model, SIGNAL (model_changed ()),
           this, SLOT (model_changed ()));
*/
  connect (_workspace_tree_view, SIGNAL (doubleClicked (QModelIndex)),
           this, SLOT (item_double_clicked (QModelIndex)));
  
  connect (_workspace_model, SIGNAL (dataChanged(QModelIndex,QModelIndex)),
	   this, SLOT (item_changed(QModelIndex, QModelIndex)));  
  
  connect (_scope_cb, SIGNAL (currentIndexChanged(int)),
	   this, SLOT (highlight_scope(int)));


}

workspace_view::~workspace_view ()
{
}

void
workspace_view::handle_visibility_changed (bool visible)
{
  if (visible)
    emit active_changed (true);
}

void 
workspace_view::update_scopes ()
{
  if (_scope_cb->count () != _workspace_model->get_scopes().length())
  {
  
    _scope_cb->clear ();
    int n = _workspace_model->get_scopes().length();
    for (int i=0; i < n; i++)
      _scope_cb->addItem (_workspace_model->get_scope_names().at (i)); 
    
    if (n > 0)
    {
      _scope_cb->setEnabled (true);
      _scope_label->setEnabled (true);
      _scope_cb->setCurrentIndex (0);
      //_workspace_model->set_current_scope (_workspace_model->get_scopes ().at (0));
      highlight_scope (0);
    }
    else
    {
      _scope_cb->setEnabled (false);
      _scope_label->setEnabled (false);
    }
  }
}

void
workspace_view::item_double_clicked (QModelIndex index)
{  
  _workspace_tree_view->setCurrentIndex (index.sibling(index.row(), 2));
}


void 
workspace_view::item_changed(QModelIndex index, QModelIndex other_index)
{
  
  Q_UNUSED (other_index);
  
  QString name = _workspace_model->itemData(index.sibling(index.row(), 0)).value(0).toString();
  QString type = _workspace_model->itemData(index.sibling(index.row(), 1)).value(0).toString();
  QString value = _workspace_model->itemData(index.sibling(index.row(), 2)).value(0).toString();
  
  if (!value.isEmpty())
  {
    QString cmd = name + "=" + type + "(" + value + ");";
    octave_link::instance()->post_event (new octave_run_command_event (*this, cmd.toStdString(), false, true));
    /*int parse_status;o
    eval_string (cmd.toStdString(), true, parse_status);
    rl_line_buffer[0] = '\0';
    rl_point = rl_end = 0;
    rl_done = 1;*/
  }
  
  _workspace_tree_view->setCurrentIndex (index);
}


void
workspace_view::closeEvent (QCloseEvent *event)
{
  emit active_changed (false);
  QDockWidget::closeEvent (event);
}

void 
workspace_view::highlight_scope(int s)
{
  QList<int> scopes = _workspace_model->get_scopes ();
  if (s < scopes.length () && s >= 0)
  {
    int scope_id = scopes.at (s);
    _workspace_model->set_current_scope (scope_id);
  }
}

void 
workspace_view::notice_settings()
{
  QSettings *settings = resource_manager::instance ()->get_settings ();
  QFont font = QFont();
  if (settings->value ("workspace/defaultFont").toBool())
  {
    font.setFamily (qApp->font().family ());
    font.setPointSize (qApp->font().pointSize ());
  }
  else
  {    
    font.setFamily(settings->value("workspace/fontName").toString());
    font.setPointSize(settings->value("workspace/fontSize").toInt ());
  }
  
  this->setFont (font);
}


void 
workspace_view::model_changed()
{
  //_workspace_tree_view->setCurrentIndex (_current_index);
}

void workspace_view::event_accepted(octave_event* e)
{
  delete e;
}

void workspace_view::event_reject(octave_event* e)
{
  delete e;
}


