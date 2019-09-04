#include "s3_flash.h"
#include "ui_s3_flash.h"

s3_flash::s3_flash(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::s3_flash)
{
    ui->setupUi(this);
}

s3_flash::~s3_flash()
{
    delete ui;
}
