#include "s1_yt.h"
#include "ui_s1_yt.h"
#include "QDebug"

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

// up
void s1_yt::on_B_base_up_clicked()
{
    int speed = ui->comboBox->currentIndex() + 1;
    emit ptz_move(1,speed);
}

// down
void s1_yt::on_B_base_down_clicked()
{
    int speed = ui->comboBox->currentIndex() + 1;
    emit ptz_move(2,speed);
}

// left
void s1_yt::on_B_base_left_clicked()
{
    int speed = ui->comboBox->currentIndex() + 1;
    emit ptz_move(3,speed);
}

// right
void s1_yt::on_B_base_right_clicked()
{
    int speed = ui->comboBox->currentIndex() + 1;
    emit ptz_move(4,speed);
}

// 对焦远
void s1_yt::on_pushButton_2_clicked()
{
    emit ptz_move(5,1);
}

// 对焦近
void s1_yt::on_pushButton_3_clicked()
{
    emit ptz_move(6,1);
}

// add
void s1_yt::on_B_point_clicked()
{
    int nmax=ui->treeWidget_2->topLevelItemCount();
    QTreeWidgetItem* nwi = new QTreeWidgetItem(QStringList()<<std::to_string(nmax+1).c_str()<<std::to_string(nmax+1).c_str());
    ui->treeWidget_2->addTopLevelItem(nwi);
    emit ptz_prset(1,nmax+1);
}

// del
void s1_yt::on_B_point_2_clicked()
{
    auto pw = ui->treeWidget_2->currentItem();
    int pnum= ui->treeWidget_2->indexOfTopLevelItem(pw);
    delete pw;
    emit ptz_prset(2,pnum+1);
}

// goto
void s1_yt::on_B_point_3_clicked()
{
    auto pw = ui->treeWidget_2->currentItem();
    int pnum= ui->treeWidget_2->indexOfTopLevelItem(pw);
    emit ptz_prset(3,pnum+1);
}























