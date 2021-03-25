QT       += core gui
QT       += widgets charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    canal_pret.cpp \
    connexion.cpp \
    main.cpp \
    mainwindow.cpp \
    vue_banquier.cpp \
    vue_president.cpp

HEADERS += \
    canal_pret.h \
    connexion.h \
    mainwindow.h \
    vue_banquier.h \
    vue_president.h

FORMS += \
    canal_pret.ui \
    connexion.ui \
    mainwindow.ui \
    vue_banquier.ui \
    vue_president.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
