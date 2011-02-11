/****************************************************************************
** Meta object code from reading C++ file 'ClientFrame.h'
**
** Created: Fri Feb 11 02:20:08 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/eggwm/xwindows/ClientFrame.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClientFrame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClientFrame[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   18,   13,   12, 0x05,
      53,   12,   12,   12, 0x05,
      70,   12,   12,   12, 0x05,
      87,   12,   12,   12, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ClientFrame[] = {
    "ClientFrame\0\0bool\0width,height\0"
    "resizedFrame(int,int)\0minimizedFrame()\0"
    "maximizedFrame()\0closedFrame()\0"
};

const QMetaObject ClientFrame::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ClientFrame,
      qt_meta_data_ClientFrame, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClientFrame::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClientFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClientFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClientFrame))
        return static_cast<void*>(const_cast< ClientFrame*>(this));
    return QWidget::qt_metacast(_clname);
}

int ClientFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { bool _r = resizedFrame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: minimizedFrame(); break;
        case 2: maximizedFrame(); break;
        case 3: closedFrame(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
bool ClientFrame::resizedFrame(int _t1, int _t2)
{
    bool _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
void ClientFrame::minimizedFrame()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ClientFrame::maximizedFrame()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ClientFrame::closedFrame()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
