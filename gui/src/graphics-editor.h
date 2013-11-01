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

#ifndef GRAPHICSEDITOR_H
#define GRAPHICSEDITOR_H

#include <QDialog>
#include <QColorDialog>
#include <QPushButton>
#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTemporaryFile>
#include <cstdio>

#include "octave_plot_properties.h"

namespace Ui {
class GraphicsEditor;
}

class GraphicsEditor : public QDialog
{
    Q_OBJECT

public:
    explicit GraphicsEditor(QWidget *parent = 0);
    ~GraphicsEditor();

    void recreate ();
    bool is_2d_plot () {return _props.is_2d_plot ();};


public slots:
    void apply_all_settings ();
    void set_plot_visible (const bool& v)  {_props.set_visible (v);};

private slots:

  void user_set_color_slot ();
  void user_set_plot_width (double d);
  void user_set_axis_width (double d);
  void update_plot_color ();
  void generate_preview ();
  void repaint_preview ();
  void toggle_grid ();
  void update_axis_font (int v);
  void user_set_plot_line (int t);
  void user_set_marker (int m);
  void user_set_marker_size (int s);

  void update_scene ();


  void resizeEvent (QResizeEvent*);
  void showEvent (QShowEvent *e);

  //void showLegendEditor ();

private:
  QColor pick_color (QColor c);



  Ui::GraphicsEditor *_ui;

  octave_plot_properties _props;
  std::string _preview_filename;
  QGraphicsScene *_scene;
  QGraphicsPixmapItem *_item;
  QPixmap _pixmap;
};


#endif // GRAPHICSEDITOR_H
