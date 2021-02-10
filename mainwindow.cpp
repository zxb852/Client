#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),ptr_client(nullptr),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化sdk模块，并连接设备
    sdk.SDK_Init();
    sdk.SDK_Connect("192.168.1.2",8000,"admin","asdf1234");

    // 创建4个子窗口
    ps1=new Scene1();
    ps2=new scene2();
    ps3=new scene3();
    ps4=new scene4();

    // 设置信号-槽相应函数
    connect(ps1->ps1_yt, SIGNAL(ptz_move(int,int)), this, SLOT(ptz_move(int,int)));
    connect(ps1->ps1_yt, SIGNAL(ptz_prset(int,int)), this, SLOT(ptz_prset(int,int)));
    connect(ps1->ps1_jk, SIGNAL(playvedio(int)), this, SLOT(playvedio(int)));  //用一个定时信号来更改时间
    connect(ps1->ps1_jk, SIGNAL(dection_switch(int)), this, SLOT(dection_switch(int)));

    connect(ps2, SIGNAL(callforplot(QDate)), this, SLOT(callforplot(QDate)));
    connect(this, SIGNAL(returnforplot(string)), ps2, SLOT(returnforplot(string)));

    connect(ps3->ps3_heat, SIGNAL(cmd1()), this, SLOT(cmd1()));

    connect(ps4, SIGNAL(Download_Vedio(record_time,record_time,int)), this, SLOT(Download_Vedio(record_time,record_time,int)));  //用一个定时信号来更改时间
    connect(ps4, SIGNAL(Capture()), this, SLOT(Capture()));  //用一个定时信号来更改时间
    connect(ps4, SIGNAL(Play_Vedio(record_time,record_time,int)), this, SLOT(Play_Vedio(record_time,record_time,int)));  //用一个定时信号来更改时间
    connect(ps4, SIGNAL(Stop_vedio()), this, SLOT(Stop_vedio()));  //用一个定时信号来更改时间




    //将子窗口添加进QStackedWidget
    qs_main=new QStackedWidget();
    qs_main->addWidget(ps1);
    qs_main->addWidget(ps2);
    qs_main->addWidget(ps3);
    qs_main->addWidget(ps4);

    // 将QStackedWidget添加进QScrollArea
    ui->scrollArea->setWidget(qs_main);

    // 设置按钮字体
    ui->pushButton ->setStyleSheet("QPushButton{background:rgb(136, 138, 133);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_2->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_3->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_4->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    // 设置当前焦点子窗口
    qs_main->setCurrentWidget(ps1);

    // 设置LCD
    ldctime = ui->lcdNumber;
    ldctime->setDigitCount(20);     //设置lcd里面的个数，格式是hh：mm：ss，总的是八个。所以设置为8
    ldctime->setPalette(Qt::color0); //设置颜色

    // 设置定时器与定时函数
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Update()));  //用一个定时信号来更改时间
    timer->start(100);  //启动定时

    // 设置预览
    NET_DVR_PREVIEWINFO struPlayInfo;
        //RGB
    struPlayInfo.hPlayWnd=ps1->getplaywnd(1);
    struPlayInfo.lChannel = 33; //预览通道号
    sdk.Vedio_Stream_Set(sdk.v_lUserID.front(),struPlayInfo);

        //IR
    struPlayInfo.hPlayWnd=ps1->getplaywnd(2);
    struPlayInfo.lChannel = 34; //预览通道号
    sdk.Vedio_Stream_Set(sdk.v_lUserID.front(),struPlayInfo);

        //UV
    struPlayInfo.hPlayWnd=ps1->getplaywnd(3);
    struPlayInfo.lChannel = 35; //预览通道号
    sdk.Vedio_Stream_Set(sdk.v_lUserID.front(),struPlayInfo);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setsocket(std::shared_ptr<Client> ptr)
{
    ptr_client=ptr;
    base=ptr_client->getbasefile();
    //timer->start(1000/60);
    Command cmd;
    cmd.type = 15;  //  all on
    ptr_client -> sendbuff_push(cmd,1);
    ptr_client->updata_alarm_data();

}

void MainWindow::Download_Vedio(record_time begin,record_time end,int port)
{
    record_time now;
    now.settimenow();
    if(begin < end && end < now)
    {
        qDebug()<<"download video";
        qDebug()<<(int)begin.year << " "<<(int)begin.month << " "<<(int)begin.day << " "<<(int)begin.hour << " "<<(int)begin.min << " "<<(int)begin.sec;
        qDebug()<<(int)end.year << " "<<(int)end.month << " "<<(int)end.day << " "<<(int)end.hour << " "<<(int)end.min << " "<<(int)end.sec;
        sdk.Vedio_record(sdk.v_lUserID[0],begin,end,true,ps4->getplaywid(),port,ps4);
    }
}

int Capturenum = 0;
void MainWindow::Capture()
{
    string nume = "/home/zxb/SRC_C/data/capture/" + to_string(++Capturenum)+".jpg";
    sdk.Vedio_capture(nume);
}
void MainWindow::Play_Vedio(record_time begin,record_time end,int port)
{
    record_time now;
    now.settimenow();
    if(begin < end && end < now)
    {
        qDebug()<<"play video";
        qDebug()<<(int)begin.year << " "<<(int)begin.month << " "<<(int)begin.day << " "<<(int)begin.hour << " "<<(int)begin.min << " "<<(int)begin.sec;
        qDebug()<<(int)end.year << " "<<(int)end.month << " "<<(int)end.day << " "<<(int)end.hour << " "<<(int)end.min << " "<<(int)end.sec;
        if(!sdk.Vedio_record(sdk.v_lUserID[0],begin,end,false,ps4->getplaywid(),port,ps4))
            printf("record play failed!");
    }
}
void MainWindow::Stop_vedio()
{
    sdk.Vedio_stop(sdk.v_lUserID[0]);
}

void MainWindow::on_pushButton_clicked()
{
    ui->pushButton ->setStyleSheet("QPushButton{background:rgb(136, 138, 133);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_2->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_3->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_4->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    qs_main->setCurrentWidget(ps1);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_2->setStyleSheet("QPushButton{background:rgb(136, 138, 133);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_3->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_4->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    qs_main->setCurrentWidget(ps3);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->pushButton->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_2->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_3->setStyleSheet("QPushButton{background:rgb(136, 138, 133);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_4->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    qs_main->setCurrentWidget(ps2);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->pushButton->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_2->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_3->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_4->setStyleSheet("QPushButton{background:rgb(136, 138, 133);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    qs_main->setCurrentWidget(ps4);
}

void MainWindow::showTime()
{
    QString timestr = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"); //设置时间格式
    ldctime->display(timestr);  //显示时间
}

void MainWindow::playvedio(int mode)
{
    Mat show;
    int index=ps1->ps1_jk->getselect();
    if(index>=v_alarm.size())
        return;
    if(mode==1)
    {
        show=imread(v_alarm[index].second[0]);
        QImage image = MatToQImage(show);
        QPixmap pixmap = QPixmap::fromImage(image);
        pixmap=pixmap.scaled(QSize(512,384));
        ps1->getplaywnd4()->setPixmap(pixmap);
    }
    else if(mode==2)
    {
        show=imread(v_alarm[index].second[1]);
        QImage image = MatToQImage(show);
        QPixmap pixmap = QPixmap::fromImage(image);
        pixmap=pixmap.scaled(QSize(512,384));
        ps1->getplaywnd4()->setPixmap(pixmap);
    }
    else if(mode==3)
    {
        show=imread(v_alarm[index].second[2]);
        QImage image = MatToQImage(show);
        QPixmap pixmap = QPixmap::fromImage(image);
        pixmap=pixmap.scaled(QSize(512,384));
        ps1->getplaywnd4()->setPixmap(pixmap);
    }
    else
    {
        cv::VideoCapture vcapture;
        vcapture.open(v_alarm[index].second[3]);
        Mat frame;
        vcapture.read(frame);
        if (frame.empty())
            return;
        while(!frame.empty())
        {
            QImage image = MatToQImage(frame);
            QPixmap pixmap = QPixmap::fromImage(image);
            pixmap=pixmap.scaled(QSize(512,384));
            ps1->getplaywnd4()->setPixmap(pixmap);
            vcapture.read(frame);
            if (frame.empty())
                break;
            cvWaitKey(1);
            usleep(36000);
        }
        vcapture.release();
    }
}

void MainWindow::dection_switch(int mode)
{
    Command cmd;

    if(mode == 7)
        cmd.type=21;
    else if(mode == 8)
        cmd.type=22;

    if(mode == 5)
        cmd.type = 15;  //  all on
    else if(mode == 6)
        cmd.type = 10;  //  all off
    else if(mode == 1)
        cmd.type = 11;  //  heat on
    else if(mode == 2)
        cmd.type = 13;  //  fire on
    else if(mode == 3)
        cmd.type = 14;  //  water on
    else if(mode == 4)
        cmd.type = 12;  //  flash on

    ptr_client -> sendbuff_push(cmd,1);
}

void MainWindow::Update()
{
    showTime();
    if(ptr_client!=nullptr)
    {
        // 当接收到故障警报
        State_mes mes;
        unsigned short src,cot;
        if(ptr_client->recvbuff_pop(mes,src,cot))
        {
            string filename=mes.tostring();
            string pic_rgb=base + filename+ "/" +filename+ "_rgb.jpg";
            string pic_ir=base+ filename+ "/" +filename+ "_ir.jpg";
            string pic_uv=base+ filename+ "/" +filename+ "_uv.jpg";
            string vedio_rgb=base+ filename+ "/" +filename+ "_vedio.mp4";

            vector<string> names;
            names.push_back(pic_rgb);
            names.push_back(pic_ir);
            names.push_back(pic_uv);
            names.push_back(vedio_rgb);

            v_alarm.push_back(pair<State_mes,vector<string>>(mes,names));

            qDebug()<< "recv alarm mode :"<<(int)mes.mode;
            ps1->ps1_jk->addtv(mes.year,mes.mon,mes.day,mes.hour,mes.min,mes.sec,"1号阀厅",ftypes(mes.mode));

            // 弹出警报框
            record_time recvt(mes.year, mes.mon, mes.day, mes.hour, mes.min,mes.sec + 30);
            record_time nowt;
            nowt.settimenow();
            if(nowt < recvt)
            {
                Dialog_alarm *da = new Dialog_alarm;
                da->settype(mes.mode);
                da->show();
            }

        }
        // 当接收到历史曲线
        string plotname;
        if(ptr_client->recvbuff_pop_plotdata(plotname))
        {
            emit returnforplot(plotname);
        }
    }

}

void MainWindow::ptz_move(int mode,int speed)
{
    sdk.Ptz_move(mode,speed,0);
    usleep(500000);
    sdk.Ptz_move(mode,speed,1);
}

void MainWindow::ptz_prset(int mode,int pnum)
{
    sdk.Ptz_preset(mode,pnum);
}

void MainWindow::cmd1()
{
    Command cmd;
    cmd.type = 1;
    ptr_client->sendbuff_push(cmd,1);
}

void MainWindow::callforplot(QDate t)
{
    QString filename = QString::number(t.year())+"-"+QString::number(t.month())+"-"+QString::number(t.day());
    QString basedir = "/home/zxb/SRC_C/data/Client_plotdata/";
    QString qf = basedir+filename;

    ptr_client->Setplotdataname(qf.toStdString());
    ptr_client->callforplot(t.year(),t.month(),t.day());    // 请求数据
}

Mat QImage2cvMat(QImage image)
{
    cv::Mat mat;
    qDebug() << image.format();
    switch(image.format())
    {
    case QImage::Format_ARGB32:
        break;
    case QImage::Format_RGB32:
        break;
    case QImage::Format_ARGB32_Premultiplied:
        mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
        break;
    case QImage::Format_RGB888:
        mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
        cvtColor(mat, mat, CV_BGR2RGB);
        break;
    case QImage::Format_Indexed8:
        mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
        break;
    default:
        break;
    }
    return mat;
}

QImage MatToQImage(const cv::Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        qDebug() << "CV_8UC4";
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}
