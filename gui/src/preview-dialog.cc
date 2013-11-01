/* OctaveGUI - A graphical user interface for Octave
 * Copyright (C) 2013 Israel Herraiz <isra@herraiz.org>
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

#include "resource-manager.h"
#include "preview-dialog.h"
#include <cstdio>

preview_dialog::preview_dialog(QWidget* parent): QDialog(parent), _ui (new Ui_export_plot)
{
  _ui->setupUi (this);

  setWindowTitle (tr("Export plot"));

  _scene = new QGraphicsScene(_ui->graphicsView);
  _ui->graphicsView->setScene(_scene);

  _item = new QGraphicsPixmapItem ();

  connect (_scene,SIGNAL(changed(QList<QRectF>)), this, SLOT(update_scene()));
}

preview_dialog::~preview_dialog()
{
  remove(_preview_filename.toStdString().c_str());

  delete _item;
  delete _scene;
  delete _ui;
}


void preview_dialog::setPreviewFilename(QString f)
{
  _preview_filename = f;
   _pixmap = QPixmap(_preview_filename);

  _item->setPixmap (_pixmap);

  repaint_item ();
}


void preview_dialog::resizeEvent(QResizeEvent* e)
{
    QDialog::resizeEvent(e);

    repaint_item ();
}


void preview_dialog::showEvent(QShowEvent* e)
{
    QDialog::showEvent(e);

    repaint_item ();
}

void preview_dialog::repaint_item()
{
    int width = _ui->graphicsView->size().width();
    int height = _ui->graphicsView->size().height();

    if (_scene->items().length() > 0)
      _scene->removeItem (_item);

    //_item->setPixmap (_pixmap.scaled(width*.9, height*.9));
    _item->setPixmap (_pixmap.scaled(width-10, height-10,Qt::KeepAspectRatio));
    _scene->addItem (_item);
}

void preview_dialog::update_scene()
{
   _item->mapToScene (0,0);

    this->repaint();
}
