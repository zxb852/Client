#include "s1_jk.h"
#include "ui_s1_jk.h"
#include <unistd.h>
#include <QDebug>
#include <QTreeWidgetItem>
#include <QString>

s1_jk::s1_jk(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::s1_jk)
{
    ui->setupUi(this);

    treeWidget = ui->treeWidget;
    treeWidget->clear();
    treeWidget->setWindowTitle("QTreeWidget");
    //设定头项名称
    treeWidget->setHeaderLabels(QStringList()<<"功能"<<"状态");
    //设定各个项
    A = new QTreeWidgetItem(QStringList()<<"用户权限"<<"未登录");
    B = new QTreeWidgetItem(QStringList()<<"过热检测"<<"关闭");
    C = new QTreeWidgetItem(QStringList()<<"明火检测"<<"关闭");
    D = new QTreeWidgetItem(QStringList()<<"渗水检测"<<"关闭");
    E = new QTreeWidgetItem(QStringList()<<"放电检测"<<"关闭");


    treeWidget->addTopLevelItem(A);
    treeWidget->addTopLevelItem(B);
    treeWidget->addTopLevelItem(C);
    treeWidget->addTopLevelItem(D);
    treeWidget->addTopLevelItem(E);
    treeWidget->addTopLevelItem(new QTreeWidgetItem(QStringList()<<"all"<<"开启"));
    treeWidget->addTopLevelItem(new QTreeWidgetItem(QStringList()<<"all"<<"关闭"));

    settw(common_user,heat_on);
    settw(common_user,fire_on);
    settw(common_user,water_on);
    settw(common_user,flash_on);




    //new tree model
    model=new QStandardItemModel(this);
    model->setHorizontalHeaderLabels(QStringList()<<"故障时间"<<"故障地点"<<"故障类型");

    ui->treeView_2->setModel(model);
    ui->treeView_2->setColumnWidth(0,200);
    ui->treeView_2->setColumnWidth(1,150);
    ui->treeView_2->setColumnWidth(2,100);
    ui->treeView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);


}

s1_jk::~s1_jk()
{
    delete ui;
}

void s1_jk::settw(twconfig_user user,twconfig_state state)
{
    QTreeWidget* treeWidget = ui->treeWidget;
    if(user==twconfig_user::none)
    {
        A->setText(1,"未登录");
        treeWidget->topLevelItem(0)->setBackgroundColor(1,QColor(200,200,200));
        treeWidget->topLevelItem(0)->setTextColor(1,QColor(255,0,0));
    }
    else if(user==common_user)
    {
        A->setText(1,"普通用户");
        treeWidget->topLevelItem(0)->setBackgroundColor(1,QColor(255,255,0));
        treeWidget->topLevelItem(0)->setTextColor(1,QColor(0,0,0));

    }
    else
    {
        A->setText(1,"管理员");
        treeWidget->topLevelItem(0)->setBackgroundColor(1,QColor(255,255,0));
        treeWidget->topLevelItem(0)->setTextColor(1,QColor(255,0,0));
    }

    if(state==heat_on)
    {
        B->setText(1,"开启");
        treeWidget->topLevelItem(1)->setBackgroundColor(1,QColor(0,255,0));
        treeWidget->topLevelItem(1)->setTextColor(1,QColor(0,0,0));
    }
    else if(state==heat_off)
    {
        B->setText(1,"关闭");
        treeWidget->topLevelItem(1)->setBackgroundColor(1,QColor(200,200,200));
        treeWidget->topLevelItem(1)->setTextColor(1,QColor(255,0,0));
    }
    else if(state==heat_am)
    {
        B->setText(1,"报警");
        treeWidget->topLevelItem(1)->setBackgroundColor(1,QColor(255,0,0));
        treeWidget->topLevelItem(1)->setTextColor(1,QColor(0,0,0));
    }

    if(state==fire_on)
    {
        C->setText(1,"开启");
        treeWidget->topLevelItem(2)->setBackgroundColor(1,QColor(0,255,0));
        treeWidget->topLevelItem(2)->setTextColor(1,QColor(0,0,0));
    }
    else if(state==fire_off)
    {
        C->setText(1,"关闭");
        treeWidget->topLevelItem(2)->setBackgroundColor(1,QColor(200,200,200));
        treeWidget->topLevelItem(2)->setTextColor(1,QColor(255,0,0));
    }
    else if(state==fire_am)
    {
        C->setText(1,"报警");
        treeWidget->topLevelItem(2)->setBackgroundColor(1,QColor(255,0,0));
        treeWidget->topLevelItem(2)->setTextColor(1,QColor(0,0,0));
    }

    if(state==water_on)
    {
        D->setText(1,"开启");
        treeWidget->topLevelItem(3)->setBackgroundColor(1,QColor(0,255,0));
        treeWidget->topLevelItem(3)->setTextColor(1,QColor(0,0,0));
    }
    else if(state==water_off)
    {
        D->setText(1,"关闭");
        treeWidget->topLevelItem(3)->setBackgroundColor(1,QColor(200,200,200));
        treeWidget->topLevelItem(3)->setTextColor(1,QColor(255,0,0));
    }
    else if(state==water_am)
    {
        D->setText(1,"报警");
        treeWidget->topLevelItem(3)->setBackgroundColor(1,QColor(255,0,0));
        treeWidget->topLevelItem(3)->setTextColor(1,QColor(0,0,0));
    }

    if(state==flash_on)
    {
        E->setText(1,"开启");
        treeWidget->topLevelItem(4)->setBackgroundColor(1,QColor(0,255,0));
        treeWidget->topLevelItem(4)->setTextColor(1,QColor(0,0,0));
    }
    else if(state==flash_off)
    {
        E->setText(1,"关闭");
        treeWidget->topLevelItem(4)->setBackgroundColor(1,QColor(200,200,200));
        treeWidget->topLevelItem(4)->setTextColor(1,QColor(255,0,0));
    }
    else if(state==flash_am)
    {
        E->setText(1,"报警");
        treeWidget->topLevelItem(4)->setBackgroundColor(1,QColor(255,0,0));
        treeWidget->topLevelItem(4)->setTextColor(1,QColor(0,0,0));
    }
}

void s1_jk::addtv(int year,int month, int day, int hour, int mins, int sec, QString pos, ftypes ft)
{
    char pPath[256] = {0};
    getcwd(pPath, 256);
    QString basedir(pPath);

    QString date=QString::number(year)+"-"+QString::number(month)+"-"+QString::number(day)+" "+QString::number(hour)+":"+QString::number(mins)+":"+QString::number(sec);
    QStandardItem* itemProject = new QStandardItem(QIcon(basedir+QStringLiteral("/icon/time.jpg")),date);
    model->appendRow(itemProject);
    model->setItem(model->indexFromItem(itemProject).row(),1,new QStandardItem(pos));
    if(ft==heat_ft)
        model->setItem(model->indexFromItem(itemProject).row(),2,new QStandardItem("过热"));
    else if(ft==fire_ft)
        model->setItem(model->indexFromItem(itemProject).row(),2,new QStandardItem("明火"));
    else if(ft==water_ft)
        model->setItem(model->indexFromItem(itemProject).row(),2,new QStandardItem("渗水"));
    else if(ft==flash_ft)
        model->setItem(model->indexFromItem(itemProject).row(),2,new QStandardItem("放电"));
}

int s1_jk::getselect()
{
    return ui->treeView_2->currentIndex().row();
}

//rgb
void s1_jk::on_pushButton_clicked()
{
    emit playvedio(1);
}
//ir
void s1_jk::on_pushButton_2_clicked()
{
    emit playvedio(2);
}
//uv
void s1_jk::on_pushButton_3_clicked()
{
    emit playvedio(3);
}
//vedio
void s1_jk::on_pushButton_4_clicked()
{
    emit playvedio(4);
}

void s1_jk::on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    int pnum= ui->treeWidget->indexOfTopLevelItem(current);

    switch(pnum)
    {
    case 1:
    {
        settw(common_user,heat_on);
        settw(common_user,fire_off);
        settw(common_user,water_off);
        settw(common_user,flash_off);
        break;
    }
    case 2:
    {
        settw(common_user,heat_off);
        settw(common_user,fire_on);
        settw(common_user,water_off);
        settw(common_user,flash_off);
        break;
    }
    case 3:
    {
        //settw(common_user,heat_off);
        //settw(common_user,fire_off);
        settw(common_user,water_on);
        //settw(common_user,flash_off);
        break;
    }
    case 4:
    {
        settw(common_user,heat_off);
        settw(common_user,fire_off);
        settw(common_user,water_off);
        settw(common_user,flash_on);
        break;
    }
    case 5:
    {
        settw(common_user,heat_on);
        settw(common_user,fire_on);
        settw(common_user,water_on);
        settw(common_user,flash_on);
        break;
    }
    case 6:
    {
        settw(common_user,heat_off);
        settw(common_user,fire_off);
        settw(common_user,water_off);
        settw(common_user,flash_off);
        break;
    }
    default:
        break;
    }

    emit dection_switch(pnum);
}
