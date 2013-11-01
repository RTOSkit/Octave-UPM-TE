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

#ifndef PROFILE_DISPLAY_H
#define PROFILE_DISPLAY_H

#include <QDockWidget>
#include <QTableWidgetItem>
#include <QMutex>
#include <QLabel>
#include <QVBoxLayout>
#include <QHeaderView>
#include "octave-adapter/octave-link.h"

class profile_model;

class profile_display : public QDockWidget
{
    Q_OBJECT
    
public:
    explicit profile_display(QWidget *parent = 0);
    ~profile_display();

    void set_profile_info (octave_map m) {_profile_info = m;};
    
public slots:

    void handle_visibility_changed (bool visible);
    void update_profiler_info (QString s);
    void open_function (const QModelIndex &index);

signals:
    void active_changed (bool active);
    void open_file (QString);

protected:
    void closeEvent (QCloseEvent *event);
    
private:

    void construct ();
    
    QLabel *_profile_label;
    QTableView *_profile_table;
    octave_map _profile_info;
    profile_model *_model;
};


class profile_function
{
public:
	profile_function () : callorder(0),
		name (),
		filename (),
		type (),
		time (0),
		numcalls (0),
		recursive ()
	{};

	int callorder;
	QString name;
	QString filename;
	QString type;
	double time;
	int numcalls;
	QString recursive;

	bool is_internal () const;
	

	static int sortfield;
	
};

class profile_model : public QAbstractTableModel
{
	Q_OBJECT

public:
	profile_model (QObject *parent = 0);
	~profile_model ();

	void update_model (const octave_map &m);

	QVariant data(const QModelIndex &index, int role) const;
	QVariant headerData (int section, Qt::Orientation Orientation, int role) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;

	Qt::ItemFlags flags (const QModelIndex &index) const;

	void sort (int column, Qt::SortOrder order);

	const profile_function * get_function (int k) { return _functions.at (k);};
	
private:

	void check_functions (QStringList names);

	QList<profile_function*> _functions;
	QMutex _profiler_mutex;
	  
};

#endif // PROFILE_DISPLAY_H
