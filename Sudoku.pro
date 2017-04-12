TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    grid.c \
    util.c \
    logic.c \
    generator.c \
    gameManagement.c

HEADERS += \
    grid.h \
    util.h \
    logic.h \
    generator.h \
    gameManagement.h

DISTFILES +=

