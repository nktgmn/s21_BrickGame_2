/****************************************************************************
** Meta object code from reading C++ file 'desktop_controller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../desktop_controller.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'desktop_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSs21SCOPEDesktopControllerSnakeENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSs21SCOPEDesktopControllerSnakeENDCLASS = QtMocHelpers::stringData(
    "s21::DesktopControllerSnake",
    "handle_action",
    "",
    "DesktopInput",
    "input",
    "move_game",
    "update_game",
    "terminate_game"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSs21SCOPEDesktopControllerSnakeENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[28];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[6];
    char stringdata5[10];
    char stringdata6[12];
    char stringdata7[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSs21SCOPEDesktopControllerSnakeENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSs21SCOPEDesktopControllerSnakeENDCLASS_t qt_meta_stringdata_CLASSs21SCOPEDesktopControllerSnakeENDCLASS = {
    {
        QT_MOC_LITERAL(0, 27),  // "s21::DesktopControllerSnake"
        QT_MOC_LITERAL(28, 13),  // "handle_action"
        QT_MOC_LITERAL(42, 0),  // ""
        QT_MOC_LITERAL(43, 12),  // "DesktopInput"
        QT_MOC_LITERAL(56, 5),  // "input"
        QT_MOC_LITERAL(62, 9),  // "move_game"
        QT_MOC_LITERAL(72, 11),  // "update_game"
        QT_MOC_LITERAL(84, 14)   // "terminate_game"
    },
    "s21::DesktopControllerSnake",
    "handle_action",
    "",
    "DesktopInput",
    "input",
    "move_game",
    "update_game",
    "terminate_game"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSs21SCOPEDesktopControllerSnakeENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x0a,    1 /* Public */,
       5,    0,   41,    2, 0x0a,    3 /* Public */,
       6,    0,   42,    2, 0x0a,    4 /* Public */,
       7,    0,   43,    2, 0x0a,    5 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject s21::DesktopControllerSnake::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSs21SCOPEDesktopControllerSnakeENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSs21SCOPEDesktopControllerSnakeENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSs21SCOPEDesktopControllerSnakeENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DesktopControllerSnake, std::true_type>,
        // method 'handle_action'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<DesktopInput, std::false_type>,
        // method 'move_game'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'update_game'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'terminate_game'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void s21::DesktopControllerSnake::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DesktopControllerSnake *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handle_action((*reinterpret_cast< std::add_pointer_t<DesktopInput>>(_a[1]))); break;
        case 1: _t->move_game(); break;
        case 2: _t->update_game(); break;
        case 3: _t->terminate_game(); break;
        default: ;
        }
    }
}

const QMetaObject *s21::DesktopControllerSnake::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::DesktopControllerSnake::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSs21SCOPEDesktopControllerSnakeENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int s21::DesktopControllerSnake::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSs21SCOPEDesktopControllerTetrisENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSs21SCOPEDesktopControllerTetrisENDCLASS = QtMocHelpers::stringData(
    "s21::DesktopControllerTetris",
    "handle_action",
    "",
    "DesktopInput",
    "input",
    "move_game",
    "update_game",
    "terminate_game"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSs21SCOPEDesktopControllerTetrisENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[29];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[6];
    char stringdata5[10];
    char stringdata6[12];
    char stringdata7[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSs21SCOPEDesktopControllerTetrisENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSs21SCOPEDesktopControllerTetrisENDCLASS_t qt_meta_stringdata_CLASSs21SCOPEDesktopControllerTetrisENDCLASS = {
    {
        QT_MOC_LITERAL(0, 28),  // "s21::DesktopControllerTetris"
        QT_MOC_LITERAL(29, 13),  // "handle_action"
        QT_MOC_LITERAL(43, 0),  // ""
        QT_MOC_LITERAL(44, 12),  // "DesktopInput"
        QT_MOC_LITERAL(57, 5),  // "input"
        QT_MOC_LITERAL(63, 9),  // "move_game"
        QT_MOC_LITERAL(73, 11),  // "update_game"
        QT_MOC_LITERAL(85, 14)   // "terminate_game"
    },
    "s21::DesktopControllerTetris",
    "handle_action",
    "",
    "DesktopInput",
    "input",
    "move_game",
    "update_game",
    "terminate_game"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSs21SCOPEDesktopControllerTetrisENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x0a,    1 /* Public */,
       5,    0,   41,    2, 0x0a,    3 /* Public */,
       6,    0,   42,    2, 0x0a,    4 /* Public */,
       7,    0,   43,    2, 0x0a,    5 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject s21::DesktopControllerTetris::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSs21SCOPEDesktopControllerTetrisENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSs21SCOPEDesktopControllerTetrisENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSs21SCOPEDesktopControllerTetrisENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DesktopControllerTetris, std::true_type>,
        // method 'handle_action'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<DesktopInput, std::false_type>,
        // method 'move_game'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'update_game'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'terminate_game'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void s21::DesktopControllerTetris::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DesktopControllerTetris *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handle_action((*reinterpret_cast< std::add_pointer_t<DesktopInput>>(_a[1]))); break;
        case 1: _t->move_game(); break;
        case 2: _t->update_game(); break;
        case 3: _t->terminate_game(); break;
        default: ;
        }
    }
}

const QMetaObject *s21::DesktopControllerTetris::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::DesktopControllerTetris::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSs21SCOPEDesktopControllerTetrisENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int s21::DesktopControllerTetris::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
