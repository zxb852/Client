#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sdk.SDK_Init();
    sdk.SDK_Connect("192.0.0.63",8000,"admin","123456ABC");

    ps1=new Scene1();
    ps2=new scene2();
    ps3=new scene3();
    ps4=new scene4();
    connect(ps4, SIGNAL(Download_Vedio(record_time,record_time,int)), this, SLOT(Download_Vedio(record_time,record_time,int)));  //用一个定时信号来更改时间
    connect(ps4, SIGNAL(Capture()), this, SLOT(Capture()));  //用一个定时信号来更改时间
    connect(ps4, SIGNAL(Play_Vedio(record_time,record_time,int)), this, SLOT(Play_Vedio(record_time,record_time,int)));  //用一个定时信号来更改时间
    connect(ps4, SIGNAL(Stop_vedio()), this, SLOT(Stop_vedio()));  //用一个定时信号来更改时间

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
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));  //用一个定时信号来更改时间
    timer->start(100);  //启动定时

    NET_DVR_PREVIEWINFO struPlayInfo;
    struPlayInfo.hPlayWnd=ps1->getplaywnd(1);
    sdk.Vedio_Stream_Set(sdk.v_lUserID.front(),struPlayInfo);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setsocket(std::shared_ptr<client> ptr)
{
    ptr_client=ptr;
    //timer->start(1000/60);
    qDebug()<<"recv!"<<endl;
}

void MainWindow::Download_Vedio(record_time begin,record_time end,int port)
{
    sdk.Vedio_record(sdk.v_lUserID[0],begin,end,true,ps4->getplaywid(),port,ps4);
}
void MainWindow::Capture()
{
}
void MainWindow::Play_Vedio(record_time begin,record_time end,int port)
{
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
