#include "s3_heat_add.h"
#include "ui_s3_heat_add.h"

s3_heat_add::s3_heat_add(int level,QWidget *parent) :
    level(level),
    QDialog(parent),
    ui(new Ui::s3_heat_add)
{
    ui->setupUi(this);
}

s3_heat_add::~s3_heat_add()
{
    delete ui;
}

void s3_heat_add::on_pushButton_clicked()
{
    int mode=ui->comboBox->currentIndex();
    double min=ui->lineEdit->text().toDouble();
    double max=ui->lineEdit_2->text().toDouble();
    if(level==1)
        emit rule_common(add_rule(mode,min,max));
    else if(level==2)
        emit rule_hard(add_rule(mode,min,max));
    else if(level==3)
        emit rule_boom(add_rule(mode,min,max));

    this->accept();
}

void s3_heat_add::on_pushButton_2_clicked()
{
    this->reject();
}
