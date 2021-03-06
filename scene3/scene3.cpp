#include "scene3.h"
#include "ui_scene3.h"

scene3::scene3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scene3)
{
    ui->setupUi(this);

    ps3_fire=new s3_fire();
    ps3_flash=new s3_flash();
    ps3_heat=new s3_heat();
    ps3_water=new s3_water();
    ps3_config1_xt = new s3_config1_xt();
    ps3_config2=new s3_config2();
    ps3_config3=new s3_config3();

    qs=new QStackedWidget();
    qs_config=new QStackedWidget();

    qs->addWidget(ps3_fire);
    qs->addWidget(ps3_flash);
    qs->addWidget(ps3_heat);
    qs->addWidget(ps3_water);
    qs_config->addWidget(ps3_config1_xt);
    qs_config->addWidget(ps3_config2);
    qs_config->addWidget(ps3_config3);

    ui->scrollArea->setWidget(qs);
    ui->scrollArea_2->setWidget(qs_config);

    selected="QPushButton{background:rgb(136, 138, 133);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}";
    unselected="QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}";
    on_pushButton_clicked();
    on_pushButton_5_clicked();

}

scene3::~scene3()
{
    delete ui;
}

void scene3::on_pushButton_clicked()
{
    ui->pushButton->setStyleSheet("QPushButton{background:rgb(136, 138, 133);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_2->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_3->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_4->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    qs->setCurrentWidget(ps3_heat);
}

void scene3::on_pushButton_2_clicked()
{
    ui->pushButton->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_2->setStyleSheet("QPushButton{background:rgb(136, 138, 133);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_3->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_4->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    qs->setCurrentWidget(ps3_fire);
}

void scene3::on_pushButton_3_clicked()
{
    ui->pushButton->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_2->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_3->setStyleSheet("QPushButton{background:rgb(136, 138, 133);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_4->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    qs->setCurrentWidget(ps3_water);
}

void scene3::on_pushButton_4_clicked()
{
    ui->pushButton->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_2->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_3->setStyleSheet("QPushButton{background:rgb(255, 255, 255);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    ui->pushButton_4->setStyleSheet("QPushButton{background:rgb(136, 138, 133);}" "QPushButton:hover{background-color:rgb(136, 138, 133);}");
    qs->setCurrentWidget(ps3_flash);
}

void scene3::on_pushButton_5_clicked()
{
    ui->pushButton_5->setStyleSheet(selected);
    ui->pushButton_6->setStyleSheet(unselected);
    ui->pushButton_7->setStyleSheet(unselected);
    qs_config->setCurrentWidget(ps3_config1_xt);
}

void scene3::on_pushButton_6_clicked()
{
    ui->pushButton_5->setStyleSheet(unselected);
    ui->pushButton_6->setStyleSheet(selected);
    ui->pushButton_7->setStyleSheet(unselected);
    qs_config->setCurrentWidget(ps3_config2);
}

void scene3::on_pushButton_7_clicked()
{
    ui->pushButton_5->setStyleSheet(unselected);
    ui->pushButton_6->setStyleSheet(unselected);
    ui->pushButton_7->setStyleSheet(selected);
    qs_config->setCurrentWidget(ps3_config3);
}
