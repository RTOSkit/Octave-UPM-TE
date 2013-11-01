/****************************************************************************
** Meta object code from reading C++ file 'QUnixTerminalImpl.h'
**
** Created: Fri Nov 1 20:06:58 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gui/qterminal/libqterminal/unix/QUnixTerminalImpl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QUnixTerminalImpl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QUnixTerminalImpl[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x0a,
      35,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QUnixTerminalImpl[] = {
    "QUnixTerminalImpl\0\0copyClipboard()\0"
    "pasteClipboard()\0"
};

void QUnixTerminalImpl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QUnixTerminalImpl *_t = static_cast<QUnixTerminalImpl *>(_o);
        switch (_id) {
        case 0: _t->copyClipboard(); break;
        case 1: _t->pasteClipboard(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QUnixTerminalImpl::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QUnixTerminalImpl::staticMetaObject = {
    { &QTerminalInterface::staticMetaObject, qt_meta_stringdata_QUnixTerminalImpl,
      qt_meta_data_QUnixTerminalImpl, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QUnixTerminalImpl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QUnixTerminalImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QUnixTerminalImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QUnixTerminalImpl))
        return static_cast<void*>(const_cast< QUnixTerminalImpl*>(this));
    return QTerminalInterface::qt_metacast(_clname);
}

int QUnixTerminalImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTerminalInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
