#include "s3_heat.h"
#include "ui_s3_heat.h"
#include <unistd.h>
#include <QDebug>
#include <QTreeWidgetItem>
#include <QString>
#include <sstream>
#include "tinystr.h"
#include "tinyxml.h"

s3_heat::s3_heat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::s3_heat)
{
    ui->setupUi(this);

    readxml("/home/zxb/SRC_C/Detect/conf.xml");

}

s3_heat::~s3_heat()
{
    delete ui;
}

// 添加规则
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

// 删除规则
void s3_heat::on_pushButton_2_clicked()
{
    delete ui->treeWidget->currentItem();
}

void s3_heat::on_pushButton_4_clicked()
{
    delete ui->treeWidget_2->currentItem();
}

void s3_heat::on_pushButton_6_clicked()
{
    delete ui->treeWidget_3->currentItem();
}

// 槽函数
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

// 在监控界面添加规则条目
void s3_heat::fadd_rule(int level,int mode,double min,double max)
{
    // qDebug()<<new_ruel.mode<<" "<<new_ruel.min<<" "<<new_ruel.max;
    if(level==1)
    {
        int nmax=ui->treeWidget->topLevelItemCount();
        if(mode==0)
        {

            QTreeWidgetItem* nwi = new QTreeWidgetItem(QStringList()<<"设备温度"<<std::to_string(min).c_str()<<std::to_string(max).c_str());
            ui->treeWidget->addTopLevelItem(nwi);
        }
        else if(mode==1)
        {
            QTreeWidgetItem* nwi = new QTreeWidgetItem(QStringList()<<"设备温升"<<std::to_string(min).c_str()<<std::to_string(max).c_str());
            ui->treeWidget->addTopLevelItem(nwi);
        }
        else if(mode==2)
        {
            QTreeWidgetItem* nwi = new QTreeWidgetItem(QStringList()<<"设备温差"<<std::to_string(min).c_str()<<std::to_string(max).c_str());
            ui->treeWidget->addTopLevelItem(nwi);
        }
        else if(mode==3)
        {
            QTreeWidgetItem* nwi = new QTreeWidgetItem(QStringList()<<"相对温差"<<std::to_string(min).c_str()<<std::to_string(max).c_str());
            ui->treeWidget->addTopLevelItem(nwi);
        }
    }
    else if(level==2)
    {
        int nmax=ui->treeWidget_2->topLevelItemCount();
        if(mode==0)
        {

            QTreeWidgetItem* nwi = new QTreeWidgetItem(QStringList()<<"设备温度"<<std::to_string(min).c_str()<<std::to_string(max).c_str());
            ui->treeWidget_2->addTopLevelItem(nwi);
        }
        else if(mode==1)
        {
            QTreeWidgetItem* nwi = new QTreeWidgetItem(QStringList()<<"设备温升"<<std::to_string(min).c_str()<<std::to_string(max).c_str());
            ui->treeWidget_2->addTopLevelItem(nwi);
        }
        else if(mode==2)
        {
            QTreeWidgetItem* nwi = new QTreeWidgetItem(QStringList()<<"设备温差"<<std::to_string(min).c_str()<<std::to_string(max).c_str());
            ui->treeWidget_2->addTopLevelItem(nwi);
        }
        else if(mode==3)
        {
            QTreeWidgetItem* nwi = new QTreeWidgetItem(QStringList()<<"相对温差"<<std::to_string(min).c_str()<<std::to_string(max).c_str());
            ui->treeWidget_2->addTopLevelItem(nwi);
        }
    }
    else if(level==3)
    {
        int nmax=ui->treeWidget_3->topLevelItemCount();
        if(mode==0)
        {

            QTreeWidgetItem* nwi = new QTreeWidgetItem(QStringList()<<"设备温度"<<std::to_string(min).c_str()<<std::to_string(max).c_str());
            ui->treeWidget_3->addTopLevelItem(nwi);
        }
        else if(mode==1)
        {
            QTreeWidgetItem* nwi = new QTreeWidgetItem(QStringList()<<"设备温升"<<std::to_string(min).c_str()<<std::to_string(max).c_str());
            ui->treeWidget_3->addTopLevelItem(nwi);
        }
        else if(mode==2)
        {
            QTreeWidgetItem* nwi = new QTreeWidgetItem(QStringList()<<"设备温差"<<std::to_string(min).c_str()<<std::to_string(max).c_str());
            ui->treeWidget_3->addTopLevelItem(nwi);
        }
        else if(mode==3)
        {
            QTreeWidgetItem* nwi = new QTreeWidgetItem(QStringList()<<"相对温差"<<std::to_string(min).c_str()<<std::to_string(max).c_str());
            ui->treeWidget_3->addTopLevelItem(nwi);
        }
    }

}

void s3_heat::readxml(string filename)
{
    TiXmlDocument* Document = new TiXmlDocument();
    if (!Document->LoadFile(filename.c_str()))
    {
        printf("无法加载xml文件！\n");
        return;
    }
    TiXmlElement* RootElement = Document->RootElement();
    TiXmlElement* NextElement = RootElement->FirstChildElement();

    int n = 0;
    for (;NextElement != NULL;NextElement = NextElement->NextSiblingElement())
    {
        TiXmlElement* RuleElement = NextElement->FirstChildElement();
        for (;RuleElement != NULL;RuleElement = RuleElement->NextSiblingElement())
        {
            const char* arr = RuleElement->Attribute("type");
            TiXmlElement *floorlimit = RuleElement->FirstChildElement();
            float floor_limit = atof(floorlimit->GetText());
            TiXmlElement *uplimit = floorlimit->NextSiblingElement();
            float up_limit = atof(uplimit->GetText());

            if (string(arr) == "tdev")
                tdev_range[n].push_back(pair<double, double>(floor_limit, up_limit));
            if (string(arr) == "trise")
                trise_range[n].push_back(pair<double, double>(floor_limit, up_limit));
            if (string(arr) == "tdifference")
                tdifference_range[n].push_back(pair<double, double>(floor_limit, up_limit));
            if (string(arr) == "trd")
                trd_range[n].push_back(pair<double, double>(floor_limit, up_limit));
        }
        ++n;
    }
    delete Document;

    for(int n = 0; n < 3; n++)
    {
        for(int i = 0; i < tdev_range[n].size(); i++)
            fadd_rule(n+1,0,tdev_range[n][i].first,tdev_range[n][i].second);
        for(int i = 0; i < trise_range[n].size(); i++)
            fadd_rule(n+1,1,trise_range[n][i].first,trise_range[n][i].second);
        for(int i = 0; i < tdifference_range[n].size(); i++)
            fadd_rule(n+1,2,tdifference_range[n][i].first,tdifference_range[n][i].second);
        for(int i = 0; i < trd_range[n].size(); i++)
            fadd_rule(n+1,3,trd_range[n][i].first,trd_range[n][i].second);
    }
}

// 读取监控界面的规则，生成xml，并通知检测进程
void s3_heat::createxml(string filename)
{
    for(int n = 0; n < 3; n++)
    {
        tdev_range[n].clear();
        trise_range[n].clear();
        tdifference_range[n].clear();
        trd_range[n].clear();
    }

    int nmax=ui->treeWidget->topLevelItemCount();
    for(int n = 0; n < nmax; n++)
    {
        QTreeWidgetItem *item = ui->treeWidget->topLevelItem(n);

        double min = atof(item->text(1).toStdString().c_str());
        double max = atof(item->text(2).toStdString().c_str());

        if(item->text(0).toStdString()=="设备温度")
            tdev_range[0].push_back(std::make_pair(min,max));
        else if(item->text(0).toStdString()=="设备温升")
            trise_range[0].push_back(std::make_pair(min,max));
        else if(item->text(0).toStdString()=="设备温差")
            tdifference_range[0].push_back(std::make_pair(min,max));
        else if(item->text(0).toStdString()=="相对温差")
            trd_range[0].push_back(std::make_pair(min,max));
    }

    nmax=ui->treeWidget_2->topLevelItemCount();
    for(int n = 0; n < nmax; n++)
    {
        QTreeWidgetItem *item = ui->treeWidget_2->topLevelItem(n);

        double min = atof(item->text(1).toStdString().c_str());
        double max = atof(item->text(2).toStdString().c_str());

        if(item->text(0).toStdString()=="设备温度")
            tdev_range[1].push_back(std::make_pair(min,max));
        else if(item->text(0).toStdString()=="设备温升")
            trise_range[1].push_back(std::make_pair(min,max));
        else if(item->text(0).toStdString()=="设备温差")
            tdifference_range[1].push_back(std::make_pair(min,max));
        else if(item->text(0).toStdString()=="相对温差")
            trd_range[1].push_back(std::make_pair(min,max));
    }

    nmax=ui->treeWidget_3->topLevelItemCount();
    for(int n = 0; n < nmax; n++)
    {
        QTreeWidgetItem *item = ui->treeWidget_3->topLevelItem(n);

        double min = atof(item->text(1).toStdString().c_str());
        double max = atof(item->text(2).toStdString().c_str());

        if(item->text(0).toStdString()=="设备温度")
            tdev_range[2].push_back(std::make_pair(min,max));
        else if(item->text(0).toStdString()=="设备温升")
            trise_range[2].push_back(std::make_pair(min,max));
        else if(item->text(0).toStdString()=="设备温差")
            tdifference_range[2].push_back(std::make_pair(min,max));
        else if(item->text(0).toStdString()=="相对温差")
            trd_range[2].push_back(std::make_pair(min,max));
    }

    TiXmlDocument doc;

    TiXmlElement* root = new TiXmlElement("root");

    // level1 rules
    TiXmlElement* lv1 = new TiXmlElement("level1");
    for(int i = 0; i < tdev_range[0].size(); i++)
    {
        TiXmlElement* rule = new TiXmlElement("rule");
        rule->SetAttribute("type","tdev");
        TiXmlElement* floorlimit = new TiXmlElement("floorlimit");
        floorlimit->LinkEndChild(new TiXmlText(std::to_string(tdev_range[0][i].first).c_str()));
        rule->LinkEndChild(floorlimit);
        TiXmlElement* uplimit = new TiXmlElement("uplimit");
        uplimit->LinkEndChild(new TiXmlText(std::to_string(tdev_range[0][i].second).c_str()));
        rule->LinkEndChild(uplimit);
        lv1->LinkEndChild(rule);
    }
    for(int i = 0; i < trise_range[0].size(); i++)
    {
        TiXmlElement* rule = new TiXmlElement("rule");
        rule->SetAttribute("type","trise");
        TiXmlElement* floorlimit = new TiXmlElement("floorlimit");
        floorlimit->LinkEndChild(new TiXmlText(std::to_string(trise_range[0][i].first).c_str()));
        rule->LinkEndChild(floorlimit);
        TiXmlElement* uplimit = new TiXmlElement("uplimit");
        uplimit->LinkEndChild(new TiXmlText(std::to_string(trise_range[0][i].second).c_str()));
        rule->LinkEndChild(uplimit);
        lv1->LinkEndChild(rule);
    }
    for(int i = 0; i < tdifference_range[0].size(); i++)
    {
        TiXmlElement* rule = new TiXmlElement("rule");
        rule->SetAttribute("type","tdifference");
        TiXmlElement* floorlimit = new TiXmlElement("floorlimit");
        floorlimit->LinkEndChild(new TiXmlText(std::to_string(tdifference_range[0][i].first).c_str()));
        rule->LinkEndChild(floorlimit);
        TiXmlElement* uplimit = new TiXmlElement("uplimit");
        uplimit->LinkEndChild(new TiXmlText(std::to_string(tdifference_range[0][i].second).c_str()));
        rule->LinkEndChild(uplimit);
        lv1->LinkEndChild(rule);
    }
    for(int i = 0; i < trd_range[0].size(); i++)
    {
        TiXmlElement* rule = new TiXmlElement("rule");
        rule->SetAttribute("type","trd");
        TiXmlElement* floorlimit = new TiXmlElement("floorlimit");
        floorlimit->LinkEndChild(new TiXmlText(std::to_string(trd_range[0][i].first).c_str()));
        rule->LinkEndChild(floorlimit);
        TiXmlElement* uplimit = new TiXmlElement("uplimit");
        uplimit->LinkEndChild(new TiXmlText(std::to_string(trd_range[0][i].second).c_str()));
        rule->LinkEndChild(uplimit);
        lv1->LinkEndChild(rule);
    }
    root->LinkEndChild(lv1);

    // level2 rules
    TiXmlElement* lv2 = new TiXmlElement("level2");
    for(int i = 0; i < tdev_range[1].size(); i++)
    {
        TiXmlElement* rule = new TiXmlElement("rule");
        rule->SetAttribute("type","tdev");
        TiXmlElement* floorlimit = new TiXmlElement("floorlimit");
        floorlimit->LinkEndChild(new TiXmlText(std::to_string(tdev_range[1][i].first).c_str()));
        rule->LinkEndChild(floorlimit);
        TiXmlElement* uplimit = new TiXmlElement("uplimit");
        uplimit->LinkEndChild(new TiXmlText(std::to_string(tdev_range[1][i].second).c_str()));
        rule->LinkEndChild(uplimit);
        lv2->LinkEndChild(rule);
    }
    for(int i = 0; i < trise_range[1].size(); i++)
    {
        TiXmlElement* rule = new TiXmlElement("rule");
        rule->SetAttribute("type","trise");
        TiXmlElement* floorlimit = new TiXmlElement("floorlimit");
        floorlimit->LinkEndChild(new TiXmlText(std::to_string(trise_range[1][i].first).c_str()));
        rule->LinkEndChild(floorlimit);
        TiXmlElement* uplimit = new TiXmlElement("uplimit");
        uplimit->LinkEndChild(new TiXmlText(std::to_string(trise_range[1][i].second).c_str()));
        rule->LinkEndChild(uplimit);
        lv2->LinkEndChild(rule);
    }
    for(int i = 0; i < tdifference_range[1].size(); i++)
    {
        TiXmlElement* rule = new TiXmlElement("rule");
        rule->SetAttribute("type","tdifference");
        TiXmlElement* floorlimit = new TiXmlElement("floorlimit");
        floorlimit->LinkEndChild(new TiXmlText(std::to_string(tdifference_range[1][i].first).c_str()));
        rule->LinkEndChild(floorlimit);
        TiXmlElement* uplimit = new TiXmlElement("uplimit");
        uplimit->LinkEndChild(new TiXmlText(std::to_string(tdifference_range[1][i].second).c_str()));
        rule->LinkEndChild(uplimit);
        lv2->LinkEndChild(rule);
    }
    for(int i = 0; i < trd_range[1].size(); i++)
    {
        TiXmlElement* rule = new TiXmlElement("rule");
        rule->SetAttribute("type","trd");
        TiXmlElement* floorlimit = new TiXmlElement("floorlimit");
        floorlimit->LinkEndChild(new TiXmlText(std::to_string(trd_range[1][i].first).c_str()));
        rule->LinkEndChild(floorlimit);
        TiXmlElement* uplimit = new TiXmlElement("uplimit");
        uplimit->LinkEndChild(new TiXmlText(std::to_string(trd_range[1][i].second).c_str()));
        rule->LinkEndChild(uplimit);
        lv2->LinkEndChild(rule);
    }
    root->LinkEndChild(lv2);

    // level3 rules
    TiXmlElement* lv3 = new TiXmlElement("level3");
    for(int i = 0; i < tdev_range[2].size(); i++)
    {
        TiXmlElement* rule = new TiXmlElement("rule");
        rule->SetAttribute("type","tdev");
        TiXmlElement* floorlimit = new TiXmlElement("floorlimit");
        floorlimit->LinkEndChild(new TiXmlText(std::to_string(tdev_range[2][i].first).c_str()));
        rule->LinkEndChild(floorlimit);
        TiXmlElement* uplimit = new TiXmlElement("uplimit");
        uplimit->LinkEndChild(new TiXmlText(std::to_string(tdev_range[2][i].second).c_str()));
        rule->LinkEndChild(uplimit);
        lv3->LinkEndChild(rule);
    }
    for(int i = 0; i < trise_range[2].size(); i++)
    {
        TiXmlElement* rule = new TiXmlElement("rule");
        rule->SetAttribute("type","trise");
        TiXmlElement* floorlimit = new TiXmlElement("floorlimit");
        floorlimit->LinkEndChild(new TiXmlText(std::to_string(trise_range[2][i].first).c_str()));
        rule->LinkEndChild(floorlimit);
        TiXmlElement* uplimit = new TiXmlElement("uplimit");
        uplimit->LinkEndChild(new TiXmlText(std::to_string(trise_range[2][i].second).c_str()));
        rule->LinkEndChild(uplimit);
        lv3->LinkEndChild(rule);
    }
    for(int i = 0; i < tdifference_range[2].size(); i++)
    {
        TiXmlElement* rule = new TiXmlElement("rule");
        rule->SetAttribute("type","tdifference");
        TiXmlElement* floorlimit = new TiXmlElement("floorlimit");
        floorlimit->LinkEndChild(new TiXmlText(std::to_string(tdifference_range[2][i].first).c_str()));
        rule->LinkEndChild(floorlimit);
        TiXmlElement* uplimit = new TiXmlElement("uplimit");
        uplimit->LinkEndChild(new TiXmlText(std::to_string(tdifference_range[2][i].second).c_str()));
        rule->LinkEndChild(uplimit);
        lv3->LinkEndChild(rule);
    }
    for(int i = 0; i < trd_range[2].size(); i++)
    {
        TiXmlElement* rule = new TiXmlElement("rule");
        rule->SetAttribute("type","trd");
        TiXmlElement* floorlimit = new TiXmlElement("floorlimit");
        floorlimit->LinkEndChild(new TiXmlText(std::to_string(trd_range[2][i].first).c_str()));
        rule->LinkEndChild(floorlimit);
        TiXmlElement* uplimit = new TiXmlElement("uplimit");
        uplimit->LinkEndChild(new TiXmlText(std::to_string(trd_range[2][i].second).c_str()));
        rule->LinkEndChild(uplimit);
        lv3->LinkEndChild(rule);
    }
    root->LinkEndChild(lv3);


    doc.LinkEndChild(root);
    doc.SaveFile(filename.c_str());
}

void s3_heat::on_pushButton_7_clicked()
{
    createxml("/home/zxb/SRC_C/Detect/conf.xml");
    emit cmd1();
}
