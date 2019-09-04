#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QTime>
#include <QTimer>
#include <QLCDNumber>
#include "dialog_login.h"
#include "scene1.h"
#include "scene2.h"
#include "scene3.h"
#include "scene4.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void showTime();

private:
    Ui::MainWindow *ui;
    QLCDNumber *time;
    QStackedWidget * qs_main;


    Scene1 *ps1;
    scene2 *ps2;
    scene3 *ps3;
    scene4 *ps4;
//    s1_play *ps1_play;
//    s1_jk *ps1_jk;
//    s1_pz *ps1_pz;
//    s1_yt *ps1_yt;
};

#endif // MAINWINDOW_H