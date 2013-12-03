TEMPLATE = app
CONFIG += console
CONFIG -= qt

DEPENDPATH += ../src/virtuals/

#DEFINES += -MD

LIBS += -lpthread
LIBS += /usr/lib/libboost_thread.a
LIBS += /usr/lib/libboost_system.a

INCLUDEPATH += ../src/algoritms/
INCLUDEPATH += ../src/boost/
#INCLUDEPATH += ../src/cpp0x/
INCLUDEPATH += ../src/cracking_code_interview/
INCLUDEPATH += ../src/func/
INCLUDEPATH += ../src/virtual/
HEADERS += boosts.h
HEADERS += cpp0x.h
HEADERS += cracking.h
HEADERS += func.h

#virtuals
HEADERS += virtuals.h
HEADERS += virt_access.h
HEADERS += virt_cast_1.h
HEADERS += virt_cast_2.h
HEADERS += virt_func_1.h
HEADERS += virt_func_2.h
HEADERS += virt_func_3.h
HEADERS += virt_func_4.h
HEADERS += virt_func_5.h
HEADERS += virt_func_6.h
HEADERS += virt_func_7.h
HEADERS += virt_func_8.h
HEADERS += virt_func_9.h


SOURCES += main.cpp
