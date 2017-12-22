QT += core sql
QT -= gui

CONFIG += c++11

TARGET = 05_PolaczenieZBazaDanych
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    databasesqlite.cpp \
    lekarz.cpp \
    pacjent.cpp \
    wizyta.cpp

HEADERS += \
    databasesqlite.h \
    lekarz.h \
    pacjent.h \
    wizyta.h \
    libs.h
