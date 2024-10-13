/****************************************************************************
** Meta object code from reading C++ file 'desktop_view.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gui/desktop/desktop_view.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'desktop_view.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSs21SCOPEDesktopViewENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSs21SCOPEDesktopViewENDCLASS = QtMocHelpers::stringData(
    "s21::DesktopView",
    "key_pressed",
    "",
    "DesktopInput",
    "terminate_game_pressed",
    "handleKeyPress"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSs21SCOPEDesktopViewENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[17];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[23];
    char stringdata5[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSs21SCOPEDesktopViewENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSs21SCOPEDesktopViewENDCLASS_t qt_meta_stringdata_CLASSs21SCOPEDesktopViewENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "s21::DesktopView"
        QT_MOC_LITERAL(17, 11),  // "key_pressed"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 12),  // "DesktopInput"
        QT_MOC_LITERAL(43, 22),  // "terminate_game_pressed"
        QT_MOC_LITERAL(66, 14)   // "handleKeyPress"
    },
    "s21::DesktopView",
    "key_pressed",
    "",
    "DesktopInput",
    "terminate_game_pressed",
    "handleKeyPress"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSs21SCOPEDesktopViewENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    1 /* Public */,
       4,    0,   35,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   36,    2, 0x08,    4 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject s21::DesktopView::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSs21SCOPEDesktopViewENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSs21SCOPEDesktopViewENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSs21SCOPEDesktopViewENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DesktopView, std::true_type>,
        // method 'key_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<DesktopInput, std::false_type>,
        // method 'terminate_game_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleKeyPress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void s21::DesktopView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DesktopView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->key_pressed((*reinterpret_cast< std::add_pointer_t<DesktopInput>>(_a[1]))); break;
        case 1: _t->terminate_game_pressed(); break;
        case 2: _t->handleKeyPress(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DesktopView::*)(DesktopInput );
            if (_t _q_method = &DesktopView::key_pressed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DesktopView::*)();
            if (_t _q_method = &DesktopView::terminate_game_pressed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *s21::DesktopView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::DesktopView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSs21SCOPEDesktopViewENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int s21::DesktopView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void s21::DesktopView::key_pressed(DesktopInput _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void s21::DesktopView::terminate_game_pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
