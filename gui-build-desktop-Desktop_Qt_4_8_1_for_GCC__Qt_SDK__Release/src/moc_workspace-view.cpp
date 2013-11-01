/****************************************************************************
** Meta object code from reading C++ file 'workspace-view.h'
**
** Created: Fri Nov 1 21:33:53 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gui/src/workspace-view.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'workspace-view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_workspace_view[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   44,   15,   15, 0x0a,
     101,   15,   84,   15, 0x0a,
     115,  113,   15,   15, 0x0a,
     136,   15,   15,   15, 0x0a,
     154,  152,   15,   15, 0x0a,
     184,  152,   15,   15, 0x0a,
     212,   15,   15,   15, 0x0a,
     236,  230,   15,   15, 0x09,
     287,  269,   15,   15, 0x09,
     325,   15,   15,   15, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_workspace_view[] = {
    "workspace_view\0\0active\0active_changed(bool)\0"
    "visible\0handle_visibility_changed(bool)\0"
    "workspace_model*\0get_model()\0s\0"
    "highlight_scope(int)\0update_scopes()\0"
    "e\0event_accepted(octave_event*)\0"
    "event_reject(octave_event*)\0"
    "notice_settings()\0index\0"
    "item_double_clicked(QModelIndex)\0"
    "index,other_index\0"
    "item_changed(QModelIndex,QModelIndex)\0"
    "model_changed()\0"
};

void workspace_view::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        workspace_view *_t = static_cast<workspace_view *>(_o);
        switch (_id) {
        case 0: _t->active_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->handle_visibility_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: { workspace_model* _r = _t->get_model();
            if (_a[0]) *reinterpret_cast< workspace_model**>(_a[0]) = _r; }  break;
        case 3: _t->highlight_scope((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->update_scopes(); break;
        case 5: _t->event_accepted((*reinterpret_cast< octave_event*(*)>(_a[1]))); break;
        case 6: _t->event_reject((*reinterpret_cast< octave_event*(*)>(_a[1]))); break;
        case 7: _t->notice_settings(); break;
        case 8: _t->item_double_clicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 9: _t->item_changed((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 10: _t->model_changed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData workspace_view::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject workspace_view::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_workspace_view,
      qt_meta_data_workspace_view, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &workspace_view::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *workspace_view::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *workspace_view::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_workspace_view))
        return static_cast<void*>(const_cast< workspace_view*>(this));
    if (!strcmp(_clname, "octave_event_observer"))
        return static_cast< octave_event_observer*>(const_cast< workspace_view*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int workspace_view::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void workspace_view::active_changed(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
