#include "s3_water.h"
#include "ui_s3_water.h"

s3_water::s3_water(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::s3_water)
{
    ui->setupUi(this);
}

s3_water::~s3_water()
{
    delete ui;
}
