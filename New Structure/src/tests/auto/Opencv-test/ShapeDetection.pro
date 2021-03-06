#-------------------------------------------------
#
# Project created by QtCreator 2015-03-26T16:50:13
#
#-------------------------------------------------


TARGET = ShapeDetection
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    shapedetector.cpp \
    main.cpp
win32 {
    INCLUDEPATH += "..\..\deps\files\opencv" \

    CONFIG(debug,debug|release) {
        LIBS += -L"..\\..\\deps\\libs\\opencv\\windows\\x64" \
            -lopencv_core2410d \
            -lopencv_highgui2410d \
            -lopencv_imgproc2410d \

    }

    CONFIG(release,debug|release) {
        DEFINES += QT_NO_WARNING_OUTPUT QT_NO_DEBUG_OUTPUT
        LIBS += -L"..\\..\\deps\\libs\\opencv\\windows\\x64" \
            -lopencv_core2410 \
            -lopencv_highgui2410 \
            -lopencv_imgproc2410 \

    }
}

HEADERS += \
    shapedetector.h
