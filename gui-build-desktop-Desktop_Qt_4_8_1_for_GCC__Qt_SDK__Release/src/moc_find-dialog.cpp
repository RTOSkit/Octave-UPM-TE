/****************************************************************************
** Meta object code from reading C++ file 'find-dialog.h'
**
** Created: Fri Nov 1 21:33:46 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gui/src/m-editor/find-dialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'find-dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_find_dialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      27,   12,   12,   12, 0x08,
      37,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_find_dialog[] = {
    "find_dialog\0\0search_next()\0replace()\0"
    "replace_all()\0"
};

void find_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        find_dialog *_t = static_cast<find_dialog *>(_o);
        switch (_id) {
        case 0: _t->search_next(); break;
        case 1: _t->replace(); break;
        case 2: _t->replace_all(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData find_dialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject find_dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_find_dialog,
      qt_meta_data_find_dialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &find_dialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *find_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *find_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_find_dialog))
        return static_cast<void*>(const_cast< find_dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int find_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
