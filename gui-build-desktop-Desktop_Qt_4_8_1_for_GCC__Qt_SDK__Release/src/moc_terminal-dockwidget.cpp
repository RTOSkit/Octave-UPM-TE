/****************************************************************************
** Meta object code from reading C++ file 'terminal-dockwidget.h'
**
** Created: Fri Nov 1 21:34:18 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gui/src/terminal-dockwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'terminal-dockwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_terminal_dock_widget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   22,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,   50,   21,   21, 0x0a,
      92,   90,   21,   21, 0x09,
     119,   90,   21,   21, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_terminal_dock_widget[] = {
    "terminal_dock_widget\0\0active\0"
    "active_changed(bool)\0visible\0"
    "handle_visibility_changed(bool)\0e\0"
    "focusInEvent(QFocusEvent*)\0"
    "closeEvent(QCloseEvent*)\0"
};

void terminal_dock_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        terminal_dock_widget *_t = static_cast<terminal_dock_widget *>(_o);
        switch (_id) {
        case 0: _t->active_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->handle_visibility_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->focusInEvent((*reinterpret_cast< QFocusEvent*(*)>(_a[1]))); break;
        case 3: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData terminal_dock_widget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject terminal_dock_widget::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_terminal_dock_widget,
      qt_meta_data_terminal_dock_widget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &terminal_dock_widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *terminal_dock_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *terminal_dock_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_terminal_dock_widget))
        return static_cast<void*>(const_cast< terminal_dock_widget*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int terminal_dock_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void terminal_dock_widget::active_changed(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
