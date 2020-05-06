#ifndef DIALOG_ALARM_H
#define DIALOG_ALARM_H

#include <QDialog>

namespace Ui {
class Dialog_alarm;
}

class Dialog_alarm : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_alarm(QWidget *parent = nullptr);
    ~Dialog_alarm();
    void settype(int type);
private:
    Ui::Dialog_alarm *ui;
};

#endif // DIALOG_ALARM_H
