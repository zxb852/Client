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

    settw(twconfig_user::common_user,twconfig_state::heat_on);
    settw(twconfig_user::common_user,twconfig_state::fire_on);
    settw(twconfig_user::common_user,twconfig_state::water_on);
    settw(twconfig_user::common_user,twconfig_state::flash_on);


    char pPath[256] = {0};
    getcwd(pPath, 256);
    QString basedir(pPath);
    qDebug()<<basedir;

    QMap<QString,QIcon> m_publicIconMap;
    m_publicIconMap[QStringLiteral("positon")] =QIcon(basedir+QStringLiteral("/icon/position.jpg"));
    m_publicIconMap[QStringLiteral("alarm")] =QIcon(basedir+QStringLiteral("/icon/am.jpg"));
    m_publicIconMap[QStringLiteral("time")] =QIcon(basedir+QStringLiteral("/icon/time.jpg"));

    //new tree model
    QStandardItemModel *model=new QStandardItemModel(this);
    model->setHorizontalHeaderLabels(QStringList()<<"故障时间"<<"故障地点"<<"故障类型");

    //new tree element 1 level
    QStandardItem* itemProject = new QStandardItem(m_publicIconMap["time"],QStringLiteral("2019-09-02 05:12:10"));
    QStandardItem* itemProject2 = new QStandardItem(m_publicIconMap["time"],QStringLiteral("2019-09-04 10:32:41"));
    QStandardItem* itemProject3 = new QStandardItem(m_publicIconMap["time"],QStringLiteral("2019-09-04 16:48:02"));


    model->appendRow(itemProject);
    model->appendRow(itemProject2);
    model->appendRow(itemProject3);
    model->setItem(model->indexFromItem(itemProject).row(),1,new QStandardItem("1号阀厅"));
    model->setItem(model->indexFromItem(itemProject).row(),2,new QStandardItem("过热"));

    model->setItem(model->indexFromItem(itemProject2).row(),1,new QStandardItem("1号阀厅"));
    model->setItem(model->indexFromItem(itemProject2).row(),2,new QStandardItem("渗水"));

    model->setItem(model->indexFromItem(itemProject3).row(),1,new QStandardItem("3号阀厅"));
     model->setItem(model->indexFromItem(itemProject3).row(),2,new QStandardItem("放电"));

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
    else if(user==twconfig_user::common_user)
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

    if(state==twconfig_state::heat_on)
    {
        treeWidget->setCurrentItem(B);
        B->setText(1,"开启");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(0,255,0));
        treeWidget->currentItem()->setTextColor(1,QColor(0,0,0));
        treeWidget->setCurrentItem(nullptr);
    }
    else if(state==twconfig_state::heat_off)
    {
        treeWidget->setCurrentItem(B);
        B->setText(1,"关闭");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(200,200,200));
        treeWidget->currentItem()->setTextColor(1,QColor(255,0,0));
        treeWidget->setCurrentItem(nullptr);
    }
    else if(state==twconfig_state::heat_am)
    {
        treeWidget->setCurrentItem(B);
        B->setText(1,"报警");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(255,0,0));
        treeWidget->currentItem()->setTextColor(1,QColor(0,0,0));
        treeWidget->setCurrentItem(nullptr);
    }

    if(state==twconfig_state::fire_on)
    {
        treeWidget->setCurrentItem(C);
        C->setText(1,"开启");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(0,255,0));
        treeWidget->currentItem()->setTextColor(1,QColor(0,0,0));
        treeWidget->setCurrentItem(nullptr);
    }
    else if(state==twconfig_state::fire_off)
    {
        treeWidget->setCurrentItem(C);
        C->setText(1,"关闭");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(200,200,200));
        treeWidget->currentItem()->setTextColor(1,QColor(255,0,0));
        treeWidget->setCurrentItem(nullptr);
    }
    else if(state==twconfig_state::fire_am)
    {
        treeWidget->setCurrentItem(C);
        C->setText(1,"报警");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(255,0,0));
        treeWidget->currentItem()->setTextColor(1,QColor(0,0,0));
        treeWidget->setCurrentItem(nullptr);
    }

    if(state==twconfig_state::water_on)
    {
        treeWidget->setCurrentItem(D);
        D->setText(1,"开启");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(0,255,0));
        treeWidget->currentItem()->setTextColor(1,QColor(0,0,0));
        treeWidget->setCurrentItem(nullptr);
    }
    else if(state==twconfig_state::water_off)
    {
        treeWidget->setCurrentItem(D);
        D->setText(1,"关闭");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(200,200,200));
        treeWidget->currentItem()->setTextColor(1,QColor(255,0,0));
        treeWidget->setCurrentItem(nullptr);
    }
    else if(state==twconfig_state::water_am)
    {
        treeWidget->setCurrentItem(D);
        D->setText(1,"报警");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(255,0,0));
        treeWidget->currentItem()->setTextColor(1,QColor(0,0,0));
        treeWidget->setCurrentItem(nullptr);
    }

    if(state==twconfig_state::flash_on)
    {
        treeWidget->setCurrentItem(E);
        E->setText(1,"开启");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(0,255,0));
        treeWidget->currentItem()->setTextColor(1,QColor(0,0,0));
        treeWidget->setCurrentItem(nullptr);
    }
    else if(state==twconfig_state::flash_off)
    {
        treeWidget->setCurrentItem(E);
        E->setText(1,"关闭");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(200,200,200));
        treeWidget->currentItem()->setTextColor(1,QColor(255,0,0));
        treeWidget->setCurrentItem(nullptr);
    }
    else if(state==twconfig_state::flash_am)
    {
        treeWidget->setCurrentItem(E);
        E->setText(1,"报警");
        treeWidget->currentItem()->setBackgroundColor(1,QColor(255,0,0));
        treeWidget->currentItem()->setTextColor(1,QColor(0,0,0));
        treeWidget->setCurrentItem(nullptr);
    }
}
