#include "scene4.h"
#include "ui_scene4.h"

scene4::scene4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scene4)
{
    ui->setupUi(this);
}

scene4::~scene4()
{
    delete ui;
}
