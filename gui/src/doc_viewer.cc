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

#include "doc_viewer.h"

doc_viewer::doc_viewer (QWidget *parent) : QMainWindow (parent)
{
	setObjectName ("DocViewerDialog");
	construct ();
}

doc_viewer::~doc_viewer ()
{
	delete _info_widget;
}

void doc_viewer::closeEvent (QCloseEvent *event)
{
	QMainWindow::closeEvent (event);
}

void doc_viewer::construct ()
{

	_info_widget = new WebInfo();
	setCentralWidget (_info_widget);

	resize(700,700);
}

void doc_viewer::set_infofile (const QString& i)
{
	_infofile = i;
}

void doc_viewer::show_help_browser ()
{
	show ();
	_info_widget->setInfoPath (_infofile);
}
