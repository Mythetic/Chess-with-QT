#-------------------------------------------------
#
# Project created by QtCreator 2017-03-06T20:07:07
#
#-------------------------------------------------

QT       += core gui
CONFIG +=C++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chess
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

RESOURCES += \
    image.qrc
