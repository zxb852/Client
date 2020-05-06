#ifndef SCENE2_H
#define SCENE2_H

#include <QDialog>
#include <QtCharts>
#include <QFile>
#include <string>
using std::string;

namespace Ui {
class scene2;
}

class scene2 : public QDialog
{
    Q_OBJECT

public:
    explicit scene2(QWidget *parent = nullptr);
    ~scene2();
signals:
    void callforplot(QDate);


private slots:
    void on_calendarWidget_selectionChanged();
    void returnforplot(string name);

private:
    Ui::scene2 *ui;
    void setchart(QString txtname);
};

#endif // SCENE2_H
