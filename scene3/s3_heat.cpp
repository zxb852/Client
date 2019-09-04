#include "s3_heat.h"
#include "ui_s3_heat.h"

s3_heat::s3_heat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::s3_heat)
{
    ui->setupUi(this);
}

s3_heat::~s3_heat()
{
    delete ui;
}
