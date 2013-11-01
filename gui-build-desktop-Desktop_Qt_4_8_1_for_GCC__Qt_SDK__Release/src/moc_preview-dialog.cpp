/****************************************************************************
** Meta object code from reading C++ file 'preview-dialog.h'
**
** Created: Fri Nov 1 21:34:11 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gui/src/preview-dialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'preview-dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_preview_dialog[] = {

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
      16,   15,   15,   15, 0x0a,
      45,   43,   15,   15, 0x0a,
      68,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_preview_dialog[] = {
    "preview_dialog\0\0resizeEvent(QResizeEvent*)\0"
    "e\0showEvent(QShowEvent*)\0update_scene()\0"
};

void preview_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        preview_dialog *_t = static_cast<preview_dialog *>(_o);
        switch (_id) {
        case 0: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 1: _t->showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        case 2: _t->update_scene(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData preview_dialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject preview_dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_preview_dialog,
      qt_meta_data_preview_dialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &preview_dialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *preview_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *preview_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_preview_dialog))
        return static_cast<void*>(const_cast< preview_dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int preview_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
