/****************************************************************************
** Meta object code from reading C++ file 'profile_display.h'
**
** Created: Fri Nov 1 21:34:25 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gui/src/profile_display.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'profile_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_profile_display[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   17,   16,   16, 0x05,
      45,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      72,   64,   16,   16, 0x0a,
     106,  104,   16,   16, 0x0a,
     142,  136,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_profile_display[] = {
    "profile_display\0\0active\0active_changed(bool)\0"
    "open_file(QString)\0visible\0"
    "handle_visibility_changed(bool)\0s\0"
    "update_profiler_info(QString)\0index\0"
    "open_function(QModelIndex)\0"
};

void profile_display::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        profile_display *_t = static_cast<profile_display *>(_o);
        switch (_id) {
        case 0: _t->active_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->open_file((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->handle_visibility_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->update_profiler_info((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->open_function((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData profile_display::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject profile_display::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_profile_display,
      qt_meta_data_profile_display, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &profile_display::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *profile_display::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *profile_display::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_profile_display))
        return static_cast<void*>(const_cast< profile_display*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int profile_display::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void profile_display::active_changed(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void profile_display::open_file(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
static const uint qt_meta_data_profile_model[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_profile_model[] = {
    "profile_model\0"
};

void profile_model::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData profile_model::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject profile_model::staticMetaObject = {
    { &QAbstractTableModel::staticMetaObject, qt_meta_stringdata_profile_model,
      qt_meta_data_profile_model, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &profile_model::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *profile_model::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *profile_model::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_profile_model))
        return static_cast<void*>(const_cast< profile_model*>(this));
    return QAbstractTableModel::qt_metacast(_clname);
}

int profile_model::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
