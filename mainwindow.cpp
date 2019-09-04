#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ps1=new Scene1();
    ps2=new scene2();
    ps3=new scene3();
    ps4=new scene4();

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

}

MainWindow::~MainWindow()
{
    delete ui;
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
