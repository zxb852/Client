#ifndef DIALOG_LOGIN_H
#define DIALOG_LOGIN_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <string>
#include <memory>
#include "socket_connect_v2.h"
#include <opencv2/opencv.hpp>
using namespace cv;

namespace Ui {
class Dialog_login;
}

class Dialog_login : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_login(QWidget *parent = nullptr);
    ~Dialog_login();

signals:
        void creatsocket( std::shared_ptr<Client> );

private slots:
    void on_B_login_clicked();

    void on_B_loginexit_clicked();

private:
    Ui::Dialog_login *ui;
};

#endif // DIALOG_LOGIN_H
