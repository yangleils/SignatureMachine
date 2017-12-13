#-------------------------------------------------
#
# Project created by QtCreator 2017-11-22T10:01:38
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SignatureMachine
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    users.cpp \
    adverification.cpp \
    usermainwindow.cpp \
    administermainwindow.cpp \
    userverification.cpp \
    ssql.cpp \
    communication.cpp \
    processthread.cpp

HEADERS  += mainwindow.h \
    users.h \
    adverification.h \
    usermainwindow.h \
    administermainwindow.h \
    userverification.h \
    userdatabase.h \
    administerdatabase.h \
    ssql.h \
    communication.h \
    processthread.h

FORMS    += mainwindow.ui \
    users.ui \
    adverification.ui \
    usermainwindow.ui \
    administermainwindow.ui \
    userverification.ui \
    communication.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../Study_Software/opencv320/lib/ -lopencv_world320
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../Study_Software/opencv320/lib/ -lopencv_world320d
else:unix: LIBS += -L$$PWD/../../../../Study_Software/opencv320/lib/ -lopencv_world320

INCLUDEPATH += $$PWD/../../../../Study_Software/opencv320/include
DEPENDPATH += $$PWD/../../../../Study_Software/opencv320/include
