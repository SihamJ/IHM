QT       += core gui
QT       += widgets charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    banquier.cpp \
    canal_bancaire.cpp \
    connection.cpp \
    details.cpp \
    guide.cpp \
    main.cpp \
    mainwindow.cpp \
    pret.cpp \
    pret_banquier.cpp \
    principale.cpp

HEADERS += \
    banquier.h \
    canal_bancaire.h \
    connection.h \
    details.h \
    guide.h \
    mainwindow.h \
    pret.h \
    pret_banquier.h \
    principale.h

FORMS += \
    banquier.ui \
    canal_bancaire.ui \
    connection.ui \
    details.ui \
    guide.ui \
    mainwindow.ui \
    pret.ui \
    pret_banquier.ui \
    principale.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressource.qrc \
    ressource.qrc
