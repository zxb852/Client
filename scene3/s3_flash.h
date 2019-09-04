#ifndef S3_FLASH_H
#define S3_FLASH_H

#include <QDialog>

namespace Ui {
class s3_flash;
}

class s3_flash : public QDialog
{
    Q_OBJECT

public:
    explicit s3_flash(QWidget *parent = nullptr);
    ~s3_flash();

private:
    Ui::s3_flash *ui;
};

#endif // S3_FLASH_H
