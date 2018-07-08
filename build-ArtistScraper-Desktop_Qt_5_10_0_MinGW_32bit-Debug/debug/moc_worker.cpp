/****************************************************************************
** Meta object code from reading C++ file 'worker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ArtistScraper/worker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'worker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Worker_t {
    QByteArrayData data[24];
    char stringdata0[325];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Worker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Worker_t qt_meta_stringdata_Worker = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Worker"
QT_MOC_LITERAL(1, 7, 13), // "workRequested"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "valueChanged"
QT_MOC_LITERAL(4, 35, 5), // "value"
QT_MOC_LITERAL(5, 41, 8), // "finished"
QT_MOC_LITERAL(6, 50, 14), // "emitParameters"
QT_MOC_LITERAL(7, 65, 13), // "emitEmailList"
QT_MOC_LITERAL(8, 79, 16), // "emitKeywordQueue"
QT_MOC_LITERAL(9, 96, 22), // "senderCurlResponseInfo"
QT_MOC_LITERAL(10, 119, 6), // "doWork"
QT_MOC_LITERAL(11, 126, 8), // "getParam"
QT_MOC_LITERAL(12, 135, 3), // "url"
QT_MOC_LITERAL(13, 139, 9), // "userAgent"
QT_MOC_LITERAL(14, 149, 15), // "QList<QString>*"
QT_MOC_LITERAL(15, 165, 12), // "proxyServers"
QT_MOC_LITERAL(16, 178, 12), // "getProxyFile"
QT_MOC_LITERAL(17, 191, 8), // "fileName"
QT_MOC_LITERAL(18, 200, 24), // "receiverEmptyProxyServer"
QT_MOC_LITERAL(19, 225, 7), // "isEmpty"
QT_MOC_LITERAL(20, 233, 26), // "receiverStopThreadCounters"
QT_MOC_LITERAL(21, 260, 17), // "stopThreadCounter"
QT_MOC_LITERAL(22, 278, 27), // "receiverStartThreadCounters"
QT_MOC_LITERAL(23, 306, 18) // "startThreadCounter"

    },
    "Worker\0workRequested\0\0valueChanged\0"
    "value\0finished\0emitParameters\0"
    "emitEmailList\0emitKeywordQueue\0"
    "senderCurlResponseInfo\0doWork\0getParam\0"
    "url\0userAgent\0QList<QString>*\0"
    "proxyServers\0getProxyFile\0fileName\0"
    "receiverEmptyProxyServer\0isEmpty\0"
    "receiverStopThreadCounters\0stopThreadCounter\0"
    "receiverStartThreadCounters\0"
    "startThreadCounter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Worker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    1,   80,    2, 0x06 /* Public */,
       5,    0,   83,    2, 0x06 /* Public */,
       6,    0,   84,    2, 0x06 /* Public */,
       7,    1,   85,    2, 0x06 /* Public */,
       8,    0,   88,    2, 0x06 /* Public */,
       9,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   92,    2, 0x0a /* Public */,
      11,    3,   93,    2, 0x0a /* Public */,
      16,    1,  100,    2, 0x0a /* Public */,
      18,    1,  103,    2, 0x0a /* Public */,
      20,    1,  106,    2, 0x0a /* Public */,
      22,    1,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 14,   12,   13,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   23,

       0        // eod
};

void Worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Worker *_t = static_cast<Worker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->workRequested(); break;
        case 1: _t->valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->finished(); break;
        case 3: _t->emitParameters(); break;
        case 4: _t->emitEmailList((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->emitKeywordQueue(); break;
        case 6: _t->senderCurlResponseInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->doWork(); break;
        case 8: _t->getParam((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QList<QString>*(*)>(_a[3]))); break;
        case 9: _t->getProxyFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->receiverEmptyProxyServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->receiverStopThreadCounters((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->receiverStartThreadCounters((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Worker::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::workRequested)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Worker::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::valueChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Worker::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::finished)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Worker::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::emitParameters)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Worker::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::emitEmailList)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Worker::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::emitKeywordQueue)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Worker::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::senderCurlResponseInfo)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject Worker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Worker.data,
      qt_meta_data_Worker,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Worker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Worker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Worker::workRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Worker::valueChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Worker::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Worker::emitParameters()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Worker::emitEmailList(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Worker::emitKeywordQueue()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Worker::senderCurlResponseInfo(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
