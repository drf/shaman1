/****************************************************************************
** Meta object code from reading C++ file 'callbacks.h'
**
** Created: Sat Feb 2 13:11:42 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/callbacks.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'callbacks.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_CallBacks[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      29,   11,   10,   10, 0x05,
      96,   72,   10,   10, 0x05,
     186,  149,   10,   10, 0x05,
     294,  245,   10,   10, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_CallBacks[] = {
    "CallBacks\0\0event,data1,data2\0"
    "streamTransEvent(pmtransevt_t,void*,void*)\0"
    "event,data1,data2,data3\0"
    "streamTransQuestion(pmtransconv_t,void*,void*,void*)\0"
    "event,pkgname,percent,howmany,remain\0"
    "streamTransProgress(pmtransprog_t,const char*,int,int,int)\0"
    "filename,file_x,file_t,spd_f,list_x,list_t,spd_l\0"
    "streamTransDlProg(char*,int,int,float,int,int,float)\0"
};

const QMetaObject CallBacks::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CallBacks,
      qt_meta_data_CallBacks, 0 }
};

const QMetaObject *CallBacks::metaObject() const
{
    return &staticMetaObject;
}

void *CallBacks::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CallBacks))
	return static_cast<void*>(const_cast< CallBacks*>(this));
    return QObject::qt_metacast(_clname);
}

int CallBacks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: streamTransEvent((*reinterpret_cast< pmtransevt_t(*)>(_a[1])),(*reinterpret_cast< void*(*)>(_a[2])),(*reinterpret_cast< void*(*)>(_a[3]))); break;
        case 1: streamTransQuestion((*reinterpret_cast< pmtransconv_t(*)>(_a[1])),(*reinterpret_cast< void*(*)>(_a[2])),(*reinterpret_cast< void*(*)>(_a[3])),(*reinterpret_cast< void*(*)>(_a[4]))); break;
        case 2: streamTransProgress((*reinterpret_cast< pmtransprog_t(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 3: streamTransDlProg((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< float(*)>(_a[7]))); break;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CallBacks::streamTransEvent(pmtransevt_t _t1, void * _t2, void * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CallBacks::streamTransQuestion(pmtransconv_t _t1, void * _t2, void * _t3, void * _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CallBacks::streamTransProgress(pmtransprog_t _t1, const char * _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CallBacks::streamTransDlProg(char * _t1, int _t2, int _t3, float _t4, int _t5, int _t6, float _t7)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
