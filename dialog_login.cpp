#include "dialog_login.h"
#include "ui_dialog_login.h"

Dialog_login::Dialog_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_login)
{
    ui->setupUi(this);
}

Dialog_login::~Dialog_login()
{
    delete ui;
}

void Dialog_login::on_B_login_clicked()
{
    QString tip=ui->text_ip->text();
    QString tport=ui->text_port->text();
    QString tuser=ui->text_user->text();
    QString tpassword=ui->text_password->text();

    std::string str_ip=tip.toStdString();
    int int_port=tport.toInt();
    std::string str_user=tuser.toStdString();
    std::string str_password=tpassword.toStdString();

    std::shared_ptr<client> ptr_client=std::make_shared<client>();
    if( ptr_client->s_connect(str_ip.c_str(),int_port) )
    {
        ptr_client->send_buff_push(login_mes(str_user, str_password));
        emit creatsocket(ptr_client);
        this->accept();
    }
    else
    {
        qDebug()<< "login failed"<< endl;
    }
    this->accept();
}

void Dialog_login::on_B_loginexit_clicked()
{
     this->reject();
}
