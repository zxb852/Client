#include "client_sdk.h"
#include <QtDebug>
#include <unistd.h>
#include <QTime>

Client_SDK::Client_SDK()
{

}

void CALLBACK g_ExceptionCallBack(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser)
{
    char tempbuf[256] = {0};
    switch(dwType)
    {
    case EXCEPTION_RECONNECT:
        //预览时重连
        printf("----------reconnect--------%d\n", time(NULL));
        break;
    default:
        break;
    }
}
void CALLBACK g_RealDataCallBack_V30(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,void* dwUser){}

//初始化
void Client_SDK::SDK_Init()
{
    NET_DVR_Init();
    //设置连接时间与重连时间
    NET_DVR_SetConnectTime(2000, 1);
    NET_DVR_SetReconnect(10000, true);
}
//登录设备
bool Client_SDK::SDK_Connect(char *ip,WORD port,char *username,char *password)
{
    NET_DVR_DEVICEINFO_V30 struDeviceInfo;
    LONG lUserID = NET_DVR_Login_V30(ip, port, username, password, &struDeviceInfo);
    if (lUserID < 0){
        printf("Login error, %d\n", NET_DVR_GetLastError());
        NET_DVR_Cleanup();
        return false;
    }
    else
        qDebug()<<"NVR lUserID is "<<lUserID;
    v_lUserID.push_back(lUserID);

//  登录rgb设备，控制云台
    lUserID = NET_DVR_Login_V30("192.168.1.64", 8000, "admin", "asdf1234", &struDeviceInfo);
    if (lUserID < 0){
        printf("Login error, %d\n", NET_DVR_GetLastError());
        NET_DVR_Cleanup();
        return false;
    }
    else
        qDebug()<<"UV lUserID is "<<lUserID;
    v_lUserID.push_back(lUserID);

    //设置异常消息回调函数
    NET_DVR_SetExceptionCallBack_V30(0, nullptr,g_ExceptionCallBack, nullptr);
    return true;
}

bool Client_SDK::Vedio_Stream_Set(LONG lUserID,NET_DVR_PREVIEWINFO struPlayInfo,bool ishard)
{
    LONG lRealPlayHandle;
    struPlayInfo.dwStreamType = 0; //0-主码流,1-子码流,2-码流 3,3-码流 4,以此类推
    struPlayInfo.dwLinkMode = 0;//0- TCP 方式,1- UDP 方式,2- 多播方式,3- RTP 方式,4-RTP/RTSP,5-RSTP/HTTP
    struPlayInfo.bBlocked = 1;//0- 非阻塞取流,1- 阻塞取流
    struPlayInfo.dwDisplayBufNum = 1;


    lRealPlayHandle = NET_DVR_RealPlay_V40(lUserID, &struPlayInfo, nullptr, nullptr);

    if (lRealPlayHandle < 0)
    {
        printf("NET_DVR_RealPlay_V40 error error id : %d \n", (int)NET_DVR_GetLastError());

        NET_DVR_Logout(lUserID);
        NET_DVR_Cleanup();
        return false;
    }
    return true;
}


//录像接口
bool Client_SDK::Vedio_record(LONG lUserID,record_time begin,record_time end,bool isdownload,WId wnd,int port,scene4 *ps4)
{
    time_t timep;
    time(&timep);
    tm *nowTime= localtime(&timep);
    record_time now(nowTime);
    if(now<end){
        sleep(1);
        if(now<end)
            return false;
    }

    if(isdownload){
        NET_DVR_PLAYCOND struDownloadCond={0};
        struDownloadCond.dwChannel=port; //通道号
        struDownloadCond.struStartTime.dwYear = begin.year; //开始时间
        struDownloadCond.struStartTime.dwMonth = begin.month;
        struDownloadCond.struStartTime.dwDay = begin.day;
        struDownloadCond.struStartTime.dwHour = begin.hour;
        struDownloadCond.struStartTime.dwMinute = begin.min;
        struDownloadCond.struStartTime.dwSecond =begin.sec;

        struDownloadCond.struStopTime.dwYear= end.year; //结束时间
        struDownloadCond.struStopTime.dwMonth = end.month;
        struDownloadCond.struStopTime.dwDay = end.day;
        struDownloadCond.struStopTime.dwHour = end.hour;
        struDownloadCond.struStopTime.dwMinute = end.min;
        struDownloadCond.struStopTime.dwSecond= end.sec;
        //---------------------------------------
        //按时间下载
        hPlayback = NET_DVR_GetFileByTime_V40(lUserID, "./test.mp4",&struDownloadCond);
    }
    else {
        NET_DVR_VOD_PARA struVodPara={0};
        struVodPara.dwSize=sizeof(struVodPara);
        struVodPara.struIDInfo.dwChannel=port; //通道号
        struVodPara.hWnd=wnd; //回放窗口

        struVodPara.struBeginTime.dwYear = begin.year; //开始时间
        struVodPara.struBeginTime.dwMonth = begin.month;
        struVodPara.struBeginTime.dwDay = begin.day;
        struVodPara.struBeginTime.dwHour = begin.hour;
        struVodPara.struBeginTime.dwMinute = begin.min;
        struVodPara.struBeginTime.dwSecond =begin.sec;

        struVodPara.struEndTime.dwYear = end.year; //结束时间
        struVodPara.struEndTime.dwMonth = end.month;
        struVodPara.struEndTime.dwDay = end.day;
        struVodPara.struEndTime.dwHour = end.hour;
        struVodPara.struEndTime.dwMinute = end.min;
        struVodPara.struEndTime.dwSecond = end.sec;
        //---------------------------------------
        //按时间回放
        hPlayback = NET_DVR_PlayBackByTime_V40(lUserID, &struVodPara);
    }
    if(hPlayback < 0)
    {
        printf("Vedio failed,last error %d\n",NET_DVR_GetLastError());
        NET_DVR_Logout(lUserID);
        NET_DVR_Cleanup();
        return false;
    }
    //---------------------------------------
    //开始
    if(!NET_DVR_PlayBackControl_V40(hPlayback, NET_DVR_PLAYSTART,NULL, 0, NULL,NULL))
    {
        printf("play back control failed [%d]\n",NET_DVR_GetLastError());
        NET_DVR_Logout(lUserID);
        NET_DVR_Cleanup();
        return false;
    }

    if(isdownload)
    {
        int nPos = 0;
        for(nPos = 0; nPos < 100&&nPos>=0; nPos = NET_DVR_GetDownloadPos(hPlayback))
        {
            ps4->process(nPos);
            usleep(5000);
        }
        ps4->process(100);

        if(!NET_DVR_StopGetFile(hPlayback))
        {
            printf("failed to stop get file [%d]\n",NET_DVR_GetLastError());
            return false;
        }
    }
    return true;
}

void Client_SDK::Vedio_stop(LONG lUserID)
{
    if(hPlayback < 0)
        return;
    else if(!NET_DVR_StopPlayBack(hPlayback))
    {
        printf("failed to stop file [%d]\n",NET_DVR_GetLastError());
        NET_DVR_Logout(lUserID);
        NET_DVR_Cleanup();
        return ;
    }
}

bool Client_SDK::Vedio_capture(std::string s)
{
    char *p = new char[s.length() + 1];
    s.copy(p, std::string::npos);
    p[s.length()] = 0;
    NET_DVR_PlayBackCaptureFile(hPlayback, p);
    delete [] p;
}

// 云台接口
bool Client_SDK::Ptz_move(int mode, int speed, int begorend)
{
    LONG tmpuid=v_lUserID[1],tmpc=1;
    switch(mode)
    {
    case Ptz_up:
        return NET_DVR_PTZControlWithSpeed_Other(tmpuid,tmpc,TILT_UP,begorend,speed);
        break;
    case Ptz_down:
        return NET_DVR_PTZControlWithSpeed_Other(tmpuid,tmpc,TILT_DOWN,begorend,speed);
        break;
    case Ptz_left:
        return NET_DVR_PTZControlWithSpeed_Other(tmpuid,tmpc,PAN_LEFT,begorend,speed);
        break;
    case Ptz_right:
        return NET_DVR_PTZControlWithSpeed_Other(tmpuid,tmpc,PAN_RIGHT,begorend,speed);
        break;
    case Ptz_fup:
        return NET_DVR_PTZControlWithSpeed_Other(tmpuid,tmpc,FOCUS_NEAR,begorend,speed);
        break;
    case Ptz_fdown:
        return NET_DVR_PTZControlWithSpeed_Other(tmpuid,tmpc,FOCUS_FAR,begorend,speed);
        break;
    default:
        break;
    }
}

bool Client_SDK::Ptz_preset(int mode, int pnum)
{
    LONG tmpuid=v_lUserID[1],tmpc=1;
    switch(mode)
    {
    case Ptz_padd:
        return NET_DVR_PTZPreset_Other(tmpuid,tmpc,SET_PRESET,pnum);
        break;
    case Ptz_pdel:
        return NET_DVR_PTZPreset_Other(tmpuid,tmpc,CLE_PRESET,pnum);
        break;
    case Ptz_pgoto:
        return NET_DVR_PTZPreset_Other(tmpuid,tmpc,GOTO_PRESET,pnum);
        break;
    default:
        break;
    }
}

//释放资源
void Client_SDK::SDK_Close()
{
    //注销用户
    for(LONG lUserID :v_lUserID)
        NET_DVR_Logout(lUserID);
    //释放 SDK 资源
    NET_DVR_Cleanup();
}
