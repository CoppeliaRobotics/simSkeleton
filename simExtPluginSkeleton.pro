QT -= core
QT -= gui

TARGET = simExtPluginSkeleton
TEMPLATE = lib

DEFINES -= UNICODE
DEFINES += QT_COMPIL
CONFIG += shared plugin
INCLUDEPATH += "../include"

*-msvc* {
    QMAKE_CXXFLAGS += -O2
    QMAKE_CXXFLAGS += -W3
}
*-g++* {
    QMAKE_CXXFLAGS += -O3
    QMAKE_CXXFLAGS += -Wall
    QMAKE_CXXFLAGS += -Wno-unused-parameter
    QMAKE_CXXFLAGS += -Wno-strict-aliasing
    QMAKE_CXXFLAGS += -Wno-empty-body
    QMAKE_CXXFLAGS += -Wno-write-strings

    QMAKE_CXXFLAGS += -Wno-unused-but-set-variable
    QMAKE_CXXFLAGS += -Wno-unused-local-typedefs
    QMAKE_CXXFLAGS += -Wno-narrowing

    QMAKE_CFLAGS += -O3
    QMAKE_CFLAGS += -Wall
    QMAKE_CFLAGS += -Wno-strict-aliasing
    QMAKE_CFLAGS += -Wno-unused-parameter
    QMAKE_CFLAGS += -Wno-unused-but-set-variable
    QMAKE_CFLAGS += -Wno-unused-local-typedefs
}

win32 {
    DEFINES += WIN_SIM
}

macx {
    DEFINES += MAC_SIM
}

unix:!macx {
    DEFINES += LIN_SIM
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

HEADERS += \
    simExtPluginSkeleton.h \
    ../include/stack/stackBool.h \
    ../include/stack/stackNull.h \
    ../include/stack/stackNumber.h \
    ../include/stack/stackString.h \
    ../include/stack/stackArray.h \
    ../include/stack/stackMap.h \
    ../include/stack/stackObject.h \
    ../include/simLib.h

SOURCES += \
    simExtPluginSkeleton.cpp \
    ../include/stack/stackBool.cpp \
    ../include/stack/stackNull.cpp \
    ../include/stack/stackNumber.cpp \
    ../include/stack/stackString.cpp \
    ../include/stack/stackArray.cpp \
    ../include/stack/stackMap.cpp \
    ../include/stack/stackObject.cpp \
    ../include/simLib.cpp



