#-------------------------------------------------
#
# Project created by QtCreator 2017-11-22T10:01:38
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SignatureMachine
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    users.cpp \
    adverification.cpp \
    usermainwindow.cpp \
    administermainwindow.cpp \
    userverification.cpp

HEADERS  += mainwindow.h \
    users.h \
    adverification.h \
    usermainwindow.h \
    administermainwindow.h \
    userverification.h \
    userdatabase.h \
    administerdatabase.h

FORMS    += mainwindow.ui \
    users.ui \
    adverification.ui \
    usermainwindow.ui \
    administermainwindow.ui \
    userverification.ui
