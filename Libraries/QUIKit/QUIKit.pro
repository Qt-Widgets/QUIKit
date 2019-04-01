#-------------------------------------------------
#
# Project created by QtCreator 2019-04-01T12:10:12
#
#-------------------------------------------------

QT += qml quick widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QUIKit
TEMPLATE = lib

DEFINES += QUIKIT_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH +=  $$PWD/../

include(./../../Path.pri)
include(FramelessHelper/FramelessHelper.pri)

HEADERS += \
    QUIKit.h \
    quikit_global.h \
    NoFocusRectStyle.h \
    BaseWindow.h

FORMS += \
    BaseWindow.ui

SOURCES += \
    BaseWindow.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}

RESOURCES += \
    Res.qrc

headers.files +=     BaseWindow.h \
                     FramelessHelper/FramelessHelper.h \
                     FramelessHelper/WindowFramelessHelper.h
headers.path  +=     $$INCLUDE_INSTALL_ROOT/QUIKit

INSTALLS += headers

dlls.files  +=      $$DESTDIR/QUIKit.dll
dlls.path   +=      $$LIB_INSTALL_ROOT
INSTALLS    +=      dlls
