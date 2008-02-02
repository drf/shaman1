/****************************************************************************
** Meta object code from reading C++ file 'ConfigurationParser.h'
**
** Created: Fri Feb 1 23:04:24 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/ConfigurationParser.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConfigurationParser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_ConfigurationParser[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_ConfigurationParser[] = {
    "ConfigurationParser\0"
};

const QMetaObject ConfigurationParser::staticMetaObject = {
    { &StringUtils::staticMetaObject, qt_meta_stringdata_ConfigurationParser,
      qt_meta_data_ConfigurationParser, 0 }
};

const QMetaObject *ConfigurationParser::metaObject() const
{
    return &staticMetaObject;
}

void *ConfigurationParser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigurationParser))
	return static_cast<void*>(const_cast< ConfigurationParser*>(this));
    return StringUtils::qt_metacast(_clname);
}

int ConfigurationParser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StringUtils::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
