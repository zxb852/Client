#ifndef S1_YT_H
#define S1_YT_H

#include <QDialog>

namespace Ui {
class s1_yt;
}

class s1_yt : public QDialog
{
    Q_OBJECT

public:
    explicit s1_yt(QWidget *parent = nullptr);
    ~s1_yt();

private slots:
    void on_B_base_up_clicked();

    void on_B_base_down_clicked();

    void on_B_base_left_clicked();

    void on_B_base_right_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_B_point_clicked();

    void on_B_point_2_clicked();

    void on_B_point_3_clicked();


signals:
    void ptz_move(int mode,int speed);
    void ptz_prset(int mode,int pnum);

private:
    Ui::s1_yt *ui;
};

#endif // S1_YT_H
