#include "s3_config3.h"
#include "ui_s3_config3.h"

s3_config3::s3_config3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::s3_config3)
{
    ui->setupUi(this);
}

s3_config3::~s3_config3()
{
    delete ui;
}
