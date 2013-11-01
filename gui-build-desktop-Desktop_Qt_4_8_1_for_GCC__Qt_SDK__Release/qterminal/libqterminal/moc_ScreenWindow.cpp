/****************************************************************************
** Meta object code from reading C++ file 'ScreenWindow.h'
**
** Created: Fri Nov 1 20:07:01 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gui/qterminal/libqterminal/unix/ScreenWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ScreenWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ScreenWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      35,   30,   13,   13, 0x05,
      49,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ScreenWindow[] = {
    "ScreenWindow\0\0outputChanged()\0line\0"
    "scrolled(int)\0selectionChanged()\0"
    "notifyOutputChanged()\0"
};

void ScreenWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ScreenWindow *_t = static_cast<ScreenWindow *>(_o);
        switch (_id) {
        case 0: _t->outputChanged(); break;
        case 1: _t->scrolled((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->selectionChanged(); break;
        case 3: _t->notifyOutputChanged(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ScreenWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ScreenWindow::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ScreenWindow,
      qt_meta_data_ScreenWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ScreenWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ScreenWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ScreenWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScreenWindow))
        return static_cast<void*>(const_cast< ScreenWindow*>(this));
    return QObject::qt_metacast(_clname);
}

int ScreenWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ScreenWindow::outputChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ScreenWindow::scrolled(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ScreenWindow::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
