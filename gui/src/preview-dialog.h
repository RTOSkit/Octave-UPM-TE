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
 *md5

 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PREVIEWDIALOG_H
#define PREVIEWDIALOG_H

#include <QDialog>
#include "ui_export-plot.h"
#include <qgraphicsitem.h>

namespace Ui
{
  class preview_dialog;
}

class preview_dialog:public QDialog
{
Q_OBJECT public:
  explicit preview_dialog (QWidget * parent);

  ~preview_dialog();

  QString getFilename () const { return _ui->filenameEdit->text();};
  int getExtension () const {return _ui->formatCombo->currentIndex();};

  void setPreviewFilename (QString);


public slots:

  void resizeEvent (QResizeEvent*);
  void showEvent (QShowEvent *e);

private slots:

  void update_scene ();


private:

   void repaint_item ();


   Ui_export_plot *_ui;
   QString _preview_filename;

   QGraphicsScene *_scene;
   QGraphicsPixmapItem *_item;
   QPixmap _pixmap;

};

#endif // PREVIEWDIALOG_H
