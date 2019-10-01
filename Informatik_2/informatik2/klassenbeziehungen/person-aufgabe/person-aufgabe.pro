TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    aufgabe.cpp \
    person_array.cpp \
    person_dynarray.cpp \
    person_vector.cpp

HEADERS += \
    aufgabe.h \
    person_array.h \
    person_dynarray.h \
    person_vector.h

