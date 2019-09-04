#ifndef S3_WATER_H
#define S3_WATER_H

#include <QDialog>

namespace Ui {
class s3_water;
}

class s3_water : public QDialog
{
    Q_OBJECT

public:
    explicit s3_water(QWidget *parent = nullptr);
    ~s3_water();

private:
    Ui::s3_water *ui;
};

#endif // S3_WATER_H
