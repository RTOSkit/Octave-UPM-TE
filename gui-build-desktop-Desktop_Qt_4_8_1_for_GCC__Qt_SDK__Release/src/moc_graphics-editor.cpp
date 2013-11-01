/****************************************************************************
** Meta object code from reading C++ file 'graphics-editor.h'
**
** Created: Fri Nov 1 21:34:12 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gui/src/graphics-editor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphics-editor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GraphicsEditor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      39,   37,   15,   15, 0x0a,
      62,   15,   15,   15, 0x08,
      86,   84,   15,   15, 0x08,
     114,   84,   15,   15, 0x08,
     142,   15,   15,   15, 0x08,
     162,   15,   15,   15, 0x08,
     181,   15,   15,   15, 0x08,
     199,   15,   15,   15, 0x08,
     213,   37,   15,   15, 0x08,
     237,  235,   15,   15, 0x08,
     263,  261,   15,   15, 0x08,
     286,  284,   15,   15, 0x08,
     312,   15,   15,   15, 0x08,
     327,   15,   15,   15, 0x08,
     356,  354,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GraphicsEditor[] = {
    "GraphicsEditor\0\0apply_all_settings()\0"
    "v\0set_plot_visible(bool)\0user_set_color_slot()\0"
    "d\0user_set_plot_width(double)\0"
    "user_set_axis_width(double)\0"
    "update_plot_color()\0generate_preview()\0"
    "repaint_preview()\0toggle_grid()\0"
    "update_axis_font(int)\0t\0user_set_plot_line(int)\0"
    "m\0user_set_marker(int)\0s\0"
    "user_set_marker_size(int)\0update_scene()\0"
    "resizeEvent(QResizeEvent*)\0e\0"
    "showEvent(QShowEvent*)\0"
};

void GraphicsEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GraphicsEditor *_t = static_cast<GraphicsEditor *>(_o);
        switch (_id) {
        case 0: _t->apply_all_settings(); break;
        case 1: _t->set_plot_visible((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 2: _t->user_set_color_slot(); break;
        case 3: _t->user_set_plot_width((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->user_set_axis_width((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->update_plot_color(); break;
        case 6: _t->generate_preview(); break;
        case 7: _t->repaint_preview(); break;
        case 8: _t->toggle_grid(); break;
        case 9: _t->update_axis_font((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->user_set_plot_line((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->user_set_marker((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->user_set_marker_size((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->update_scene(); break;
        case 14: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 15: _t->showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GraphicsEditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GraphicsEditor::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GraphicsEditor,
      qt_meta_data_GraphicsEditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GraphicsEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GraphicsEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GraphicsEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GraphicsEditor))
        return static_cast<void*>(const_cast< GraphicsEditor*>(this));
    return QDialog::qt_metacast(_clname);
}

int GraphicsEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
