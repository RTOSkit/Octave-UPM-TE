/****************************************************************************
** Meta object code from reading C++ file 'Emulation.h'
**
** Created: Fri Nov 1 20:06:56 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gui/qterminal/libqterminal/unix/Emulation.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Emulation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Emulation[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   11,   10,   10, 0x05,
      54,   46,   10,   10, 0x05,
      75,   10,   10,   10, 0x05,
     102,   96,   10,   10, 0x05,
     122,  116,   10,   10, 0x05,
     163,  153,   10,   10, 0x05,
     193,   10,   10,   10, 0x05,
     224,  209,   10,   10, 0x05,
     272,  250,   10,   10, 0x05,
     303,  298,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     355,  341,   10,   10, 0x0a,
     377,  298,   10,   10, 0x0a,
     395,   10,   10,   10, 0x0a,
     450,  420,   10,   10, 0x0a,
     496,  482,   10,   10, 0x0a,
     531,  524,   10,   10, 0x2a,
     566,  555,   10,   10, 0x0a,
     595,   10,   10,   10, 0x09,
     612,   10,   10,   10, 0x08,
     623,  153,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Emulation[] = {
    "Emulation\0\0data,len\0sendData(const char*,int)\0"
    "suspend\0lockPtyRequest(bool)\0"
    "useUtf8Request(bool)\0state\0stateSet(int)\0"
    "color\0changeTabTextColorRequest(int)\0"
    "usesMouse\0programUsesMouseChanged(bool)\0"
    "outputChanged()\0title,newTitle\0"
    "titleChanged(int,QString)\0"
    "lineCount,columnCount\0imageSizeChanged(int,int)\0"
    "text\0profileChangeCommandReceived(QString)\0"
    "lines,columns\0setImageSize(int,int)\0"
    "sendText(QString)\0sendKeyEvent(QKeyEvent*)\0"
    "buttons,column,line,eventType\0"
    "sendMouseEvent(int,int,int,int)\0"
    "string,length\0sendString(const char*,int)\0"
    "string\0sendString(const char*)\0"
    "buffer,len\0receiveData(const char*,int)\0"
    "bufferedUpdate()\0showBulk()\0"
    "usesMouseChanged(bool)\0"
};

void Emulation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Emulation *_t = static_cast<Emulation *>(_o);
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->lockPtyRequest((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->useUtf8Request((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->stateSet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->changeTabTextColorRequest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->programUsesMouseChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->outputChanged(); break;
        case 7: _t->titleChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->imageSizeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->profileChangeCommandReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->setImageSize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->sendText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->sendKeyEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 13: _t->sendMouseEvent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 14: _t->sendString((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->sendString((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 16: _t->receiveData((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->bufferedUpdate(); break;
        case 18: _t->showBulk(); break;
        case 19: _t->usesMouseChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Emulation::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Emulation::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Emulation,
      qt_meta_data_Emulation, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Emulation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Emulation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Emulation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Emulation))
        return static_cast<void*>(const_cast< Emulation*>(this));
    return QObject::qt_metacast(_clname);
}

int Emulation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void Emulation::sendData(const char * _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Emulation::lockPtyRequest(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Emulation::useUtf8Request(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Emulation::stateSet(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Emulation::changeTabTextColorRequest(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Emulation::programUsesMouseChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Emulation::outputChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void Emulation::titleChanged(int _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Emulation::imageSizeChanged(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Emulation::profileChangeCommandReceived(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
