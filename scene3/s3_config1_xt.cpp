#include "s3_config1_xt.h"
#include "ui_s3_config1_xt.h"

s3_config1_xt::s3_config1_xt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::s3_config1_xt)
{
    ui->setupUi(this);
}

s3_config1_xt::~s3_config1_xt()
{
    delete ui;
}
