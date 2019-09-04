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

private:
    Ui::s1_yt *ui;
};

#endif // S1_YT_H
