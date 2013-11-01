/****************************************************************************
** Meta object code from reading C++ file 'file-editor-tab.h'
**
** Created: Fri Nov 1 21:33:42 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gui/src/m-editor/file-editor-tab.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'file-editor-tab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_file_editor_tab[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      38,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   17,   16,   16, 0x05,
      53,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      85,   76,   16,   16, 0x0a,
     112,  101,   16,   16, 0x0a,
     158,  140,   16,   16, 0x0a,
     211,   16,   16,   16, 0x0a,
     235,   16,   16,   16, 0x0a,
     261,   16,   16,   16, 0x0a,
     279,   16,   16,   16, 0x0a,
     297,   16,   16,   16, 0x0a,
     313,   16,   16,   16, 0x0a,
     333,   16,   16,   16, 0x0a,
     358,   16,   16,   16, 0x0a,
     378,   16,   16,   16, 0x0a,
     396,   16,   16,   16, 0x0a,
     418,   16,   16,   16, 0x0a,
     424,   16,   16,   16, 0x0a,
     431,   16,   16,   16, 0x0a,
     439,   16,   16,   16, 0x0a,
     446,   16,   16,   16, 0x0a,
     458,  453,   16,   16, 0x0a,
     485,   16,   16,   16, 0x0a,
     492,   76,   16,   16, 0x0a,
     511,   16,   16,   16, 0x2a,
     526,   17,   16,   16, 0x0a,
     545,   16,   16,   16, 0x0a,
     561,   16,  556,   16, 0x0a,
     586,  573,  556,   16, 0x0a,
     605,   16,  556,   16, 0x0a,
     628,   16,  620,   16, 0x0a,
     639,   16,  556,   16, 0x0a,
     654,   16,   16,   16, 0x0a,
     668,   16,   16,   16, 0x0a,
     689,   16,   16,   16, 0x0a,
     716,   16,   16,   16, 0x0a,
     734,   16,  556,   16, 0x0a,
     748,   16,  620,   16, 0x0a,
     778,  764,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_file_editor_tab[] = {
    "file_editor_tab\0\0fileName\0"
    "file_name_changed(QString)\0"
    "editor_state_changed()\0modified\0"
    "new_title(bool)\0enableCopy\0"
    "handle_copy_available(bool)\0"
    "line,margin,state\0"
    "handle_margin_clicked(int,int,Qt::KeyboardModifiers)\0"
    "comment_selected_text()\0"
    "uncomment_selected_text()\0remove_bookmark()\0"
    "toggle_bookmark()\0next_bookmark()\0"
    "previous_bookmark()\0remove_all_breakpoints()\0"
    "toggle_breakpoint()\0next_breakpoint()\0"
    "previous_breakpoint()\0cut()\0copy()\0"
    "paste()\0undo()\0redo()\0line\0"
    "set_debugger_position(int)\0find()\0"
    "set_modified(bool)\0set_modified()\0"
    "load_file(QString)\0new_file()\0bool\0"
    "save_file()\0saveFileName\0save_file(QString)\0"
    "save_file_as()\0QString\0run_file()\0"
    "attempt_save()\0save_backup()\0"
    "remove_backup_file()\0check_backup_file(QString)\0"
    "notice_settings()\0is_modified()\0"
    "get_file_name()\0active,period\0"
    "set_autosave(bool,int)\0"
};

void file_editor_tab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        file_editor_tab *_t = static_cast<file_editor_tab *>(_o);
        switch (_id) {
        case 0: _t->file_name_changed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->editor_state_changed(); break;
        case 2: _t->new_title((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->handle_copy_available((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->handle_margin_clicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[3]))); break;
        case 5: _t->comment_selected_text(); break;
        case 6: _t->uncomment_selected_text(); break;
        case 7: _t->remove_bookmark(); break;
        case 8: _t->toggle_bookmark(); break;
        case 9: _t->next_bookmark(); break;
        case 10: _t->previous_bookmark(); break;
        case 11: _t->remove_all_breakpoints(); break;
        case 12: _t->toggle_breakpoint(); break;
        case 13: _t->next_breakpoint(); break;
        case 14: _t->previous_breakpoint(); break;
        case 15: _t->cut(); break;
        case 16: _t->copy(); break;
        case 17: _t->paste(); break;
        case 18: _t->undo(); break;
        case 19: _t->redo(); break;
        case 20: _t->set_debugger_position((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->find(); break;
        case 22: _t->set_modified((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->set_modified(); break;
        case 24: _t->load_file((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 25: _t->new_file(); break;
        case 26: { bool _r = _t->save_file();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 27: { bool _r = _t->save_file((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 28: { bool _r = _t->save_file_as();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 29: { QString _r = _t->run_file();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 30: { bool _r = _t->attempt_save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 31: _t->save_backup(); break;
        case 32: _t->remove_backup_file(); break;
        case 33: _t->check_backup_file((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 34: _t->notice_settings(); break;
        case 35: { bool _r = _t->is_modified();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 36: { QString _r = _t->get_file_name();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 37: _t->set_autosave((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData file_editor_tab::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject file_editor_tab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_file_editor_tab,
      qt_meta_data_file_editor_tab, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &file_editor_tab::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *file_editor_tab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *file_editor_tab::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_file_editor_tab))
        return static_cast<void*>(const_cast< file_editor_tab*>(this));
    if (!strcmp(_clname, "octave_event_observer"))
        return static_cast< octave_event_observer*>(const_cast< file_editor_tab*>(this));
    return QWidget::qt_metacast(_clname);
}

int file_editor_tab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 38)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 38;
    }
    return _id;
}

// SIGNAL 0
void file_editor_tab::file_name_changed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void file_editor_tab::editor_state_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
