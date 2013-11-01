/****************************************************************************
** Meta object code from reading C++ file 'TerminalView.h'
**
** Created: Fri Nov 1 20:07:05 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gui/qterminal/libqterminal/unix/TerminalView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TerminalView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TerminalView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   14,   13,   13, 0x05,
      74,   45,   13,   13, 0x05,
     116,  103,   13,   13, 0x05,
     149,  103,   13,   13, 0x05,
     199,  183,   13,   13, 0x05,
     242,   13,   13,   13, 0x05,
     264,   13,   13,   13, 0x05,
     298,  293,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     321,   13,   13,   13, 0x0a,
     335,   13,   13,   13, 0x0a,
     358,   13,   13,   13, 0x0a,
     374,   13,   13,   13, 0x0a,
     391,   13,   13,   13, 0x0a,
     418,  408,   13,   13, 0x0a,
     450,  440,   13,   13, 0x0a,
     474,   13,  469,   13, 0x0a,
     492,  486,   13,   13, 0x09,
     522,   13,   13,   13, 0x09,
     535,   13,   13,   13, 0x09,
     554,   13,   13,   13, 0x09,
     567,   13,   13,   13, 0x08,
     584,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TerminalView[] = {
    "TerminalView\0\0e\0keyPressedSignal(QKeyEvent*)\0"
    "button,column,line,eventType\0"
    "mouseSignal(int,int,int,int)\0height,width\0"
    "changedFontMetricSignal(int,int)\0"
    "changedContentSizeSignal(int,int)\0"
    ",state,position\0"
    "configureRequest(TerminalView*,int,QPoint)\0"
    "isBusySelecting(bool)\0"
    "sendStringToEmu(const char*)\0text\0"
    "tripleClicked(QString)\0updateImage()\0"
    "updateLineProperties()\0copyClipboard()\0"
    "pasteClipboard()\0pasteSelection()\0"
    "suspended\0outputSuspended(bool)\0"
    "usesMouse\0setUsesMouse(bool)\0bool\0"
    "usesMouse()\0value\0scrollBarPositionChanged(int)\0"
    "blinkEvent()\0blinkCursorEvent()\0"
    "enableBell()\0swapColorTable()\0"
    "tripleClickTimeout()\0"
};

void TerminalView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TerminalView *_t = static_cast<TerminalView *>(_o);
        switch (_id) {
        case 0: _t->keyPressedSignal((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 1: _t->mouseSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->changedFontMetricSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->changedContentSizeSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->configureRequest((*reinterpret_cast< TerminalView*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QPoint(*)>(_a[3]))); break;
        case 5: _t->isBusySelecting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->sendStringToEmu((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 7: _t->tripleClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->updateImage(); break;
        case 9: _t->updateLineProperties(); break;
        case 10: _t->copyClipboard(); break;
        case 11: _t->pasteClipboard(); break;
        case 12: _t->pasteSelection(); break;
        case 13: _t->outputSuspended((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->setUsesMouse((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: { bool _r = _t->usesMouse();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 16: _t->scrollBarPositionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->blinkEvent(); break;
        case 18: _t->blinkCursorEvent(); break;
        case 19: _t->enableBell(); break;
        case 20: _t->swapColorTable(); break;
        case 21: _t->tripleClickTimeout(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TerminalView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TerminalView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TerminalView,
      qt_meta_data_TerminalView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TerminalView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TerminalView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TerminalView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TerminalView))
        return static_cast<void*>(const_cast< TerminalView*>(this));
    return QWidget::qt_metacast(_clname);
}

int TerminalView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void TerminalView::keyPressedSignal(QKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TerminalView::mouseSignal(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TerminalView::changedFontMetricSignal(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TerminalView::changedContentSizeSignal(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TerminalView::configureRequest(TerminalView * _t1, int _t2, const QPoint & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TerminalView::isBusySelecting(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TerminalView::sendStringToEmu(const char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TerminalView::tripleClicked(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
