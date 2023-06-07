QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    jugar.cpp \
    main.cpp \
    mainwindow.cpp \
    pantalla.cpp \
    personajes.cpp \
    roedor1.cpp \
    zorr.cpp

HEADERS += \
    jugar.h \
    mainwindow.h \
    pantalla.h \
    personajes.h \
    roedor1.h \
    zorr.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pintura.qrc

DISTFILES += \
    pintura/escena1y2_y_nameJuego.png
