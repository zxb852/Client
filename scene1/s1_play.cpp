#include "s1_play.h"
#include "ui_s1_play.h"

s1_play::s1_play(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::s1_play)
{
    ui->setupUi(this);

    QPixmap qpix("./pic/heat.jpg");
    qpix=qpix.scaled(QSize(512,384));
    ui->label_2->setPixmap(qpix);

    QPixmap qpix2("./pic/flash.jpg");
    qpix2=qpix2.scaled(QSize(512,384));
    ui->label_4->setPixmap(qpix2);

    QPixmap qpix3("./pic/heat2.jpg");
    qpix3=qpix3.scaled(QSize(512,384));
    ui->label_3->setPixmap(qpix3);
}

s1_play::~s1_play()
{
    delete ui;
}

WId s1_play::getplaywnd(int type)
{
    if(type==1)
        ui->label->winId();
    else if(type==2)
        ui->label_2->winId();
    else if(type==3)
        ui->label_4->winId();
}

QLabel *s1_play::getplaywnd4()
{
    return ui->label_3;
}
