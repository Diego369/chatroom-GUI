#-------------------------------------------------
#
# Project created by QtCreator 2019-11-21T13:05:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chat
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        chatwidget.cpp \
        login.cpp \
        main.cpp \
        mainwindow.cpp \
        register.cpp

HEADERS += \
        chatwidget.h \
        login.h \
        mainwindow.h \
        register.h

FORMS += \
        chatwidget.ui \
        login.ui \
        mainwindow.ui \
        register.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/MyWidget/ -lchatwidgetplugin
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/MyWidget/ -lchatwidgetplugind
#else:unix: LIBS += -L$$PWD/MyWidget/ -lchatwidgetplugin

#INCLUDEPATH += $$PWD/MyWidget
#DEPENDPATH += $$PWD/MyWidget

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lchatwidgetplugin
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lchatwidgetplugind
#else:unix: LIBS += -L$$PWD/lib/ -lchatwidgetplugin

#INCLUDEPATH += $$PWD/include
#DEPENDPATH += $$PWD/include

RESOURCES += \
    Resource/Resource.qrc
