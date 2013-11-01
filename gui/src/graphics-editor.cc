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

#include "graphics-editor.h"
#include "ui_graphics-editor.h"

GraphicsEditor::GraphicsEditor(QWidget *parent) :
    QDialog(parent),
    _ui(new Ui::GraphicsEditor),
    _props(),
    _preview_filename()
{
    setWindowTitle (tr("Graphics editor"));

    QTemporaryFile f;
    f.setAutoRemove (true);
    f.open();
    _preview_filename = f.fileName ().toStdString ();
    _preview_filename.append(".png");

    _ui->setupUi(this);

    connect (_ui->xcolor, SIGNAL (pressed()), this, SLOT (user_set_color_slot()));
    connect (_ui->ycolor, SIGNAL(pressed()), this, SLOT(user_set_color_slot()));
    connect (_ui->plotColor, SIGNAL(pressed()), this, SLOT(user_set_color_slot()));
    connect (_ui->buttonBox->button(QDialogButtonBox::Apply), SIGNAL(pressed()), this, SLOT(apply_all_settings()));
    connect (_ui->plotComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(update_plot_color()));
    connect (_ui->plotWidth, SIGNAL(valueChanged(double)), this, SLOT(user_set_plot_width(double)));
    connect (_ui->axisWidth, SIGNAL(valueChanged(double)), this, SLOT(user_set_axis_width(double)));
    connect (_ui->toggleGrid, SIGNAL(pressed()), this, SLOT(toggle_grid()));
    connect (_ui->axisFontSize, SIGNAL(valueChanged(int)), this, SLOT(update_axis_font(int)));
    connect (_ui->axisFontWeight, SIGNAL(currentIndexChanged(int)), this, SLOT(update_axis_font(int)));
    connect (_ui->plotLine, SIGNAL(currentIndexChanged(int)), this, SLOT(user_set_plot_line(int)));
    connect (_ui->markerType, SIGNAL(currentIndexChanged(int)), this, SLOT(user_set_marker(int)));
    connect (_ui->markerSize, SIGNAL(valueChanged(int)), this, SLOT(user_set_marker_size(int)));
    //connect (_ui->editLegend, SIGNAL(pressed()), this, SLOT(showLegendEditor()));

    _scene = new QGraphicsScene(_ui->graphicsView);
    _ui->graphicsView->setScene(_scene);

    _item = new QGraphicsPixmapItem ();

    connect (_scene,SIGNAL(changed(QList<QRectF>)), this, SLOT(update_scene()));
}

void GraphicsEditor::recreate()
{
    _props.read_from_octave ();

    _ui->axisWidth->setValue (_props.get_axis_width ());

    // Set plot lines color button
    const std::vector<plot_line*> v = _props.get_plot_lines ();

    if (v.empty ())
      _ui->plotAllBox->setEnabled (false);
    else
    {
      _ui->plotAllBox->setEnabled (true);

      _ui->plotComboBox->blockSignals (true);
      _ui->plotComboBox->clear();
      for (size_t i = 0; i < v.size (); i++)
      {
	_ui->plotComboBox->addItem (QString("Series %1").arg (i+1));
      }
      _ui->plotComboBox->blockSignals (false);

      update_plot_color ();
    }


    _ui->axisFontSize->setValue (_props.get_axis_fontsize ());
    _ui->axisWidth->setValue (_props.get_axis_width ());
    const int *xcolor = _props.get_xcolor ();
    int r = xcolor[0];
    int g = xcolor[1];
    int b = xcolor[2];
    _ui->xcolor->setPalette(QPalette(QColor(r,g,b)));
    const int *ycolor = _props.get_ycolor();
    r = ycolor[0];
    g = ycolor[1];
    b = ycolor[2];
    _ui->ycolor->setPalette(QPalette(QColor(r,g,b)));


    if (_props.get_axis_fontweight() == "normal")
      _ui->axisFontWeight->setCurrentIndex (0);
    else
      _ui->axisFontWeight->setCurrentIndex (1);

    generate_preview ();
}

GraphicsEditor::~GraphicsEditor()
{
    remove (_preview_filename.c_str ());

    delete _ui;
}

void GraphicsEditor::update_plot_color()
{
  if (_props.get_plot_lines().size() == 0 || _ui->plotComboBox->count() == 0)
    return;

  plot_line *p = _props.get_plot_lines().at (_ui->plotComboBox->currentIndex());

  _ui->plotWidth->setValue (p->get_width ());
  _ui->plotLine->setCurrentIndex (p->get_type ());
  _ui->markerSize->setValue (p->get_marker_size ());
  _ui->markerType->setCurrentIndex (p->get_marker ());

    const int *color = p->get_color ();
    int r = color[0];
    int g = color[1];
    int b = color[2];
    _ui->plotColor->setPalette(QPalette(QColor(r,g,b)));
}


void GraphicsEditor::user_set_color_slot()
{
  QPushButton *o = qobject_cast< QPushButton* >(QObject::sender());


  QColor c = pick_color (o->palette().color(QPalette::Background));
  o->setPalette (QPalette(c));


  // Set property in Octave
  if (o == _ui->plotColor)
  {
    size_t k = _ui->plotComboBox->currentIndex();
    plot_line *p = _props.get_plot_lines ().at (k);
    p->set_color (c.red (), c.green (), c.blue ());
    return;
  }

  if (o == _ui->xcolor)
  {
    _props.set_xcolor (c.red(), c.green(), c.blue ());
    return;
  }

  if (o == _ui->ycolor)
  {
    _props.set_ycolor (c.red (), c.green(), c.blue());
    return;
  }

}


QColor GraphicsEditor::pick_color(QColor c = QColor())
{
  QColorDialog *d = new QColorDialog (this);
  d->setCurrentColor (c);
  d->setModal (true);

  if (d->exec () == QDialog::Accepted)
    return d->currentColor ();

  delete d;

  return c;
}

void GraphicsEditor::apply_all_settings()
{
  _props.set_in_octave ();
  generate_preview ();
}

void GraphicsEditor::generate_preview()
{
  octave_value_list gcf = feval("gcf", octave_value_list (), 1);
  octave_value_list saveargs;
  saveargs.append(gcf(0));
  saveargs.append(_preview_filename);
  saveargs.append("png");
  feval("saveas", saveargs, 0);

  _pixmap = QPixmap(QString::fromStdString(_preview_filename));

  _item->setPixmap (_pixmap);

  repaint_preview ();
}

void GraphicsEditor::repaint_preview()
{
    int width = _ui->graphicsView->size().width();
    int height = _ui->graphicsView->size().height();


    if (_scene->items().length() > 0)
          _scene->removeItem(_item);


    _item->setPixmap (_pixmap.scaled(width-10, height-10,Qt::KeepAspectRatio));
    _scene->addItem (_item);
}

void GraphicsEditor::resizeEvent(QResizeEvent* e)
{
    QDialog::resizeEvent(e);

    repaint_preview ();
}


void GraphicsEditor::showEvent(QShowEvent* e)
{
    QDialog::showEvent(e);

    repaint_preview ();
}

void GraphicsEditor::user_set_plot_width(double d)
{
  if (_props.get_plot_lines().size() == 0 || _ui->plotComboBox->count() == 0)
    return;

  plot_line *p = _props.get_plot_lines().at (_ui->plotComboBox->currentIndex());
  p->set_width (d);
}

void GraphicsEditor::user_set_axis_width(double d)
{
  _props.set_axis_wdith (d);
}

void GraphicsEditor::toggle_grid()
{
  bool minor = _ui->showGridMinor->isChecked ();
  _props.toggle_grid (minor);
  generate_preview ();
}

void GraphicsEditor::update_axis_font(int v)
{
  if(QComboBox *c = qobject_cast< QComboBox* >(QObject::sender()))
  {
    Q_UNUSED(c);

    if (v == 1)
      _props.set_axis_fontweight ("bold");
    else
      _props.set_axis_fontweight ("normal");
  }
  else if (QSpinBox * c = qobject_cast< QSpinBox* >(QObject::sender()))
  {
      Q_UNUSED(c);
      _props.set_axis_fontsize (v);
  }


}

void GraphicsEditor::user_set_plot_line(int t)
{
    if (_props.get_plot_lines().size() == 0 || _ui->plotComboBox->count() == 0)
    return;

  plot_line *p = _props.get_plot_lines().at (_ui->plotComboBox->currentIndex());
  p->set_type (t);
}

void GraphicsEditor::user_set_marker(int m)
{
  if (_props.get_plot_lines().size() == 0 || _ui->plotComboBox->count() == 0)
    return;

  plot_line *p = _props.get_plot_lines().at (_ui->plotComboBox->currentIndex());
  p->set_marker (m);
}

void GraphicsEditor::user_set_marker_size(int s)
{

  if (_props.get_plot_lines().size() == 0 || _ui->plotComboBox->count() == 0)
    return;

  plot_line *p = _props.get_plot_lines().at (_ui->plotComboBox->currentIndex());
  p->set_marker_size (s);
}

void GraphicsEditor::update_scene()
{
    _item->mapToScene (0,0);

    this->repaint();
}

/*
void GraphicsEditor::showLegendEditor()
{
  legend_editor *e = new legend_editor (this);
  e->set_plot_properties(&_props);

  if (e->exec () == QDialog::Accepted)
    this->repaint_preview();
  delete e;
}
*/


