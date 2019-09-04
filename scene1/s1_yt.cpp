#include "s1_yt.h"
#include "ui_s1_yt.h"

s1_yt::s1_yt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::s1_yt)
{
    ui->setupUi(this);
}

s1_yt::~s1_yt()
{
    delete ui;
}
