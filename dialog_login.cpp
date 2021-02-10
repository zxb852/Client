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

    std::shared_ptr<Client> ptr_client=std::make_shared<Client>();
    if (!ptr_client->s_connect(str_ip.c_str(),int_port))
    {
        qDebug()<< "connect failed"<< endl;
        this->reject();
    }
    cout << "connect successfully!" << endl;

    Login_mes login_mes("client","123");
    ptr_client->sendbuff_push(login_mes);
    while (!ptr_client->recvbuff_pop(login_mes));
    if (login_mes.confirm != 3)
    {
        qDebug()<< "Login failed"<< endl;
        this->reject();
    }
    cout << "login successfully!" << endl;
    login_mes.confirm = 1;
    ptr_client->sendbuff_push(login_mes);

    ptr_client->setbasefile("/home/zxb/SRC_C/data/Client_data/");
    emit creatsocket(ptr_client);

    this->accept();
}

void Dialog_login::on_B_loginexit_clicked()
{
     this->reject();
}
