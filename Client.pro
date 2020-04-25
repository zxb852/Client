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
DEFINES += QT_DEPRECATED_WARNINGS   \
            Linux

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
INCLUDEPATH += ./scene3 \
               ./scene1 \
               ./scene2 \
               ./scene4 \
               ./sdk64  \
               ./sdk64/HCNetSDKCom  \
               ./sdk64/include  \
               "/home/zxb/SRC_C/Socket_connect_v2/socket_connect_v2"\
               "/home/zxb/SRC_C/Socket_connect_v2/socket_connect_v2/base"\
               "/home/zxb/SRC_C/Socket_connect_v2/socket_connect_v2/systems"\
               "/home/zxb/SRC_C/Socket_connect_v2/socket_connect_v2/types"\
               "/usr/local/include" \
               "/usr/local/include/opencv" \
               "/usr/local/include/opencv2"

LIBS += /usr/local/lib/libopencv_calib3d.so\
        /usr/local/lib/libopencv_core.so\
        /usr/local/lib/libopencv_features2d.so\
        /usr/local/lib/libopencv_flann.so\
        /usr/local/lib/libopencv_highgui.so\
        /usr/local/lib/libopencv_imgcodecs.so\
        /usr/local/lib/libopencv_imgproc.so\
        /usr/local/lib/libopencv_ml.so\
        /usr/local/lib/libopencv_objdetect.so\
        /usr/local/lib/libopencv_photo.so\
        /usr/local/lib/libopencv_shape.so\
        /usr/local/lib/libopencv_stitching.so\
        /usr/local/lib/libopencv_superres.so\
        /usr/local/lib/libopencv_videoio.so\
        /usr/local/lib/libopencv_video.so\
        /usr/local/lib/libopencv_videostab.so\
        -lpthread
LIBS += -L./sdk64/ -Wl,-rpath=./:./HCNetSDKCom:./sdk64
LIBS += -lhcnetsdk -lPlayCtrl -lAudioRender -lSuperRender

SOURCES += \
        client_sdk.cpp \
    data.cpp \
        dialog_login.cpp \
        main.cpp \
        mainwindow.cpp \
        scene1/s1_jk.cpp \
        scene1/s1_play.cpp \
        scene1/s1_pz.cpp \
        scene1/s1_yt.cpp \
        scene3/s3_config2.cpp \
        scene3/s3_config3.cpp \
        scene3/s3_fire.cpp \
        scene3/s3_flash.cpp \
        scene3/s3_heat.cpp \
        scene3/s3_heat_add.cpp \
        scene3/s3_water.cpp \
        scene1/scene1.cpp \
        scene2/scene2.cpp \
        scene3/scene3.cpp \
        scene3/s3_config1_xt.cpp \
        scene4/scene4.cpp \
        ../../SRC_C/Socket_connect_v2/socket_connect_v2/socket_connect_v2.cpp   \
        ../../SRC_C/Socket_connect_v2/socket_connect_v2/base/socket_base.cpp   \
        ../../SRC_C/Socket_connect_v2/socket_connect_v2/systems/imp.cpp   \
        ../../SRC_C/Socket_connect_v2/socket_connect_v2/systems/log.cpp   \
        ../../SRC_C/Socket_connect_v2/socket_connect_v2/types/frame.cpp   \
        ../../SRC_C/Socket_connect_v2/socket_connect_v2/types/type_base.cpp   \
        ../../SRC_C/Socket_connect_v2/socket_connect_v2/types/types.cpp

HEADERS += \
        client_sdk.h \
        data.h \
        dialog_login.h \
        mainwindow.h \
        scene1/s1_jk.h \
        scene1/s1_play.h \
        scene1/s1_pz.h \
        scene1/s1_yt.h \
        scene3/s3_config2.h \
        scene3/s3_config3.h \
        scene3/s3_fire.h \
        scene3/s3_flash.h \
        scene3/s3_heat.h \
        scene3/s3_heat_add.h \
        scene3/s3_water.h \
        scene1/scene1.h \
        scene2/scene2.h \
        scene3/scene3.h \
        scene3/s3_config1_xt.h \
        scene4/scene4.h \
        sdk64/include/HCNetSDK.h \
        sdk64/include/LinuxPlayM4.h \
        ../../SRC_C/Socket_connect_v2/socket_connect_v2/socket_connect_v2.h

FORMS += \
        dialog_login.ui \
        mainwindow.ui \
        scene1/s1_jk.ui \
        scene1/s1_play.ui \
        scene1/s1_pz.ui \
        scene1/s1_yt.ui \
        scene3/s3_config2.ui \
        scene3/s3_config3.ui \
        scene3/s3_fire.ui \
        scene3/s3_flash.ui \
        scene3/s3_heat.ui \
        scene3/s3_heat_add.ui \
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
