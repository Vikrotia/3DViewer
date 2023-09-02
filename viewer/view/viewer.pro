QT       += core gui opengl openglwidgets widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl openglwidgets concurrent

include(qtgifimage/src/gifimage/qtgifimage.pri)


CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../controller/controller.cpp \
    gif.cpp \
    glwidget.cpp \
    ../main.cpp \
    mainwindow.cpp \
    ../model/parser.cpp

HEADERS += \
    ../controller/controller.h \
    gif.h \
    glwidget.h \
    mainwindow.h \
    ../model/parser.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    im.qrc
