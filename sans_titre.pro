#-------------------------------------------------
#
# Project created by QtCreator 2019-10-23T23:44:15
#
#-------------------------------------------------

QT       += core gui sql serialport charts printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = sans_titre
TARGET = test_son
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
        main.cpp \
        mainwindow.cpp \
    gerer_client.cpp \
    connexion.cpp \
    client.cpp \
    ajout_client.cpp \
    categorie.cpp \
    gerer_categorie.cpp \
    stat_bib.cpp \
    notification.cpp

HEADERS += \
        mainwindow.h \
    gerer_client.h \
    connexion.h \
    client.h \
    ajout_client.h \
    categorie.h \
    gerer_categorie.h \
    stat_bib.h \
    notification.h

FORMS += \
        mainwindow.ui \
    gerer_client.ui \
    gerer_categorie.ui \
    stat_bib.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
