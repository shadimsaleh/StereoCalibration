/****************************************************************************
** Meta object code from reading C++ file 'stereocalibration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../stereocalibration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stereocalibration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StereoCalibration_t {
    QByteArrayData data[9];
    char stringdata[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StereoCalibration_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StereoCalibration_t qt_meta_stringdata_StereoCalibration = {
    {
QT_MOC_LITERAL(0, 0, 17), // "StereoCalibration"
QT_MOC_LITERAL(1, 18, 36), // "onComputeIntrinsicsParameters..."
QT_MOC_LITERAL(2, 55, 0), // ""
QT_MOC_LITERAL(3, 56, 29), // "onPushButtonLoadImagesClicked"
QT_MOC_LITERAL(4, 86, 28), // "onPushButtonNextFrameClicked"
QT_MOC_LITERAL(5, 115, 29), // "onPushStartCalibrationClicked"
QT_MOC_LITERAL(6, 145, 33), // "onPushButtonStartDetectionCli..."
QT_MOC_LITERAL(7, 179, 20), // "patternParametersMaj"
QT_MOC_LITERAL(8, 200, 18) // "pointDetectionAuto"

    },
    "StereoCalibration\0"
    "onComputeIntrinsicsParametersChanged\0"
    "\0onPushButtonLoadImagesClicked\0"
    "onPushButtonNextFrameClicked\0"
    "onPushStartCalibrationClicked\0"
    "onPushButtonStartDetectionClicked\0"
    "patternParametersMaj\0pointDetectionAuto"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StereoCalibration[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StereoCalibration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StereoCalibration *_t = static_cast<StereoCalibration *>(_o);
        switch (_id) {
        case 0: _t->onComputeIntrinsicsParametersChanged(); break;
        case 1: _t->onPushButtonLoadImagesClicked(); break;
        case 2: _t->onPushButtonNextFrameClicked(); break;
        case 3: _t->onPushStartCalibrationClicked(); break;
        case 4: _t->onPushButtonStartDetectionClicked(); break;
        case 5: _t->patternParametersMaj(); break;
        case 6: _t->pointDetectionAuto(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject StereoCalibration::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_StereoCalibration.data,
      qt_meta_data_StereoCalibration,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StereoCalibration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StereoCalibration::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StereoCalibration.stringdata))
        return static_cast<void*>(const_cast< StereoCalibration*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int StereoCalibration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
