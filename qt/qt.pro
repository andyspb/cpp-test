TEMPLATE = app
CONFIG += console
CONFIG -= qt

DEFINES += __GXX_EXPERIMENTAL_CXX0X__

LIBS += -lpthread
LIBS += /usr/lib/libboost_thread.a
LIBS += /usr/lib/libboost_system.a

INCLUDEPATH += ../src/algoritms/
INCLUDEPATH += ../src/boost/
INCLUDEPATH += ../src/cpp0x/
INCLUDEPATH += ../src/cracking_code_interview/
INCLUDEPATH += ../src/func/

HEADERS += algoritms.h
HEADERS += boosts.h
HEADERS += cpp0x.h
HEADERS += cracking.h
HEADERS += func.h

SOURCES += main.cpp
