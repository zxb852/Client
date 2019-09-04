#-------------------------------------------------
#
# Project created by QtCreator 2019-09-03T15:09:32
#
#-------------------------------------------------

QT       += core gui
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
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
INCLUDEPATH += ./scene3 \
               ./scene1 \
               ./scene2 \
               ./scene4

SOURCES += \
        dialog_login.cpp \
        main.cpp \
        mainwindow.cpp \
        scene1/s1_jk.cpp \
        scene1/s1_play.cpp \
        scene1/s1_pz.cpp \
        scene1/s1_yt.cpp \
        scene3/s3_fire.cpp \
        scene3/s3_flash.cpp \
        scene3/s3_heat.cpp \
        scene3/s3_water.cpp \
        scene1/scene1.cpp \
        scene2/scene2.cpp \
        scene3/scene3.cpp \
        scene3/s3_config1_xt.cpp \
        scene4/scene4.cpp

HEADERS += \
        dialog_login.h \
        mainwindow.h \
        scene1/s1_jk.h \
        scene1/s1_play.h \
        scene1/s1_pz.h \
        scene1/s1_yt.h \
        scene3/s3_fire.h \
        scene3/s3_flash.h \
        scene3/s3_heat.h \
        scene3/s3_water.h \
        scene1/scene1.h \
        scene2/scene2.h \
        scene3/scene3.h \
        scene3/s3_config1_xt.h \
        scene4/scene4.h

FORMS += \
        dialog_login.ui \
        mainwindow.ui \
        scene1/s1_jk.ui \
        scene1/s1_play.ui \
        scene1/s1_pz.ui \
        scene1/s1_yt.ui \
        scene3/s3_fire.ui \
        scene3/s3_flash.ui \
        scene3/s3_heat.ui \
        scene3/s3_water.ui \
        scene1/scene1.ui \
        scene2/scene2.ui \
        scene3/scene3.ui \
        scene3/s3_config1_xt.ui \
        scene4/scene4.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
