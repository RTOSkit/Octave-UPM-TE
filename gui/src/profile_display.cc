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

#include "profile_display.h"

int profile_function::sortfield = 0;

bool profile_function::is_internal () const {
	bool is_internal = false;
	is_internal = is_internal || (type != "function" && type != "script");
	is_internal = is_internal || (QFileInfo(filename).suffix () == "oct");

	return is_internal;
};


profile_display::profile_display(QWidget *parent) :
    QDockWidget (parent)
{
	setObjectName ("ProfilerDockWidget");
	construct ();
}

profile_display::~profile_display()
{
}

void
profile_display::construct ()
{
	QVBoxLayout *layout = new QVBoxLayout ();
	_profile_label = new QLabel (tr ("No profile info available"), this);
	_profile_table = new QTableView (this);
	_model = new profile_model ();
	_profile_table->setModel (_model);
	_profile_table->setAlternatingRowColors (true);
	_profile_table->setSortingEnabled (true);
	_profile_table->horizontalHeader ()->setStretchLastSection (true);
	_profile_table->setSizePolicy (QSizePolicy::Expanding, QSizePolicy::Expanding);

	_profile_table->setSelectionMode (QAbstractItemView::SingleSelection);
	_profile_table->setSelectionBehavior (QAbstractItemView::SelectRows);

	layout->addWidget (_profile_label);
	layout->addWidget (_profile_table);

	setWindowTitle (tr ("Profiler"));
	setWidget (new QWidget ());
	widget()->setLayout (layout);
							   
	connect (_profile_table, SIGNAL (clicked (QModelIndex)),
		 this, SLOT (open_function (QModelIndex)));
}

void
profile_display::update_profiler_info (QString s)
{
	_model->update_model (_profile_info);
	_profile_label->setText (s);
	if (!isVisible())
		show();
}

void
profile_display::handle_visibility_changed (bool visible)
{
	if (visible)
		emit active_changed (true);
}

void
profile_display::closeEvent (QCloseEvent *event)
{
	emit active_changed (false);
	QDockWidget::closeEvent (event);
}

void
profile_display::open_function (const QModelIndex& index)
{
	int row = index.row ();
	int column = index.column ();

	const profile_function *f = _model->get_function (row);

	if (f->is_internal ())
		return;
	
	if (column == 1)
		emit open_file (f->filename);
}

profile_model::profile_model (QObject* parent) : QAbstractTableModel (parent)
{
}

profile_model::~profile_model ()
{
	foreach (profile_function *f, _functions)
		delete f;
	_functions.clear ();
}

void
profile_model::update_model (const octave_map &m)
{
	if (m.is_empty ())
		return;
	
	if (_profiler_mutex.tryLock ())
	{		
		beginResetModel ();
		octave_map function_table = m.getfield ("FunctionTable")(0).map_value();
		int n = function_table.length ();

		foreach (profile_function *f, _functions)
			delete f;
		_functions.clear ();

		QStringList names;
		
		for(int k=0; k < n; k++)
		{
			profile_function *f = new profile_function ();
			f->name = QString(octave_value(function_table.getfield("FunctionName")(k)).string_value ().c_str ());
			names << f->name;
			f->callorder = k+1;
			bool recursive = octave_value(function_table.getfield("IsRecursive")(k)).bool_value ();
			f->time = octave_value(function_table.getfield("TotalTime")(k)).double_value ();
			f->numcalls = octave_value(function_table.getfield("NumCalls")(k)).double_value ();

			QString recursiveStr;
			if (recursive)
				recursiveStr = tr("Yes");
			else
				recursiveStr = tr("No");
			f->recursive = recursiveStr;
 
			_functions.append (f);
		}

		check_functions (names);

		endResetModel ();
		_profiler_mutex.unlock ();
	}
}

void 
profile_model::check_functions (QStringList names)
{
	octave_value_list v;
	foreach (QString n, names)		
		v.append(n.toStdString ());

	v = feval("__which__", v, 1);
	octave_map m = v(0).map_value ();

	for (int k = 0; k < m.length (); k++)
	{
		octave_value fnv = m(k).getfield ("file");
		octave_value tv = m(k).getfield ("type");
		std::string fn;
		std::string type;

		if (!fnv.is_empty () && !tv.is_empty ())
		{
			fn = fnv.string_value ();
			type = tv.string_value ();
		}
		else
		{
			fn = "";
			type ="internal";
		}
		
		profile_function *f = _functions.at (k);
		f->filename = QString(fn.c_str ());
		f->type = QString(type.c_str ());
	}
}

int
profile_model::rowCount (const QModelIndex &parent) const
{
	Q_UNUSED (parent);	
	return _functions.size ();
}
						 
int
profile_model::columnCount (const QModelIndex& index) const
{
	Q_UNUSED (index);
	return 6;
}

QVariant
profile_model::data (const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant ();
	
	int row = index.row ();
	int column = index.column ();

	if (row > _functions.size ())
		return QVariant ();

	profile_function *f = _functions.at (row);
	
	switch (role)
	{
	case Qt::DisplayRole:


		switch (column) {
		case 0:
			return f->callorder;
			break;
		case 1:
			return f->name;
			break;
		case 2:
			return f->type;
			break;
		case 3:
			return QString("").sprintf("%.4f",f->time);
			break;
		case 4:
			return f->numcalls;
			break;
		case 5:
			return f->recursive;
			break;
		}
		break;
	case Qt::TextAlignmentRole:
		if (column == 0 || column == 3 || column == 4)
			return Qt::AlignRight + Qt::AlignVCenter;
		else
			return Qt::AlignCenter;		    
		break;

	case Qt::EditRole:
		return QVariant ();
		break;

        case Qt::ForegroundRole:
		switch (column) {
		case 1:
			if (!f->is_internal ())
				return Qt::blue;
			else
				return QVariant ();
		}
		break;

	case Qt::FontRole:
		switch (column) {
		case 1:
			if (!f->is_internal ())
			{
				QFont myFont;
				myFont.setUnderline (true);
				return myFont;
			}
			else
				return QVariant ();
		}
		break;	

	}

	return QVariant ();
}

QVariant
profile_model::headerData (int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal) {
			switch (section)
			{
			case 0:
				return QString("Call order");
			case 1:
				return QString("Name");
			case 2:
				return QString("Type");
			case 3:
				return QString("Time (sec)");
			case 4:
				return QString("Num. calls");
			case 5:
				return QString("Is recursive?");
			}
		}
	}
	return QVariant();
}

Qt::ItemFlags
profile_model::flags (const QModelIndex& index) const
{
	Q_UNUSED (index);
	return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}




bool
less_than (const profile_function* f1, const profile_function* f2)
{
	switch (f1->sortfield)
	{
	case 0:
		return f1->callorder <= f2->callorder;
	case 1:
		return f1->name <= f2->name;
	case 2:
		return f1->type <= f2->type;
	case 3:
		return f1->time <= f2->time;
	case 4:
		return f1->numcalls <= f2->numcalls;
	case 5:
		return f1->recursive <= f2->recursive;
	}

	return false;
}

bool
more_than (const profile_function *f1, const profile_function *f2)
{
	return !less_than (f1, f2);
}

void
profile_model::sort (int column, Qt::SortOrder order)
{
	if (_functions.length () == 0)
		return;
	
	profile_function *f = _functions.at (0);
	f->sortfield = column;
	
	beginResetModel ();
	if (order == Qt::AscendingOrder)
		qSort (_functions.begin (), _functions.end (), more_than);
	else
		qSort (_functions.begin (), _functions.end (), less_than);
	endResetModel ();
}
