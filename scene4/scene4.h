#ifndef SCENE4_H
#define SCENE4_H

#include <QDialog>
#include <QList>
#include <QLabel>
#include <QStandardItemModel>
#include <QStandardItem>
#include "data.h"

namespace Ui {
class scene4;
}

class scene4 : public QDialog
{
    Q_OBJECT

public:
    explicit scene4(QWidget *parent = nullptr);
    ~scene4();
    WId getplaywid();
    void process(int value);

signals:
    void Download_Vedio(record_time,record_time,int);
    void Capture();
    void Play_Vedio(record_time,record_time,int);
    void Stop_vedio();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();



private:
    Ui::scene4 *ui;
    record_time begin;
    record_time end;
    void get_uidata();
};

#endif // SCENE4_H
