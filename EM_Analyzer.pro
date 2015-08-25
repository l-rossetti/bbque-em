#-------------------------------------------------
#
# Project created by QtCreator 2015-04-25T11:18:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EM_Analyzer
TEMPLATE = app
CONFIG += c++11
#INCLUDEPATH += /home/rh0x/ber-em/barbeque/include/

LIBS += -L/usr/lib/x86_64-linux-gnu -lboost_system -lboost_filesystem -lboost_serialization

SOURCES +=\
    main.cc \
    event.cc \
    event_list_viewer.cc \
    main_window.cc \
    event_manager.cc \
    controller.cc \
    event_wrapper.cc \
    event_wrapper1.cc

HEADERS  += \
    event.h \
    event_list_viewer.h \
    event_manager.h \
    controller.h \
    main_window.h \
    event_wrapper.h \
    event_wrapper1.h

FORMS += \
    event_list_viewer.ui \
    main_window.ui
