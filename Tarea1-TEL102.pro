#-------------------------------------------------
#
# Project created by QtCreator 2017-06-05T00:24:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tarea1-TEL102
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    solicitud.cpp \
    cilindro.cpp \
    camion.cpp \
    loginwindows.cpp \
    camionwindows.cpp \
    adminwindow.cpp

HEADERS  += mainwindow.h \
    solicitud.h \
    cilindro.h \
    camion.h \
    loginwindows.h \
    camionwindows.h \
    adminwindow.h

FORMS    += mainwindow.ui \
    loginwindows.ui \
    camionwindows.ui \
    adminwindow.ui
