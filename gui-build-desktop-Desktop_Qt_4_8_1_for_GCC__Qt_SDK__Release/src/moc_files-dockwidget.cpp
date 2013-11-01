/****************************************************************************
** Meta object code from reading C++ file 'files-dockwidget.h'
**
** Created: Fri Nov 1 21:34:06 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gui/src/files-dockwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'files-dockwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_files_dock_widget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   19,   18,   18, 0x05,
      54,   47,   18,   18, 0x05,
      83,   75,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
     123,  117,   18,   18, 0x0a,
     156,   18,   18,   18, 0x0a,
     191,  174,   18,   18, 0x0a,
     222,   18,   18,   18, 0x0a,
     250,   18,   18,   18, 0x0a,
     276,  268,   18,   18, 0x0a,
     316,  308,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_files_dock_widget[] = {
    "files_dock_widget\0\0fileName\0"
    "open_file(QString)\0active\0"
    "active_changed(bool)\0dirName\0"
    "change_working_directory(QString)\0"
    "index\0item_double_clicked(QModelIndex)\0"
    "do_up_directory()\0currentDirectory\0"
    "set_current_directory(QString)\0"
    "current_directory_entered()\0"
    "notice_settings()\0visible\0"
    "handle_visibility_changed(bool)\0dirname\0"
    "on_working_dir_changed(QString)\0"
};

void files_dock_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        files_dock_widget *_t = static_cast<files_dock_widget *>(_o);
        switch (_id) {
        case 0: _t->open_file((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->active_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->change_working_directory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->item_double_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->do_up_directory(); break;
        case 5: _t->set_current_directory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->current_directory_entered(); break;
        case 7: _t->notice_settings(); break;
        case 8: _t->handle_visibility_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_working_dir_changed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData files_dock_widget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject files_dock_widget::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_files_dock_widget,
      qt_meta_data_files_dock_widget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &files_dock_widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *files_dock_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *files_dock_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_files_dock_widget))
        return static_cast<void*>(const_cast< files_dock_widget*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int files_dock_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void files_dock_widget::open_file(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void files_dock_widget::active_changed(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void files_dock_widget::change_working_directory(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
