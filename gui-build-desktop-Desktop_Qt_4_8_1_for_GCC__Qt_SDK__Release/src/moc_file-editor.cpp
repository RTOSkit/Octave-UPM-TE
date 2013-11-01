/****************************************************************************
** Meta object code from reading C++ file 'file-editor.h'
**
** Created: Fri Nov 1 21:33:35 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gui/src/m-editor/file-editor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'file-editor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_file_editor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   12,   12,   12, 0x0a,
      49,   12,   12,   12, 0x0a,
      78,   69,   12,   12, 0x0a,
     105,   12,   12,   12, 0x0a,
     133,   12,   12,   12, 0x0a,
     158,   12,   12,   12, 0x0a,
     185,   12,   12,   12, 0x0a,
     200,   12,   12,   12, 0x0a,
     215,   12,   12,   12, 0x0a,
     230,   12,   12,   12, 0x0a,
     244,   12,   12,   12, 0x0a,
     260,   12,   12,   12, 0x0a,
     275,   12,   12,   12, 0x0a,
     295,   12,   12,   12, 0x0a,
     318,   12,   12,   12, 0x0a,
     347,   12,  339,   12, 0x0a,
     366,   12,   12,   12, 0x0a,
     392,   12,   12,   12, 0x0a,
     416,   12,   12,   12, 0x0a,
     444,   12,   12,   12, 0x0a,
     470,   12,   12,   12, 0x0a,
     502,   12,   12,   12, 0x0a,
     536,   12,   12,   12, 0x0a,
     564,   12,   12,   12, 0x0a,
     590,   12,   12,   12, 0x0a,
     620,   12,   12,   12, 0x0a,
     648,   69,   12,   12, 0x0a,
     688,  682,   12,   12, 0x0a,
     718,   12,   12,   12, 0x0a,
     745,  682,   12,   12, 0x0a,
     769,   12,   12,   12, 0x0a,
     804,   12,  799,   12, 0x0a,
     820,   12,   12,   12, 0x0a,
     838,   12,   12,   12, 0x0a,
     869,   12,  339,   12, 0x0a,
     893,   12,  799,   12, 0x0a,
     910,   12,  799,   12, 0x0a,
     926,   12,  799,   12, 0x0a,
     954,   12,  942,   12, 0x0a,
     975,   12,  339,   12, 0x0a,
    1000,  997,  993,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_file_editor[] = {
    "file_editor\0\0editor_changed()\0"
    "request_new_file()\0request_open_file()\0"
    "fileName\0request_open_file(QString)\0"
    "handle_entered_debug_mode()\0"
    "handle_quit_debug_mode()\0"
    "handle_debug_in_progress()\0request_undo()\0"
    "request_redo()\0request_copy()\0"
    "request_cut()\0request_paste()\0"
    "request_find()\0request_save_file()\0"
    "request_save_file_as()\0request_close_file()\0"
    "QString\0request_run_file()\0"
    "request_toggle_bookmark()\0"
    "request_next_bookmark()\0"
    "request_previous_bookmark()\0"
    "request_remove_bookmark()\0"
    "request_comment_selected_text()\0"
    "request_uncomment_selected_text()\0"
    "request_toggle_breakpoint()\0"
    "request_next_breakpoint()\0"
    "request_previous_breakpoint()\0"
    "request_remove_breakpoint()\0"
    "handle_file_name_changed(QString)\0"
    "index\0handle_tab_close_request(int)\0"
    "handle_tab_close_request()\0"
    "active_tab_changed(int)\0"
    "handle_editor_state_changed()\0bool\0"
    "save_all_tabs()\0notice_settings()\0"
    "set_current_directory(QString)\0"
    "get_current_directory()\0copy_available()\0"
    "editor_active()\0file_modified()\0"
    "QStringList\0get_all_open_files()\0"
    "active_filename()\0int\0fn\0"
    "find_filename_in_tabs(QFileInfo)\0"
};

void file_editor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        file_editor *_t = static_cast<file_editor *>(_o);
        switch (_id) {
        case 0: _t->editor_changed(); break;
        case 1: _t->request_new_file(); break;
        case 2: _t->request_open_file(); break;
        case 3: _t->request_open_file((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->handle_entered_debug_mode(); break;
        case 5: _t->handle_quit_debug_mode(); break;
        case 6: _t->handle_debug_in_progress(); break;
        case 7: _t->request_undo(); break;
        case 8: _t->request_redo(); break;
        case 9: _t->request_copy(); break;
        case 10: _t->request_cut(); break;
        case 11: _t->request_paste(); break;
        case 12: _t->request_find(); break;
        case 13: _t->request_save_file(); break;
        case 14: _t->request_save_file_as(); break;
        case 15: _t->request_close_file(); break;
        case 16: { QString _r = _t->request_run_file();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 17: _t->request_toggle_bookmark(); break;
        case 18: _t->request_next_bookmark(); break;
        case 19: _t->request_previous_bookmark(); break;
        case 20: _t->request_remove_bookmark(); break;
        case 21: _t->request_comment_selected_text(); break;
        case 22: _t->request_uncomment_selected_text(); break;
        case 23: _t->request_toggle_breakpoint(); break;
        case 24: _t->request_next_breakpoint(); break;
        case 25: _t->request_previous_breakpoint(); break;
        case 26: _t->request_remove_breakpoint(); break;
        case 27: _t->handle_file_name_changed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: _t->handle_tab_close_request((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->handle_tab_close_request(); break;
        case 30: _t->active_tab_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->handle_editor_state_changed(); break;
        case 32: { bool _r = _t->save_all_tabs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 33: _t->notice_settings(); break;
        case 34: _t->set_current_directory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 35: { QString _r = _t->get_current_directory();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 36: { bool _r = _t->copy_available();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 37: { bool _r = _t->editor_active();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 38: { bool _r = _t->file_modified();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 39: { QStringList _r = _t->get_all_open_files();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 40: { QString _r = _t->active_filename();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 41: { int _r = _t->find_filename_in_tabs((*reinterpret_cast< QFileInfo(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData file_editor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject file_editor::staticMetaObject = {
    { &file_editor_interface::staticMetaObject, qt_meta_stringdata_file_editor,
      qt_meta_data_file_editor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &file_editor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *file_editor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *file_editor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_file_editor))
        return static_cast<void*>(const_cast< file_editor*>(this));
    if (!strcmp(_clname, "octave_event_observer"))
        return static_cast< octave_event_observer*>(const_cast< file_editor*>(this));
    return file_editor_interface::qt_metacast(_clname);
}

int file_editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = file_editor_interface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    }
    return _id;
}

// SIGNAL 0
void file_editor::editor_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
