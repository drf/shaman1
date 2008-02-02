/****************************************************************************
** Meta object code from reading C++ file 'UpdateDbDialog.h'
**
** Created: Sat Feb 2 13:59:18 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/UpdateDbDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UpdateDbDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_UpdateDbDialog[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   25,   15,   15, 0x08,
      60,   15,   15,   15, 0x08,
      84,   78,   15,   15, 0x08,
     102,   15,   15,   15, 0x08,
     115,   15,   15,   15, 0x08,
     126,   15,   15,   15, 0x08,
     172,  139,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_UpdateDbDialog[] = {
    "UpdateDbDialog\0\0killMe()\0repo,action\0"
    "updateLabel(char*,int)\0updateTotalProg()\0"
    "range\0setPBarRange(int)\0setUpdated()\0"
    "doAction()\0scopeEnded()\0"
    "c,bytedone,bytetotal,speed,i,j,k\0"
    "updateDlBar(char*,int,int,int,int,int,int)\0"
};

const QMetaObject UpdateDbDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_UpdateDbDialog,
      qt_meta_data_UpdateDbDialog, 0 }
};

const QMetaObject *UpdateDbDialog::metaObject() const
{
    return &staticMetaObject;
}

void *UpdateDbDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UpdateDbDialog))
	return static_cast<void*>(const_cast< UpdateDbDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int UpdateDbDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: killMe(); break;
        case 1: updateLabel((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: updateTotalProg(); break;
        case 3: setPBarRange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: setUpdated(); break;
        case 5: doAction(); break;
        case 6: scopeEnded(); break;
        case 7: updateDlBar((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void UpdateDbDialog::killMe()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
