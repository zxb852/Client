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
        treeWidget->setCurrentItem(A);
        A->setText(1,"未登录");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(200,200,200));
        treeWidget->currentItem()->setTextColor(1,QColor(255,0,0));
        treeWidget->setCurrentItem(nullptr);
    }
    else if(user==common_user)
    {
        treeWidget->setCurrentItem(A);
        A->setText(1,"普通用户");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(255,255,0));
        treeWidget->currentItem()->setTextColor(1,QColor(0,0,0));
        treeWidget->setCurrentItem(nullptr);
    }
    else
    {
        treeWidget->setCurrentItem(A);
        A->setText(1,"管理员");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(255,255,0));
        treeWidget->currentItem()->setTextColor(1,QColor(255,0,0));
        treeWidget->setCurrentItem(nullptr);
    }

    if(state==heat_on)
    {
        treeWidget->setCurrentItem(B);
        B->setText(1,"开启");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(0,255,0));
        treeWidget->currentItem()->setTextColor(1,QColor(0,0,0));
        treeWidget->setCurrentItem(nullptr);
    }
    else if(state==heat_off)
    {
        treeWidget->setCurrentItem(B);
        B->setText(1,"关闭");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(200,200,200));
        treeWidget->currentItem()->setTextColor(1,QColor(255,0,0));
        treeWidget->setCurrentItem(nullptr);
    }
    else if(state==heat_am)
    {
        treeWidget->setCurrentItem(B);
        B->setText(1,"报警");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(255,0,0));
        treeWidget->currentItem()->setTextColor(1,QColor(0,0,0));
        treeWidget->setCurrentItem(nullptr);
    }

    if(state==fire_on)
    {
        treeWidget->setCurrentItem(C);
        C->setText(1,"开启");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(0,255,0));
        treeWidget->currentItem()->setTextColor(1,QColor(0,0,0));
        treeWidget->setCurrentItem(nullptr);
    }
    else if(state==fire_off)
    {
        treeWidget->setCurrentItem(C);
        C->setText(1,"关闭");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(200,200,200));
        treeWidget->currentItem()->setTextColor(1,QColor(255,0,0));
        treeWidget->setCurrentItem(nullptr);
    }
    else if(state==fire_am)
    {
        treeWidget->setCurrentItem(C);
        C->setText(1,"报警");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(255,0,0));
        treeWidget->currentItem()->setTextColor(1,QColor(0,0,0));
        treeWidget->setCurrentItem(nullptr);
    }

    if(state==water_on)
    {
        treeWidget->setCurrentItem(D);
        D->setText(1,"开启");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(0,255,0));
        treeWidget->currentItem()->setTextColor(1,QColor(0,0,0));
        treeWidget->setCurrentItem(nullptr);
    }
    else if(state==water_off)
    {
        treeWidget->setCurrentItem(D);
        D->setText(1,"关闭");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(200,200,200));
        treeWidget->currentItem()->setTextColor(1,QColor(255,0,0));
        treeWidget->setCurrentItem(nullptr);
    }
    else if(state==water_am)
    {
        treeWidget->setCurrentItem(D);
        D->setText(1,"报警");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(255,0,0));
        treeWidget->currentItem()->setTextColor(1,QColor(0,0,0));
        treeWidget->setCurrentItem(nullptr);
    }

    if(state==flash_on)
    {
        treeWidget->setCurrentItem(E);
        E->setText(1,"开启");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(0,255,0));
        treeWidget->currentItem()->setTextColor(1,QColor(0,0,0));
        treeWidget->setCurrentItem(nullptr);
    }
    else if(state==flash_off)
    {
        treeWidget->setCurrentItem(E);
        E->setText(1,"关闭");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(200,200,200));
        treeWidget->currentItem()->setTextColor(1,QColor(255,0,0));
        treeWidget->setCurrentItem(nullptr);
    }
    else if(state==flash_am)
    {
        treeWidget->setCurrentItem(E);
        E->setText(1,"报警");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(255,0,0));
        treeWidget->currentItem()->setTextColor(1,QColor(0,0,0));
        treeWidget->setCurrentItem(nullptr);
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
