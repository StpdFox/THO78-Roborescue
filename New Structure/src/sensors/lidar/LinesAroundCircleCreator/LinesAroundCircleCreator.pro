#-------------------------------------------------
#
# Project created by QtCreator 2015-04-18T22:41:16
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = LinesAroundCircleCreator
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    circledetector.cpp

win32 {
    INCLUDEPATH += "C:\\opencv\\build\\include" \

    CONFIG(debug,debug|release) {
        LIBS += -L"C:\\opencv\\build\\x64\\vc12\\lib" \
            -lopencv_core2410d \
            -lopencv_highgui2410d \
            -lopencv_imgproc2410d \
            -lopencv_features2d2410d \
            -lopencv_calib3d2410d
    }

    CONFIG(release,debug|release) {
        DEFINES += QT_NO_WARNING_OUTPUT QT_NO_DEBUG_OUTPUT
        LIBS += -L"C:\\opencv\\build\\x64\\vc12\\lib" \
            -lopencv_core2410 \
            -lopencv_highgui2410 \
            -lopencv_imgproc2410 \
            -lopencv_features2d2410 \
            -lopencv_calib3d2410
    }
}

HEADERS += \
    circledetector.h
