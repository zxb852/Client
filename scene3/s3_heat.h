#ifndef S3_HEAT_H
#define S3_HEAT_H

#include <QDialog>
#include <QList>
#include <QTreeWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include "s3_heat_add.h"

namespace Ui {
class s3_heat;
}

class s3_heat : public QDialog
{
    Q_OBJECT

public:
    explicit s3_heat(QWidget *parent = nullptr);
    ~s3_heat();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void add_rule_common(add_rule new_ruel);
    void add_rule_hard(add_rule new_ruel);
    void add_rule_boom(add_rule new_ruel);

private:
    Ui::s3_heat *ui;

    QStandardItemModel *model;
    QStandardItemModel *model2;
    QStandardItemModel *model3;

    void fadd_rule(int level,int mode,double min,double max);
};

#endif // S3_HEAT_H
