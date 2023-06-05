/****************************************************************************
** Meta object code from reading C++ file 'paintscene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Graph/paintscene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paintscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PaintScene_t {
    QByteArrayData data[10];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PaintScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PaintScene_t qt_meta_stringdata_PaintScene = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PaintScene"
QT_MOC_LITERAL(1, 11, 18), // "signalGetPtrMatrix"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 11), // "AdjMatrix*&"
QT_MOC_LITERAL(4, 43, 13), // "out_ptrMatrix"
QT_MOC_LITERAL(5, 57, 15), // "deleteItem_Line"
QT_MOC_LITERAL(6, 73, 9), // "firstVert"
QT_MOC_LITERAL(7, 83, 10), // "secondVert"
QT_MOC_LITERAL(8, 94, 16), // "deleteItem_Point"
QT_MOC_LITERAL(9, 111, 5) // "index"

    },
    "PaintScene\0signalGetPtrMatrix\0\0"
    "AdjMatrix*&\0out_ptrMatrix\0deleteItem_Line\0"
    "firstVert\0secondVert\0deleteItem_Point\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PaintScene[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   32,    2, 0x0a /* Public */,
       8,    1,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void PaintScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PaintScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalGetPtrMatrix((*reinterpret_cast< AdjMatrix*(*)>(_a[1]))); break;
        case 1: _t->deleteItem_Line((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->deleteItem_Point((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PaintScene::*)(AdjMatrix * & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PaintScene::signalGetPtrMatrix)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PaintScene::staticMetaObject = { {
    &QGraphicsScene::staticMetaObject,
    qt_meta_stringdata_PaintScene.data,
    qt_meta_data_PaintScene,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PaintScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PaintScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PaintScene.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int PaintScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void PaintScene::signalGetPtrMatrix(AdjMatrix * & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
