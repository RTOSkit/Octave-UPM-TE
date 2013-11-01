/****************************************************************************
** Meta object code from reading C++ file 'webinfo.h'
**
** Created: Fri Nov 1 21:34:31 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gui/src/doc-viewer/webinfo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WebInfo[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,    9,    8,    8, 0x0a,
      41,   35,    8,    8, 0x0a,
      67,    8,    8,    8, 0x0a,
      81,    8,    8,    8, 0x0a,
      93,    8,    8,    8, 0x0a,
     105,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_WebInfo[] = {
    "WebInfo\0\0link\0linkClicked_cb(QUrl)\0"
    "index\0currentTabChanged_cb(int)\0"
    "closeTab_cb()\0search_cb()\0zoomIn_cb()\0"
    "zoomOut_cb()\0"
};

void WebInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WebInfo *_t = static_cast<WebInfo *>(_o);
        switch (_id) {
        case 0: _t->linkClicked_cb((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 1: _t->currentTabChanged_cb((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->closeTab_cb(); break;
        case 3: _t->search_cb(); break;
        case 4: _t->zoomIn_cb(); break;
        case 5: _t->zoomOut_cb(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData WebInfo::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WebInfo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WebInfo,
      qt_meta_data_WebInfo, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WebInfo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WebInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WebInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WebInfo))
        return static_cast<void*>(const_cast< WebInfo*>(this));
    return QWidget::qt_metacast(_clname);
}

int WebInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
