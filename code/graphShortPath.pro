#-------------------------------------------------
#
# Project created by QtCreator 2016-05-12T00:06:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = graphShortPath
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    edge.cpp \
    graphwidget.cpp \   
    node.cpp

HEADERS  += mainwindow.h \
    edge.h \
    graphwidget.h \
    node.h \
    node.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc
