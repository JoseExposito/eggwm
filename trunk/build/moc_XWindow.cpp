/****************************************************************************
** Meta object code from reading C++ file 'XWindow.h'
**
** Created: Tue Jan 18 22:05:45 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/eggwm/xwindows/XWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'XWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_XWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   14,    9,    8, 0x0a,
      49,    8,    8,    8, 0x0a,
      66,    8,    8,    8, 0x0a,
      83,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_XWindow[] = {
    "XWindow\0\0bool\0width,height\0"
    "resizedFrame(int,int)\0minimizedFrame()\0"
    "maximizedFrame()\0closedFrame()\0"
};

const QMetaObject XWindow::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_XWindow,
      qt_meta_data_XWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &XWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *XWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *XWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_XWindow))
        return static_cast<void*>(const_cast< XWindow*>(this));
    return QObject::qt_metacast(_clname);
}

int XWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
