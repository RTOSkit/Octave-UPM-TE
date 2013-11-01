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


#ifndef DOC_VIEWER_H
#define DOC_VIEWER_H_H

#include <QMainWindow>
#include <QVBoxLayout>
#include "doc-viewer/webinfo.h"

class doc_viewer : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit doc_viewer(QWidget *parent = 0);
    ~doc_viewer();

    void set_infofile (const QString& i);

    void show_help_browser ();
protected:
    void closeEvent (QCloseEvent *event);
    
private:
    void construct ();
    
    WebInfo *_info_widget;
    QString _infofile;
};


#endif // DOC_VIEWER_H
