#ifndef SCENE4_H
#define SCENE4_H

#include <QDialog>

namespace Ui {
class scene4;
}

class scene4 : public QDialog
{
    Q_OBJECT

public:
    explicit scene4(QWidget *parent = nullptr);
    ~scene4();

private:
    Ui::scene4 *ui;
};

#endif // SCENE4_H
