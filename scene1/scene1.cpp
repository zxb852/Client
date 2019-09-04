#include "scene1.h"
#include "ui_scene1.h"

Scene1::Scene1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Scene1)
{
    ui->setupUi(this);

    ps1_play=new s1_play();
    ps1_jk=new s1_jk();
    ps1_pz=new s1_pz();
    ps1_yt=new s1_yt();

    qs_s1_play=new QStackedWidget();
    qs_s1_right=new QStackedWidget();
    qs_s1_play->addWidget(ps1_play);
    qs_s1_right->addWidget(ps1_jk);
    qs_s1_right->addWidget(ps1_pz);
    qs_s1_right->addWidget(ps1_yt);

    qs_s1_play->setCurrentWidget(ps1_play);
    qs_s1_right->setCurrentWidget(ps1_jk);

    ui->scrollArea->setWidget(qs_s1_play);
    ui->scrollArea_2->setWidget(qs_s1_right);

    ui->pushButton_3->setStyleSheet("QPushButton{background:rgb(136, 138, 133);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_4->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_5->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    qs_s1_right->setCurrentWidget(ps1_jk);
}

Scene1::~Scene1()
{
    delete ui;
}

void Scene1::on_pushButton_3_clicked()
{
    ui->pushButton_3->setStyleSheet("QPushButton{background:rgb(136, 138, 133);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_4->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_5->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    qs_s1_right->setCurrentWidget(ps1_jk);

}

void Scene1::on_pushButton_4_clicked()
{
    ui->pushButton_3->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_4->setStyleSheet("QPushButton{background:rgb(136, 138, 133);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_5->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    qs_s1_right->setCurrentWidget(ps1_pz);

}

void Scene1::on_pushButton_5_clicked()
{
    ui->pushButton_3->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_4->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_5->setStyleSheet("QPushButton{background:rgb(136, 138, 133);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    qs_s1_right->setCurrentWidget(ps1_yt);

}
