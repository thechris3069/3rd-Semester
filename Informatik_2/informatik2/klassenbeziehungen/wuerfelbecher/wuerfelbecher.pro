TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_INCDIR += ../../klassen-objekte-methoden/wuerfel

SOURCES += main.cpp \
    wuerfelbecher.cpp \
    ../../klassen-objekte-methoden/wuerfel/wuerfel.cpp

HEADERS += \
    wuerfelbecher.h \
    ../../klassen-objekte-methoden/wuerfel/wuerfel.h

