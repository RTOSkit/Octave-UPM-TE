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

#include "workspace-model.h"
#include <QTreeWidget>
#include "octave-link.h"

workspace_model::workspace_model(QObject *parent)
  : QAbstractItemModel(parent)
{
  QList<QVariant> rootData;
  rootData << tr ("Name") << tr ("Type") << tr ("Value");
  _rootItem = new tree_item(rootData);

  _scopes.clear ();
  _scope_names.clear ();
  _current_scope = -1;
}



workspace_model::~workspace_model()
{
  delete _rootItem;
}

void
workspace_model::update_model (const QList<symbol_information> &symbols)
{
  if(_mutex.tryLock())
  {
  beginResetModel();
  _rootItem->delete_child_items ();

  foreach (const symbol_information& s, symbols)
    {
      tree_item *child = new tree_item ();

      /*
      child->set_data (0, s.getSymbol ());
      child->set_data (1, s.getType ());
      child->set_data (2, s.getValue ());
      child->setEditable (s.isEditable());
      */
      child->import_from_symbol (s);

      if (!s.isHidden ())
	    _rootItem->add_child (child);
    }

  endResetModel();
  _mutex.unlock ();
  //emit model_changed();
  }
}

QModelIndex
workspace_model::index(int row, int column, const QModelIndex &parent) const
{
  if (!hasIndex(row, column, parent))
    return QModelIndex();

  tree_item *parentItem;

  if (!parent.isValid())
    parentItem = _rootItem;
  else
    parentItem = static_cast<tree_item*>(parent.internalPointer());

  tree_item *childItem = parentItem->child(row);
  if (childItem)
    return createIndex(row, column, childItem);
  else
    return QModelIndex();
}

QModelIndex
workspace_model::parent(const QModelIndex &index) const
{
  Q_UNUSED (index);
  return QModelIndex ();
  /*
  if (!index.isValid())
    return QModelIndex();

  tree_item *childItem = static_cast<tree_item*>(index.internalPointer());
  tree_item *parentItem = childItem->parent();

  if (parentItem == _rootItem)
    return QModelIndex();

  return createIndex(parentItem->row(), 0, parentItem);
  */
}

int
workspace_model::rowCount(const QModelIndex &parent) const
{
  tree_item *parentItem;
  if (parent.column() > 0)
    return 0;

  if (!parent.isValid())
    parentItem = _rootItem;
  else
    parentItem = static_cast<tree_item*>(parent.internalPointer());

  return parentItem->child_count();
}


int
workspace_model::columnCount(const QModelIndex &parent) const
{
  if (parent.isValid())
    return static_cast<tree_item*>(parent.internalPointer())->column_count();
  else
    return _rootItem->column_count();
}

void
workspace_model::insert_top_level_item(int at, tree_item *treeItem)
{
  _rootItem->insert_child_item(at, treeItem);
}

tree_item *
workspace_model::top_level_item (int at)
{
  return _rootItem->child(at);
}

Qt::ItemFlags
workspace_model::flags(const QModelIndex &index) const
{
  if (!index.isValid())
    return 0;

  tree_item *item = static_cast<tree_item*>(index.internalPointer());

  if (index.column() == 2 && item->isEditable())
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;

  return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant
workspace_model::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    return _rootItem->data(section);

  return QVariant();
}

QVariant
workspace_model::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();

  tree_item *item = static_cast<tree_item*>(index.internalPointer());

  if (role == Qt::EditRole)
      return item->data (2);

  if (role != Qt::DisplayRole)
    return QVariant();

  return item->data(index.column());
}


bool
workspace_model::setData(const QModelIndex& index, const QVariant& value, int role)
{
  if (role != Qt::EditRole)
    return false;

  tree_item *item = static_cast<tree_item*>(index.internalPointer());
  item->set_data(2, value.toString());

  emit dataChanged (index, index);

  return true;
}

