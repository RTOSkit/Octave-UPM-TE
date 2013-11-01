/****************************************************************************
** Meta object code from reading C++ file 'history-dockwidget.h'
**
** Created: Fri Nov 1 21:34:01 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gui/src/history-dockwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'history-dockwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_history_dock_widget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   21,   20,   20, 0x05,
      68,   61,   20,   20, 0x05,
      89,   20,   20,   20, 0x05,
     105,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
     129,  121,   20,   20, 0x0a,
     161,   20,   20,   20, 0x0a,
     192,   20,   20,   20, 0x0a,
     209,   20,   20,   20, 0x0a,
     236,   20,   20,   20, 0x0a,
     265,  254,   20,   20, 0x08,
     300,  298,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_history_dock_widget[] = {
    "history_dock_widget\0\0command\0"
    "command_double_clicked(QString)\0active\0"
    "active_changed(bool)\0load_finished()\0"
    "restart_timer()\0visible\0"
    "handle_visibility_changed(bool)\0"
    "request_history_model_update()\0"
    "copy_selection()\0item_selected(QModelIndex)\0"
    "notice_settings()\0modelIndex\0"
    "handle_double_click(QModelIndex)\0,\0"
    "update_scroll(QModelIndex,QModelIndex)\0"
};

void history_dock_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        history_dock_widget *_t = static_cast<history_dock_widget *>(_o);
        switch (_id) {
        case 0: _t->command_double_clicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->active_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->load_finished(); break;
        case 3: _t->restart_timer(); break;
        case 4: _t->handle_visibility_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->request_history_model_update(); break;
        case 6: _t->copy_selection(); break;
        case 7: _t->item_selected((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 8: _t->notice_settings(); break;
        case 9: _t->handle_double_click((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 10: _t->update_scroll((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData history_dock_widget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject history_dock_widget::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_history_dock_widget,
      qt_meta_data_history_dock_widget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &history_dock_widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *history_dock_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *history_dock_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_history_dock_widget))
        return static_cast<void*>(const_cast< history_dock_widget*>(this));
    if (!strcmp(_clname, "octave_event_observer"))
        return static_cast< octave_event_observer*>(const_cast< history_dock_widget*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int history_dock_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void history_dock_widget::command_double_clicked(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void history_dock_widget::active_changed(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void history_dock_widget::load_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void history_dock_widget::restart_timer()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
