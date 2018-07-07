/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ArtistScraper/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[388];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "postParam"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 15), // "QList<QString>*"
QT_MOC_LITERAL(4, 38, 14), // "emitParameters"
QT_MOC_LITERAL(5, 53, 26), // "emitsenderEmptyProxyServer"
QT_MOC_LITERAL(6, 80, 27), // "on_pushButton_Start_clicked"
QT_MOC_LITERAL(7, 108, 7), // "checked"
QT_MOC_LITERAL(8, 116, 39), // "on_pushButton_Load_Keyword_Li..."
QT_MOC_LITERAL(9, 156, 11), // "eventFilter"
QT_MOC_LITERAL(10, 168, 7), // "watched"
QT_MOC_LITERAL(11, 176, 7), // "QEvent*"
QT_MOC_LITERAL(12, 184, 5), // "event"
QT_MOC_LITERAL(13, 190, 15), // "mousePressEvent"
QT_MOC_LITERAL(14, 206, 12), // "QMouseEvent*"
QT_MOC_LITERAL(15, 219, 31), // "on_pushButton_Add_Proxy_clicked"
QT_MOC_LITERAL(16, 251, 34), // "on_pushButton_Load_Proxies_cl..."
QT_MOC_LITERAL(17, 286, 17), // "receiverEmailList"
QT_MOC_LITERAL(18, 304, 18), // "receiverParameters"
QT_MOC_LITERAL(19, 323, 27), // "recieverProxyTableSelection"
QT_MOC_LITERAL(20, 351, 14), // "QItemSelection"
QT_MOC_LITERAL(21, 366, 21) // "recieverKeywordsQueue"

    },
    "MainWindow\0postParam\0\0QList<QString>*\0"
    "emitParameters\0emitsenderEmptyProxyServer\0"
    "on_pushButton_Start_clicked\0checked\0"
    "on_pushButton_Load_Keyword_List_clicked\0"
    "eventFilter\0watched\0QEvent*\0event\0"
    "mousePressEvent\0QMouseEvent*\0"
    "on_pushButton_Add_Proxy_clicked\0"
    "on_pushButton_Load_Proxies_clicked\0"
    "receiverEmailList\0receiverParameters\0"
    "recieverProxyTableSelection\0QItemSelection\0"
    "recieverKeywordsQueue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   79,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,
       5,    1,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   90,    2, 0x08 /* Private */,
       8,    0,   93,    2, 0x08 /* Private */,
       9,    2,   94,    2, 0x08 /* Private */,
      13,    1,   99,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,
      17,    1,  104,    2, 0x0a /* Public */,
      18,    0,  107,    2, 0x0a /* Public */,
      19,    2,  108,    2, 0x0a /* Public */,
      21,    0,  113,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 3,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 11,   10,   12,
    QMetaType::Void, 0x80000000 | 14,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 20,    2,    2,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->postParam((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QList<QString>*(*)>(_a[3]))); break;
        case 1: _t->emitParameters(); break;
        case 2: _t->emitsenderEmptyProxyServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_Start_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_Load_Keyword_List_clicked(); break;
        case 5: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_Add_Proxy_clicked(); break;
        case 8: _t->on_pushButton_Load_Proxies_clicked(); break;
        case 9: _t->receiverEmailList((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->receiverParameters(); break;
        case 11: _t->recieverProxyTableSelection((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 12: _t->recieverKeywordsQueue(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QItemSelection >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainWindow::*_t)(QString , QString , QList<QString> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::postParam)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::emitParameters)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::emitsenderEmptyProxyServer)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::postParam(QString _t1, QString _t2, QList<QString> * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::emitParameters()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::emitsenderEmptyProxyServer(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
