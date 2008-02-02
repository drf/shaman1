/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Sat Feb 2 13:59:17 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_MainWindow[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      28,   11,   23,   11, 0x0a,
      55,   51,   11,   11, 0x0a,
      92,   11,   23,   11, 0x0a,
     113,   11,   11,   11, 0x0a,
     127,   11,   11,   11, 0x0a,
     140,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0updateDB()\0bool\0"
    "populatePackagesView()\0itm\0"
    "changePackagesView(QListWidgetItem*)\0"
    "populateRepoColumn()\0showPkgInfo()\0"
    "doDbUpdate()\0finishDbUpdate()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
	return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateDB(); break;
        case 1: { bool _r = populatePackagesView();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: changePackagesView((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: { bool _r = populateRepoColumn();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: showPkgInfo(); break;
        case 5: doDbUpdate(); break;
        case 6: finishDbUpdate(); break;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::updateDB()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
