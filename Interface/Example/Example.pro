#-------------------------------------------------
#
# Project created by QtCreator 2015-05-19T16:26:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Example
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    bar.cpp \
    inventory.cpp \
    colision.cpp \
    rectangle.cpp

HEADERS  += widget.h \
    bar.h \
    inventory.h \
    colision.h \
    rectangle.h

FORMS    += widget.ui
