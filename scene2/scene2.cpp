#include "scene2.h"
#include "ui_scene2.h"
#include <unistd.h>
#include <QDebug>
#include <QTreeWidgetItem>
#include <QString>

scene2::scene2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scene2)
{
    ui->setupUi(this);

    QDate nowaday = ui->calendarWidget->selectedDate();
    QString filename = QString::number(nowaday.year())+"-"+QString::number(nowaday.month())+"-"+QString::number(nowaday.day());
    setchart(filename);

}

scene2::~scene2()
{
    delete ui;
}

void scene2::setchart(QString txtname)
{
    QChartView *chartView = new QChartView(this);
    QChart *chart = new QChart();
    chart->setTitle("设备温度曲线");   //图标的名字
    chartView->setChart(chart);
    ui->scrollArea->setWidget(chartView);

    //创建曲线序列
    QLineSeries *series0 = new QLineSeries();
    series0->setName("温度曲线");   //自动添加折线名字
    chart->addSeries(series0);

    if(!txtname.isEmpty())
    {
        printf("no empty1\n");
        fflush(NULL);

        QFile qf(txtname);
        qf.open(QIODevice::ReadOnly | QIODevice::Text);
        QString strpoint;

        //序列添加数值
        qreal x,y;
        while(!qf.atEnd())
        {
            strpoint=qf.readLine();
            QStringList xy=strpoint.split(",");
            if(xy.size()==2)
            {
                x=xy[0].toDouble();
                y=xy[1].toDouble();
                series0->append(x,y);
            }

        }
    }
    //创建坐标
    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0, 24);//设置坐标轴范围
    axisX->setTitleText("time(h)");//标题
    axisX->setLabelFormat("%.1f"); //标签格式：每个单位保留几位小数
    axisX->setTickCount(20); //主分隔个数：0到10分成20个单位
    axisX->setMinorTickCount(4); //每个单位之间绘制了多少虚网线
    //    axisX->setGridLineVisible(false);

    QValueAxis *axisY = new QValueAxis; //Y 轴
    axisY->setRange(0, 20);
    axisY->setTitleText("value");
    axisY->setLabelFormat("%.2f"); //标签格式
    axisY->setTickCount(10);
    axisY->setMinorTickCount(4);
    //    axisX->setGridLineVisible(false);

    //为序列设置坐标轴
    chart->setAxisX(axisX, series0);
    chart->setAxisY(axisY, series0);
}

void scene2::on_calendarWidget_selectionChanged()
{
    QDate nowaday = ui->calendarWidget->selectedDate();

    emit callforplot(nowaday);
    setchart("");
}

void scene2::returnforplot(string name)
{
    setchart(QString::fromStdString(name));
}
