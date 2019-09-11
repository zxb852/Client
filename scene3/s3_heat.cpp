#include "s3_heat.h"
#include "ui_s3_heat.h"
#include <unistd.h>
#include <QDebug>
#include <QTreeWidgetItem>
#include <QString>

s3_heat::s3_heat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::s3_heat)
{
    ui->setupUi(this);

    model=new QStandardItemModel(this);
    model->setHorizontalHeaderLabels(QStringList()<<"规则类型"<<"下限"<<"上限");

    ui->treeView->setModel(model);
    ui->treeView->setColumnWidth(0,100);
    ui->treeView->setColumnWidth(1,100);
    ui->treeView->setColumnWidth(2,100);
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    model2=new QStandardItemModel(this);
    model2->setHorizontalHeaderLabels(QStringList()<<"规则类型"<<"下限"<<"上限");

    ui->treeView_2->setModel(model2);
    ui->treeView_2->setColumnWidth(0,100);
    ui->treeView_2->setColumnWidth(1,100);
    ui->treeView_2->setColumnWidth(2,100);
    ui->treeView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    model3=new QStandardItemModel(this);
    model3->setHorizontalHeaderLabels(QStringList()<<"规则类型"<<"下限"<<"上限");

    ui->treeView_3->setModel(model3);
    ui->treeView_3->setColumnWidth(0,100);
    ui->treeView_3->setColumnWidth(1,100);
    ui->treeView_3->setColumnWidth(2,100);
    ui->treeView_3->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

s3_heat::~s3_heat()
{
    delete ui;
}

void s3_heat::on_pushButton_clicked()
{
    s3_heat_add *ps3_heat_add=new s3_heat_add(1);
    connect(ps3_heat_add,SIGNAL(rule_common(add_rule)),this,SLOT(add_rule_common(add_rule)));
    ps3_heat_add->show();
}

void s3_heat::on_pushButton_3_clicked()
{
    s3_heat_add *ps3_heat_add=new s3_heat_add(2);
    connect(ps3_heat_add,SIGNAL(rule_hard(add_rule)),this,SLOT(add_rule_hard(add_rule)));
    ps3_heat_add->show();
}

void s3_heat::on_pushButton_5_clicked()
{
    s3_heat_add *ps3_heat_add=new s3_heat_add(3);
    connect(ps3_heat_add,SIGNAL(rule_boom(add_rule)),this,SLOT(add_rule_boom(add_rule)));
    ps3_heat_add->show();
}

void s3_heat::add_rule_common(add_rule new_ruel)
{
    fadd_rule(1,new_ruel.mode,new_ruel.min,new_ruel.max);
}
void s3_heat::add_rule_hard(add_rule new_ruel)
{
    fadd_rule(2,new_ruel.mode,new_ruel.min,new_ruel.max);
}
void s3_heat::add_rule_boom(add_rule new_ruel)
{
    fadd_rule(3,new_ruel.mode,new_ruel.min,new_ruel.max);
}

void s3_heat::fadd_rule(int level,int mode,double min,double max)
{
    // qDebug()<<new_ruel.mode<<" "<<new_ruel.min<<" "<<new_ruel.max;
    if(level==1)
    {
        if(mode==0)
        {
            QStandardItem* itemProject = new QStandardItem("设备温度");
            model->appendRow(itemProject);
            model->setItem(model->indexFromItem(itemProject).row(),1,new QStandardItem(QString::number(min)));
            model->setItem(model->indexFromItem(itemProject).row(),2,new QStandardItem(QString::number(max)));
        }
        else if(mode==1)
        {
            QStandardItem* itemProject = new QStandardItem("设备温升");
            model->appendRow(itemProject);
            model->setItem(model->indexFromItem(itemProject).row(),1,new QStandardItem(QString::number(min)));
            model->setItem(model->indexFromItem(itemProject).row(),2,new QStandardItem(QString::number(max)));
        }
        else if(mode==2)
        {
            QStandardItem* itemProject = new QStandardItem("设备温差");
            model->appendRow(itemProject);
            model->setItem(model->indexFromItem(itemProject).row(),1,new QStandardItem(QString::number(min)));
            model->setItem(model->indexFromItem(itemProject).row(),2,new QStandardItem(QString::number(max)));
        }
        else if(mode==3)
        {
            QStandardItem* itemProject = new QStandardItem("相对温差");
            model->appendRow(itemProject);
            model->setItem(model->indexFromItem(itemProject).row(),1,new QStandardItem(QString::number(min)));
            model->setItem(model->indexFromItem(itemProject).row(),2,new QStandardItem(QString::number(max)));
        }
    }
    else if(level==2)
    {
        if(mode==0)
        {
            QStandardItem* itemProject = new QStandardItem("设备温度");
            model2->appendRow(itemProject);
            model2->setItem(model->indexFromItem(itemProject).row(),1,new QStandardItem(QString::number(min)));
            model2->setItem(model->indexFromItem(itemProject).row(),2,new QStandardItem(QString::number(max)));
        }
        else if(mode==1)
        {
            QStandardItem* itemProject = new QStandardItem("设备温升");
            model2->appendRow(itemProject);
            model2->setItem(model->indexFromItem(itemProject).row(),1,new QStandardItem(QString::number(min)));
            model2->setItem(model->indexFromItem(itemProject).row(),2,new QStandardItem(QString::number(max)));
        }
        else if(mode==2)
        {
            QStandardItem* itemProject = new QStandardItem("设备温差");
            model2->appendRow(itemProject);
            model2->setItem(model->indexFromItem(itemProject).row(),1,new QStandardItem(QString::number(min)));
            model2->setItem(model->indexFromItem(itemProject).row(),2,new QStandardItem(QString::number(max)));
        }
        else if(mode==3)
        {
            QStandardItem* itemProject = new QStandardItem("相对温差");
            model2->appendRow(itemProject);
            model2->setItem(model->indexFromItem(itemProject).row(),1,new QStandardItem(QString::number(min)));
            model2->setItem(model->indexFromItem(itemProject).row(),2,new QStandardItem(QString::number(max)));
        }
    }
    else if(level==3)
    {
        if(mode==0)
        {
            QStandardItem* itemProject = new QStandardItem("设备温度");
            model3->appendRow(itemProject);
            model3->setItem(model->indexFromItem(itemProject).row(),1,new QStandardItem(QString::number(min)));
            model3->setItem(model->indexFromItem(itemProject).row(),2,new QStandardItem(QString::number(max)));
        }
        else if(mode==1)
        {
            QStandardItem* itemProject = new QStandardItem("设备温升");
            model3->appendRow(itemProject);
            model3->setItem(model->indexFromItem(itemProject).row(),1,new QStandardItem(QString::number(min)));
            model3->setItem(model->indexFromItem(itemProject).row(),2,new QStandardItem(QString::number(max)));
        }
        else if(mode==2)
        {
            QStandardItem* itemProject = new QStandardItem("设备温差");
            model3->appendRow(itemProject);
            model3->setItem(model->indexFromItem(itemProject).row(),1,new QStandardItem(QString::number(min)));
            model3->setItem(model->indexFromItem(itemProject).row(),2,new QStandardItem(QString::number(max)));
        }
        else if(mode==3)
        {
            QStandardItem* itemProject = new QStandardItem("相对温差");
            model3->appendRow(itemProject);
            model3->setItem(model->indexFromItem(itemProject).row(),1,new QStandardItem(QString::number(min)));
            model3->setItem(model->indexFromItem(itemProject).row(),2,new QStandardItem(QString::number(max)));
        }
    }

}

