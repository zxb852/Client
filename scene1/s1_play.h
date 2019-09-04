#ifndef S1_PLAY_H
#define S1_PLAY_H

#include <QDialog>

namespace Ui {
class s1_play;
}

class s1_play : public QDialog
{
    Q_OBJECT

public:
    explicit s1_play(QWidget *parent = nullptr);
    ~s1_play();

private:
    Ui::s1_play *ui;
};

#endif // S1_PLAY_H
