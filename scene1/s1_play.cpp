#include "s1_play.h"
#include "ui_s1_play.h"

s1_play::s1_play(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::s1_play)
{
    ui->setupUi(this);
}

s1_play::~s1_play()
{
    delete ui;
}
