#ifndef SCENE1_H
#define SCENE1_H

#include <QDialog>
#include <QStackedWidget>
#include "s1_play.h"
#include "s1_jk.h"
#include "s1_pz.h"
#include "s1_yt.h"

namespace Ui {
class Scene1;
}

class Scene1 : public QDialog
{
    Q_OBJECT

public:
    explicit Scene1(QWidget *parent = nullptr);
    ~Scene1();
    WId getplaywnd(int type)
    {
        return ps1_play->getplaywnd(type);
    }

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Scene1 *ui;

    QStackedWidget * qs_s1_play;
    QStackedWidget * qs_s1_right;

    s1_play *ps1_play;
    s1_jk *ps1_jk;
    s1_pz *ps1_pz;
    s1_yt *ps1_yt;
};

#endif // SCENE1_H
