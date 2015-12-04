#-------------------------------------------------
#
# Project created by QtCreator 2015-10-22T23:45:42
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Boy_And_Dog
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    boy.cpp \
    map.cpp

HEADERS  += mainwindow.h \
    boy.h \
    map.h

FORMS    += mainwindow.ui

#RESOURCES += \
 #   resources.qrc

DISTFILES +=

RESOURCES += \
    Sound_Files/sounds.qrc \
    Sound_Files/image_files.qrc
