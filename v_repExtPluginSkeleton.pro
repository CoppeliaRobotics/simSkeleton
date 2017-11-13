QT -= core
QT -= gui

TARGET = v_repExtPluginSkeleton
TEMPLATE = lib

DEFINES -= UNICODE
DEFINES += QT_COMPIL
CONFIG += shared
INCLUDEPATH += "../include"
INCLUDEPATH += "../include/stack"

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
    DEFINES += WIN_VREP
}

macx {
    DEFINES += MAC_VREP
}

unix:!macx {
    DEFINES += LIN_VREP
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
    v_repExtPluginSkeleton.h \
    ../include/stack/stackBool.h \
    ../include/stack/stackNull.h \
    ../include/stack/stackNumber.h \
    ../include/stack/stackString.h \
    ../include/stack/stackArray.h \
    ../include/stack/stackMap.h \
    ../include/stack/stackObject.h \
    ../include/v_repLib.h

SOURCES += \
    v_repExtPluginSkeleton.cpp \
    ../common/stack/stackBool.cpp \
    ../common/stack/stackNull.cpp \
    ../common/stack/stackNumber.cpp \
    ../common/stack/stackString.cpp \
    ../common/stack/stackArray.cpp \
    ../common/stack/stackMap.cpp \
    ../common/stack/stackObject.cpp \
    ../common/v_repLib.cpp



