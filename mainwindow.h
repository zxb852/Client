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
#include "client_sdk.h"
using std::vector;
using std::pair;
using std::string;

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
    void setsocket(std::shared_ptr<client> ptr_client);

    void Download_Vedio(record_time begin,record_time end,int port);
    void Capture();
    void Play_Vedio(record_time begin,record_time end,int port);
    void Stop_vedio();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void playvedio(int mode);

    void Update();


private:
    Ui::MainWindow *ui;

    Client_SDK sdk;
    std::shared_ptr<client> ptr_client;

    QLCDNumber *time;
    QStackedWidget * qs_main;
    vector<pair<state_mes,vector<string>>> v_alarm;

    Scene1 *ps1;
    scene2 *ps2;
    scene3 *ps3;
    scene4 *ps4;


    std::string base;
    QTimer * timer;

    void showTime();
};
Mat QImage2cvMat(QImage image);
QImage MatToQImage(const cv::Mat& mat) ;

#endif // MAINWINDOW_H
