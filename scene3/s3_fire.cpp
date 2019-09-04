#include "s3_fire.h"
#include "ui_s3_fire.h"

s3_fire::s3_fire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::s3_fire)
{
    ui->setupUi(this);
}

s3_fire::~s3_fire()
{
    delete ui;
}
