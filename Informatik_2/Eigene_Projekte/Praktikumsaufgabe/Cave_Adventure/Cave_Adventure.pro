TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    player.cpp \
    caveadventure.cpp \
    world.cpp \
    spielfeld.cpp

HEADERS += \
    player.h \
    caveadventure.h \
    world.h \
    spielfeld.h
