/****************************************************************************
** Meta object code from reading C++ file 'TerminalModel.h'
**
** Created: Fri Nov 1 20:07:04 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gui/qterminal/libqterminal/unix/TerminalModel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TerminalModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TerminalModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       2,  124, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      25,   14,   14,   14, 0x05,
      41,   36,   14,   14, 0x05,
      63,   14,   14,   14, 0x05,
      86,   78,   14,   14, 0x05,
     116,  110,   14,   14, 0x05,
     142,  134,   14,   14, 0x05,
     163,   14,   14,   14, 0x05,
     194,   14,   14,   14, 0x05,
     235,  231,   14,   14, 0x05,
     264,  259,   14,   14, 0x05,
     285,   36,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     323,   14,   14,   14, 0x0a,
     329,   14,   14,   14, 0x0a,
     337,   14,   14,   14, 0x08,
     358,  347,   14,   14, 0x08,
     390,   14,   14,   14, 0x08,
     422,  409,   14,   14, 0x08,
     462,  448,   14,   14, 0x08,
     493,   14,   14,   14, 0x08,
     520,  515,   14,   14, 0x08,
     552,  544,   14,   14, 0x08,

 // properties: name, type, flags
     586,  578, 0x0a095103,
     259,  598, 0x15095103,

       0        // eod
};

static const char qt_meta_stringdata_TerminalModel[] = {
    "TerminalModel\0\0started()\0finished()\0"
    "text\0receivedData(QString)\0titleChanged()\0"
    "profile\0profileChanged(QString)\0state\0"
    "stateChanged(int)\0message\0"
    "bellRequest(QString)\0"
    "changeTabTextColorRequest(int)\0"
    "changeBackgroundColorRequest(QColor)\0"
    "url\0openUrlRequest(QString)\0size\0"
    "resizeRequest(QSize)\0"
    "profileChangeCommandReceived(QString)\0"
    "run()\0close()\0done(int)\0buffer,len\0"
    "onReceiveBlock(const char*,int)\0"
    "monitorTimerDone()\0height,width\0"
    "onViewSizeChange(int,int)\0lines,columns\0"
    "onEmulationSizeChange(int,int)\0"
    "activityStateSet(int)\0view\0"
    "viewDestroyed(QObject*)\0buf,len\0"
    "sendData(const char*,int)\0QString\0"
    "keyBindings\0QSize\0"
};

void TerminalModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TerminalModel *_t = static_cast<TerminalModel *>(_o);
        switch (_id) {
        case 0: _t->started(); break;
        case 1: _t->finished(); break;
        case 2: _t->receivedData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->titleChanged(); break;
        case 4: _t->profileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->bellRequest((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->changeTabTextColorRequest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->changeBackgroundColorRequest((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 9: _t->openUrlRequest((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->resizeRequest((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 11: _t->profileChangeCommandReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->run(); break;
        case 13: _t->close(); break;
        case 14: _t->done((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->onReceiveBlock((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->monitorTimerDone(); break;
        case 17: _t->onViewSizeChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 18: _t->onEmulationSizeChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 19: _t->activityStateSet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->viewDestroyed((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 21: _t->sendData((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TerminalModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TerminalModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TerminalModel,
      qt_meta_data_TerminalModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TerminalModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TerminalModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TerminalModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TerminalModel))
        return static_cast<void*>(const_cast< TerminalModel*>(this));
    return QObject::qt_metacast(_clname);
}

int TerminalModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = keyBindings(); break;
        case 1: *reinterpret_cast< QSize*>(_v) = size(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setKeyBindings(*reinterpret_cast< QString*>(_v)); break;
        case 1: setSize(*reinterpret_cast< QSize*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void TerminalModel::started()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void TerminalModel::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void TerminalModel::receivedData(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TerminalModel::titleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void TerminalModel::profileChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TerminalModel::stateChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TerminalModel::bellRequest(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TerminalModel::changeTabTextColorRequest(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void TerminalModel::changeBackgroundColorRequest(const QColor & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void TerminalModel::openUrlRequest(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void TerminalModel::resizeRequest(const QSize & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void TerminalModel::profileChangeCommandReceived(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_END_MOC_NAMESPACE
