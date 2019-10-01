TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    led.cpp \
    taster.cpp \
    lcddisplay.cpp \
    auswurfeinheit.cpp \
    fuellstandserfassung.cpp \
    bonbonautomat.cpp

HEADERS += \
    led.h \
    taster.h \
    lcddisplay.h \
    auswurfeinheit.h \
    fuellstandserfassung.h \
    bonbonautomat.h
