#ifndef S3_HEAT_H
#define S3_HEAT_H

#include <QDialog>
#include <QList>
#include <QTreeWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include "s3_heat_add.h"
using std::string;
using std::pair;
using std::vector;

namespace Ui {
class s3_heat;
}

class s3_heat : public QDialog
{
    Q_OBJECT

public:
    explicit s3_heat(QWidget *parent = nullptr);
    ~s3_heat();

    void readxml(string filename);
    void createxml(string filename);
signals:
    void cmd1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void add_rule_common(add_rule new_ruel);
    void add_rule_hard(add_rule new_ruel);
    void add_rule_boom(add_rule new_ruel);

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::s3_heat *ui;

    //警报阈值以及标志，三元数组代表三种级别的故障。
    vector<pair<double, double>> tdev_range[3];			//设备温度的警报范围
    vector<pair<double, double>> trise_range[3];		//温升的警报范围
    vector<pair<double, double>> tdifference_range[3];  //温差的警报范围
    vector<pair<double, double>> trd_range[3];			//相对温差的警报范围

    void fadd_rule(int level,int mode,double min,double max);
};

#endif // S3_HEAT_H
