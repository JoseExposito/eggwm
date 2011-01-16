TEMPLATE = app
TARGET = eggwm
QT += core \
    gui
OBJECTS_DIR += build
MOC_DIR += build
LIBS += -lX11
//DEFINES = QT_NO_DEBUG_OUTPUT
include(src/eggwm/eggwm.pri)
