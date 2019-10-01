TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    player.cpp \
    caveadventure.cpp \
    world.cpp \
    room.cpp \
    creature.cpp \
    trader.cpp \
    inventory.cpp \
    inventorylist.cpp

HEADERS += \
    player.h \
    caveadventure.h \
    world.h \
    room.h \
    creature.h \
    trader.h \
    inventory.h \
    inventorylist.h

