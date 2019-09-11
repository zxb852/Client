#include "s3_config2.h"
#include "ui_s3_config2.h"

s3_config2::s3_config2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::s3_config2)
{
    ui->setupUi(this);
}

s3_config2::~s3_config2()
{
    delete ui;
}
