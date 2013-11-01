/****************************************************************************
** Meta object code from reading C++ file 'file-editor-interface.h'
**
** Created: Fri Nov 1 21:33:41 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gui/src/m-editor/file-editor-interface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'file-editor-interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_file_editor_interface[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      30,   23,   22,   22, 0x05,
      51,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   22,   22,   22, 0x0a,
      87,   22,   22,   22, 0x0a,
     116,  107,   22,   22, 0x0a,
     143,   22,   22,   22, 0x0a,
     163,   22,   22,   22, 0x0a,
     186,   22,   22,   22, 0x0a,
     207,   22,   22,   22, 0x0a,
     222,   22,   22,   22, 0x0a,
     237,   22,   22,   22, 0x0a,
     252,   22,   22,   22, 0x0a,
     266,   22,   22,   22, 0x0a,
     282,   22,   22,   22, 0x0a,
     305,   22,  297,   22, 0x0a,
     324,   22,   22,   22, 0x0a,
     350,   22,   22,   22, 0x0a,
     374,   22,   22,   22, 0x0a,
     402,   22,   22,   22, 0x0a,
     428,   22,   22,   22, 0x0a,
     460,   22,   22,   22, 0x0a,
     494,   22,   22,   22, 0x0a,
     520,   22,   22,   22, 0x0a,
     550,   22,   22,   22, 0x0a,
     578,   22,   22,   22, 0x0a,
     611,   22,  606,   22, 0x0a,
     628,   22,  606,   22, 0x0a,
     644,   22,  606,   22, 0x0a,
     672,   22,  660,   22, 0x0a,
     693,   22,  297,   22, 0x0a,
     715,   22,  711,   22, 0x0a,
     748,   22,   22,   22, 0x0a,
     776,   22,   22,   22, 0x0a,
     801,   22,   22,   22, 0x0a,
     828,   22,   22,   22, 0x0a,
     846,   22,  606,   22, 0x0a,
     870,  862,   22,   22, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_file_editor_interface[] = {
    "file_editor_interface\0\0active\0"
    "active_changed(bool)\0editor_changed()\0"
    "request_new_file()\0request_open_file()\0"
    "fileName\0request_open_file(QString)\0"
    "request_save_file()\0request_save_file_as()\0"
    "request_close_file()\0request_undo()\0"
    "request_redo()\0request_copy()\0"
    "request_cut()\0request_paste()\0"
    "request_find()\0QString\0request_run_file()\0"
    "request_toggle_bookmark()\0"
    "request_next_bookmark()\0"
    "request_previous_bookmark()\0"
    "request_remove_bookmark()\0"
    "request_comment_selected_text()\0"
    "request_uncomment_selected_text()\0"
    "request_next_breakpoint()\0"
    "request_previous_breakpoint()\0"
    "request_toggle_breakpoint()\0"
    "request_remove_breakpoint()\0bool\0"
    "copy_available()\0editor_active()\0"
    "file_modified()\0QStringList\0"
    "get_all_open_files()\0active_filename()\0"
    "int\0find_filename_in_tabs(QFileInfo)\0"
    "handle_entered_debug_mode()\0"
    "handle_quit_debug_mode()\0"
    "handle_debug_in_progress()\0notice_settings()\0"
    "save_all_tabs()\0visible\0"
    "handle_visibility_changed(bool)\0"
};

void file_editor_interface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        file_editor_interface *_t = static_cast<file_editor_interface *>(_o);
        switch (_id) {
        case 0: _t->active_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->editor_changed(); break;
        case 2: _t->request_new_file(); break;
        case 3: _t->request_open_file(); break;
        case 4: _t->request_open_file((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->request_save_file(); break;
        case 6: _t->request_save_file_as(); break;
        case 7: _t->request_close_file(); break;
        case 8: _t->request_undo(); break;
        case 9: _t->request_redo(); break;
        case 10: _t->request_copy(); break;
        case 11: _t->request_cut(); break;
        case 12: _t->request_paste(); break;
        case 13: _t->request_find(); break;
        case 14: { QString _r = _t->request_run_file();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 15: _t->request_toggle_bookmark(); break;
        case 16: _t->request_next_bookmark(); break;
        case 17: _t->request_previous_bookmark(); break;
        case 18: _t->request_remove_bookmark(); break;
        case 19: _t->request_comment_selected_text(); break;
        case 20: _t->request_uncomment_selected_text(); break;
        case 21: _t->request_next_breakpoint(); break;
        case 22: _t->request_previous_breakpoint(); break;
        case 23: _t->request_toggle_breakpoint(); break;
        case 24: _t->request_remove_breakpoint(); break;
        case 25: { bool _r = _t->copy_available();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 26: { bool _r = _t->editor_active();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 27: { bool _r = _t->file_modified();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 28: { QStringList _r = _t->get_all_open_files();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 29: { QString _r = _t->active_filename();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 30: { int _r = _t->find_filename_in_tabs((*reinterpret_cast< QFileInfo(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 31: _t->handle_entered_debug_mode(); break;
        case 32: _t->handle_quit_debug_mode(); break;
        case 33: _t->handle_debug_in_progress(); break;
        case 34: _t->notice_settings(); break;
        case 35: { bool _r = _t->save_all_tabs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 36: _t->handle_visibility_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData file_editor_interface::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject file_editor_interface::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_file_editor_interface,
      qt_meta_data_file_editor_interface, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &file_editor_interface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *file_editor_interface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *file_editor_interface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_file_editor_interface))
        return static_cast<void*>(const_cast< file_editor_interface*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int file_editor_interface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    }
    return _id;
}

// SIGNAL 0
void file_editor_interface::active_changed(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void file_editor_interface::editor_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
