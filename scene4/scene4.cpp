#include "scene4.h"
#include "ui_scene4.h"
#include <unistd.h>
#include <QDebug>

scene4::scene4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scene4)
{
    ui->setupUi(this);

    char pPath[256] = {0};
    getcwd(pPath, 256);
    QString basedir(pPath);
    qDebug()<<basedir;

    QMap<QString,QIcon> m_publicIconMap;
    m_publicIconMap[QStringLiteral("positon")] =QIcon(basedir+QStringLiteral("/icon/position.jpg"));
    m_publicIconMap[QStringLiteral("camera")] =QIcon(basedir+QStringLiteral("/icon/camera.jpg"));

    //new tree model
    QStandardItemModel *model=new QStandardItemModel(this);
    model->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("设备")<<QStringLiteral("信息"));

    //new tree element 1 level
    QStandardItem* itemProject = new QStandardItem(m_publicIconMap[QStringLiteral("positon")],QStringLiteral("1号阀厅"));
    QStandardItem* itemProject2 = new QStandardItem(m_publicIconMap[QStringLiteral("positon")],QStringLiteral("2号阀厅"));
    QStandardItem* itemProject3 = new QStandardItem(m_publicIconMap[QStringLiteral("positon")],QStringLiteral("3号阀厅"));

    //new tree element 2 level
    QStandardItem* itemChild = new QStandardItem(m_publicIconMap[QStringLiteral("camera")],QStringLiteral("1号设备"));
    QStandardItem* itemChild2 = new QStandardItem(m_publicIconMap[QStringLiteral("camera")],QStringLiteral("2号设备"));
    QStandardItem* itemChild3 = new QStandardItem(m_publicIconMap[QStringLiteral("camera")],QStringLiteral("3号设备"));
    QStandardItem* itemChild4 = new QStandardItem(m_publicIconMap[QStringLiteral("camera")],QStringLiteral("4号设备"));

    QStandardItem* itemChild02 = new QStandardItem(m_publicIconMap[QStringLiteral("camera")],QStringLiteral("1号设备"));
    QStandardItem* itemChild22 = new QStandardItem(m_publicIconMap[QStringLiteral("camera")],QStringLiteral("2号设备"));
    QStandardItem* itemChild32 = new QStandardItem(m_publicIconMap[QStringLiteral("camera")],QStringLiteral("3号设备"));
    QStandardItem* itemChild42 = new QStandardItem(m_publicIconMap[QStringLiteral("camera")],QStringLiteral("4号设备"));

    QStandardItem* itemChild03 = new QStandardItem(m_publicIconMap[QStringLiteral("camera")],QStringLiteral("1号设备"));
    QStandardItem* itemChild23 = new QStandardItem(m_publicIconMap[QStringLiteral("camera")],QStringLiteral("2号设备"));
    QStandardItem* itemChild33 = new QStandardItem(m_publicIconMap[QStringLiteral("camera")],QStringLiteral("3号设备"));
    QStandardItem* itemChild43 = new QStandardItem(m_publicIconMap[QStringLiteral("camera")],QStringLiteral("4号设备"));

    //add element
    itemProject->appendRow(itemChild);
    itemProject->setChild(0,1,new QStandardItem(QStringLiteral("可见+红外+紫外")));
    itemProject->appendRow(itemChild2);
    itemProject->setChild(1,1,new QStandardItem(QStringLiteral("可见+红外+紫外")));
    itemProject->appendRow(itemChild3);
    itemProject->setChild(2,1,new QStandardItem(QStringLiteral("可见")));
    itemProject->appendRow(itemChild4);
    itemProject->setChild(3,1,new QStandardItem(QStringLiteral("可见")));

    itemProject2->appendRow(itemChild02);
    itemProject2->setChild(0,1,new QStandardItem(QStringLiteral("可见+红外+紫外")));
    itemProject2->appendRow(itemChild22);
    itemProject2->setChild(1,1,new QStandardItem(QStringLiteral("可见")));
    itemProject2->appendRow(itemChild32);
    itemProject2->setChild(2,1,new QStandardItem(QStringLiteral("可见+红外+紫外")));
    itemProject2->appendRow(itemChild42);
    itemProject2->setChild(3,1,new QStandardItem(QStringLiteral("可见")));

    itemProject3->appendRow(itemChild03);
    itemProject3->setChild(0,1,new QStandardItem(QStringLiteral("可见+红外+紫外")));
    itemProject3->appendRow(itemChild23);
    itemProject3->setChild(1,1,new QStandardItem(QStringLiteral("可见")));
    itemProject3->appendRow(itemChild33);
    itemProject3->setChild(2,1,new QStandardItem(QStringLiteral("可见")));
    itemProject3->appendRow(itemChild43);
    itemProject3->setChild(3,1,new QStandardItem(QStringLiteral("可见")));

    model->appendRow(itemProject);
    model->appendRow(itemProject2);
    model->appendRow(itemProject3);
    model->setItem(model->indexFromItem(itemProject).row(),1,new QStandardItem(QStringLiteral("南京")));
    model->setItem(model->indexFromItem(itemProject2).row(),1,new QStandardItem(QStringLiteral("南京")));
    model->setItem(model->indexFromItem(itemProject3).row(),1,new QStandardItem(QStringLiteral("南京")));

    ui->treeView->setModel(model);
    ui->treeView->setColumnWidth(0,140);
    ui->treeView->setColumnWidth(1,145);
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

scene4::~scene4()
{
    delete ui;
}

WId scene4::getplaywid()
{
    return ui->label_11->winId();
}

void scene4::get_uidata()
{
    QDate data = ui->calendarWidget->selectedDate();
    int year=data.year();
    int month=data.month();
    int day=data.day();

    int begin_hour=ui->spinBox->value();
    int begin_min=ui->spinBox_2->value();
    int begin_sec=ui->spinBox_3->value();

    int end_hour=ui->spinBox_6->value();
    int end_min=ui->spinBox_5->value();
    int end_sec=ui->spinBox_4->value();

    begin.set(year,month,day,begin_hour,begin_min,begin_sec);
    end.set(year,month,day,end_hour,end_min,end_sec);

}

void scene4::on_pushButton_clicked()
{
    get_uidata();
    emit Download_Vedio(begin,end,33);
}

void scene4::on_pushButton_2_clicked()
{
    get_uidata();
    emit Capture();
}

void scene4::on_pushButton_3_clicked()
{
    get_uidata();
    emit Play_Vedio(begin,end,33);
}

void scene4::on_pushButton_4_clicked()
{
    get_uidata();
    emit Stop_vedio();
}

void scene4::process(int value)
{
    ui->progressBar->setValue(value);
}
