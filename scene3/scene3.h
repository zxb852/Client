#ifndef SCENE3_H
#define SCENE3_H

#include <QDialog>
#include <QStackedWidget>
#include "s3_fire.h"
#include "s3_flash.h"
#include "s3_heat.h"
#include "s3_water.h"
#include "s3_config1_xt.h"
#include "s3_config2.h"
#include "s3_config3.h"

namespace Ui {
class scene3;
}

class scene3 : public QDialog
{
    Q_OBJECT

public:
    explicit scene3(QWidget *parent = nullptr);
    ~scene3();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::scene3 *ui;

    QString selected;
    QString unselected;
    QStackedWidget *qs;
    QStackedWidget *qs_config;

    s3_fire *ps3_fire;
    s3_flash *ps3_flash;
    s3_heat *ps3_heat;
    s3_water *ps3_water;
    s3_config1_xt *ps3_config1_xt;
    s3_config2 *ps3_config2;
    s3_config3 *ps3_config3;
};

#endif // SCENE3_H
