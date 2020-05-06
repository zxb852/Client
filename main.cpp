#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(w.windowFlags() &~ Qt::WindowMinMaxButtonsHint);


    Dialog_login D_login;
    QObject::connect(&D_login, SIGNAL(creatsocket( std::shared_ptr<Client> )), &w, SLOT(setsocket(std::shared_ptr<Client>)));

    D_login.show();
    if(D_login.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    else // D_login.exec() == QDialog::Rejected
        return 0;
}
