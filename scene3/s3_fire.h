#ifndef S3_FIRE_H
#define S3_FIRE_H

#include <QDialog>

namespace Ui {
class s3_fire;
}

class s3_fire : public QDialog
{
    Q_OBJECT

public:
    explicit s3_fire(QWidget *parent = nullptr);
    ~s3_fire();

private:
    Ui::s3_fire *ui;
};

#endif // S3_FIRE_H
