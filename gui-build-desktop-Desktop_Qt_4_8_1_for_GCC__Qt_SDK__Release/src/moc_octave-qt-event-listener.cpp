/****************************************************************************
** Meta object code from reading C++ file 'octave-qt-event-listener.h'
**
** Created: Fri Nov 1 21:34:20 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gui/src/octave-qt-event-listener.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'octave-qt-event-listener.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_octave_qt_event_listener[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      36,   26,   25,   25, 0x05,
      82,   25,   25,   25, 0x05,
     110,   25,   25,   25, 0x05,
     135,   25,   25,   25, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_octave_qt_event_listener[] = {
    "octave_qt_event_listener\0\0directory\0"
    "current_directory_has_changed_signal(QString)\0"
    "entered_debug_mode_signal()\0"
    "quit_debug_mode_signal()\0"
    "debugging_in_progress()\0"
};

void octave_qt_event_listener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        octave_qt_event_listener *_t = static_cast<octave_qt_event_listener *>(_o);
        switch (_id) {
        case 0: _t->current_directory_has_changed_signal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->entered_debug_mode_signal(); break;
        case 2: _t->quit_debug_mode_signal(); break;
        case 3: _t->debugging_in_progress(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData octave_qt_event_listener::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject octave_qt_event_listener::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_octave_qt_event_listener,
      qt_meta_data_octave_qt_event_listener, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &octave_qt_event_listener::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *octave_qt_event_listener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *octave_qt_event_listener::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_octave_qt_event_listener))
        return static_cast<void*>(const_cast< octave_qt_event_listener*>(this));
    if (!strcmp(_clname, "octave_event_listener"))
        return static_cast< octave_event_listener*>(const_cast< octave_qt_event_listener*>(this));
    return QObject::qt_metacast(_clname);
}

int octave_qt_event_listener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void octave_qt_event_listener::current_directory_has_changed_signal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void octave_qt_event_listener::entered_debug_mode_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void octave_qt_event_listener::quit_debug_mode_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void octave_qt_event_listener::debugging_in_progress()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
