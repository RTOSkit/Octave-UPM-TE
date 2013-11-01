/****************************************************************************
** Meta object code from reading C++ file 'Vt102Emulation.h'
**
** Created: Fri Nov 1 20:07:02 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gui/qterminal/libqterminal/unix/Vt102Emulation.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Vt102Emulation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Vt102Emulation[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   16,   15,   15, 0x0a,
      52,   15,   15,   15, 0x2a,
      81,   76,   15,   15, 0x0a,
      99,   15,   15,   15, 0x0a,
     154,  124,   15,   15, 0x0a,
     186,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Vt102Emulation[] = {
    "Vt102Emulation\0\0,length\0"
    "sendString(const char*,int)\0"
    "sendString(const char*)\0text\0"
    "sendText(QString)\0sendKeyEvent(QKeyEvent*)\0"
    "buttons,column,line,eventType\0"
    "sendMouseEvent(int,int,int,int)\0"
    "updateTitle()\0"
};

void Vt102Emulation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Vt102Emulation *_t = static_cast<Vt102Emulation *>(_o);
        switch (_id) {
        case 0: _t->sendString((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->sendString((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 2: _t->sendText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->sendKeyEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 4: _t->sendMouseEvent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 5: _t->updateTitle(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Vt102Emulation::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Vt102Emulation::staticMetaObject = {
    { &Emulation::staticMetaObject, qt_meta_stringdata_Vt102Emulation,
      qt_meta_data_Vt102Emulation, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Vt102Emulation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Vt102Emulation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Vt102Emulation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Vt102Emulation))
        return static_cast<void*>(const_cast< Vt102Emulation*>(this));
    return Emulation::qt_metacast(_clname);
}

int Vt102Emulation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Emulation::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
