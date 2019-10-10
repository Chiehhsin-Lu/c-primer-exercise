#-------------------------------------------------
#
# Project created by QtCreator 2019-09-26T10:03:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = primer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sales_data.cpp \
    screen.cpp \
    window_mgr.cpp \
    quote.cpp \
    bulk_quote.cpp \
    disc_quote.cpp \
    hasptr.cpp \
    message.cpp \
    folder.cpp

HEADERS  += mainwindow.h \
    sales_data.h \
    screen.h \
    window_mgr.h \
    quote.h \
    bulk_quote.h \
    disc_quote.h \
    hasptr.h \
    message.h \
    folder.h

FORMS    += mainwindow.ui
