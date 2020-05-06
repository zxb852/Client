#include "dialog_alarm.h"
#include "ui_dialog_alarm.h"

Dialog_alarm::Dialog_alarm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_alarm)
{
    ui->setupUi(this);
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::red);
    ui->labeltext->setPalette(pe);
}

Dialog_alarm::~Dialog_alarm()
{
    delete ui;
}

void Dialog_alarm::settype(int type)
{
    switch(type)
    {
    case 1:
        ui->labeltext->setText("出现过热故障");
        break;
    case 2:
        ui->labeltext->setText("出现明火故障");
        break;
    case 3:
        ui->labeltext->setText("出现渗水故障");
        break;
    case 4:
        ui->labeltext->setText("出现放电故障");
        break;
    default:
        break;
    }
}
