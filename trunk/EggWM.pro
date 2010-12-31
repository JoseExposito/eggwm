TEMPLATE = app
TARGET = eggwm
QT += core \
    gui
OBJECTS_DIR += build
MOC_DIR += build
//DEFINES = QT_NO_DEBUG_OUTPUT
include(src/eggwm/eggwm.pri)
