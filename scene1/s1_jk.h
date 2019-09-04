#ifndef S1_JK_H
#define S1_JK_H

#include <QDialog>
#include <QList>
#include <QTreeWidget>
#include <QStandardItemModel>
#include <QStandardItem>

namespace Ui {
class s1_jk;
}

class s1_jk : public QDialog
{
    Q_OBJECT

public:
    explicit s1_jk(QWidget *parent = nullptr);
    ~s1_jk();

private:
    Ui::s1_jk *ui;
    QTreeWidget* treeWidget;
    QTreeWidgetItem* A;
    QTreeWidgetItem* B;
    QTreeWidgetItem* C;
    QTreeWidgetItem* D;
    QTreeWidgetItem* E;

    enum twconfig_user{none=1,common_user=2,admin=3};
    enum twconfig_state{heat_on=1,heat_off=2,fire_on=3,fire_off=4,water_on=5,water_off=6,flash_on=7,flash_off=8 ,\
                        heat_am=9,fire_am=10,water_am=11,flash_am=12};
    void settw(twconfig_user user,twconfig_state state);
};

#endif // S1_JK_H
