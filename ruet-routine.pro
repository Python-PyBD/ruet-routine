QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = ruet-routine
TEMPLATE = app
SOURCES += main.cpp \
    routine.cpp
HEADERS += \
    routine.h \
    defines.h
FORMS += \
    routine.ui
RESOURCES += \
    images.qrc
win32: RC_FILE += icon.rc
