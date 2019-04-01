#-------------------------------------------------
#
# Project created by QtCreator 2019-01-28T10:03:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Example
TEMPLATE = app

include(./../../Path.pri)

#library
INCLUDEPATH += $$PWD/../../Libraries
LIBS += -L$${DESTDIR} -lQUIKit

SOURCES += main.cpp\
        MainWindow.cpp

HEADERS  += MainWindow.h

FORMS    += MainWindow.ui
