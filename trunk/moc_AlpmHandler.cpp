/****************************************************************************
** Meta object code from reading C++ file 'AlpmHandler.h'
**
** Created: Sat Feb 2 13:06:09 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/AlpmHandler.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AlpmHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_AlpmHandler[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      25,   13,   12,   12, 0x05,
      59,   12,   12,   12, 0x05,
      74,   71,   12,   12, 0x05,
      85,   12,   12,   12, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_AlpmHandler[] = {
    "AlpmHandler\0\0repo,action\0"
    "streamDbUpdatingStatus(char*,int)\0"
    "dbUpdated()\0db\0dbQty(int)\0dbUpdatePerformed()\0"
};

const QMetaObject AlpmHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AlpmHandler,
      qt_meta_data_AlpmHandler, 0 }
};

const QMetaObject *AlpmHandler::metaObject() const
{
    return &staticMetaObject;
}

void *AlpmHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AlpmHandler))
	return static_cast<void*>(const_cast< AlpmHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int AlpmHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: streamDbUpdatingStatus((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: dbUpdated(); break;
        case 2: dbQty((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: dbUpdatePerformed(); break;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AlpmHandler::streamDbUpdatingStatus(char * _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AlpmHandler::dbUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void AlpmHandler::dbQty(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AlpmHandler::dbUpdatePerformed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
