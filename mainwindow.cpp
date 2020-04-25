#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),ptr_client(nullptr),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sdk.SDK_Init();
    sdk.SDK_Connect("192.168.1.2",8000,"admin","asdf1234");

    ps1=new Scene1();
    ps2=new scene2();
    ps3=new scene3();
    ps4=new scene4();
    connect(ps4, SIGNAL(Download_Vedio(record_time,record_time,int)), this, SLOT(Download_Vedio(record_time,record_time,int)));  //用一个定时信号来更改时间
    connect(ps4, SIGNAL(Capture()), this, SLOT(Capture()));  //用一个定时信号来更改时间
    connect(ps4, SIGNAL(Play_Vedio(record_time,record_time,int)), this, SLOT(Play_Vedio(record_time,record_time,int)));  //用一个定时信号来更改时间
    connect(ps4, SIGNAL(Stop_vedio()), this, SLOT(Stop_vedio()));  //用一个定时信号来更改时间
    connect(ps1->ps1_jk, SIGNAL(playvedio(int)), this, SLOT( playvedio(int)));  //用一个定时信号来更改时间


    qs_main=new QStackedWidget();
    qs_main->addWidget(ps1);
    qs_main->addWidget(ps2);
    qs_main->addWidget(ps3);
    qs_main->addWidget(ps4);

    ui->scrollArea->setWidget(qs_main);

    ui->pushButton ->setStyleSheet("QPushButton{background:rgb(136, 138, 133);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_2->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_3->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_4->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    qs_main->setCurrentWidget(ps1);

    time = ui->lcdNumber;
    time->setDigitCount(20);     //设置lcd里面的个数，格式是hh：mm：ss，总的是八个。所以设置为8
    time->setPalette(Qt::color0); //设置颜色

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Update()));  //用一个定时信号来更改时间
    timer->start(100);  //启动定时

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
    ptr_client->updata_alarm_data();
}

void MainWindow::Download_Vedio(record_time begin,record_time end,int port)
{
    record_time now;
    now.settimenow();
    if(begin < end && end < now)
        sdk.Vedio_record(sdk.v_lUserID[0],begin,end,true,ps4->getplaywid(),port,ps4);
}
void MainWindow::Capture()
{
}
void MainWindow::Play_Vedio(record_time begin,record_time end,int port)
{
    record_time now;
    now.settimenow();
    if(begin < end && end < now)
        sdk.Vedio_record(sdk.v_lUserID[0],begin,end,false,NULL,port,ps4);
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
    time->display(timestr);  //显示时间
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

void MainWindow::Update()
{
    showTime();

    if(ptr_client!=nullptr)
    {
        State_mes mes;
        unsigned short src,cot;
        //if(ptr_client->recv_buff_pop(mes,tid))
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

            qDebug()<<(int)mes.mode;
            ps1->ps1_jk->addtv(mes.year,mes.mon,mes.day,mes.hour,mes.min,mes.sec,"1号阀厅",ftypes(mes.mode));
        }
    }

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
