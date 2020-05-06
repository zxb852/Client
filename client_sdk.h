#ifndef CLIENT_SDK_H
#define CLIENT_SDK_H

#define Ptz_up 1
#define Ptz_down 2
#define Ptz_left 3
#define Ptz_right 4
#define Ptz_fup 5
#define Ptz_fdown 6
#define Ptz_padd 1
#define Ptz_pdel 2
#define Ptz_pgoto 3

#include "HCNetSDK.h"
#include "LinuxPlayM4.h"
#include <QList>
#include <QVector>
#include "data.h"
#include "scene4.h"

class Client_SDK
{
public:
    Client_SDK();

    QVector<LONG> v_lUserID;
    //初始化
    void SDK_Init();
    //登录设备
    bool SDK_Connect(char *ip,WORD port,char *username,char *password);
    //开启视频流实时更新,type==0 硬件解码 type==1 软解码
    bool Vedio_Stream_Set(LONG lUserID,NET_DVR_PREVIEWINFO struPlayInfo,bool ishard = true);
    //停止录像
    bool Vedio_Stream_stop();
    //录像接口
    bool Vedio_record(LONG lUserID,record_time begin,record_time end,bool isdownload =true,WId wnd =NULL,int port=1,scene4 *ps4=nullptr);
    void Vedio_stop(LONG lUserID);
    bool Vedio_capture(std::string sFileName);
    // 云台接口
    bool Ptz_move(int mode, int speed, int begorend);
    bool Ptz_preset(int mode, int pnum);
    //释放资源
    void SDK_Close();
private:
    int hPlayback;

};

#endif // CLIENT_SDK_H
