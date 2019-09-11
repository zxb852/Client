#ifndef S3_CONFIG2_H
#define S3_CONFIG2_H

#include <QDialog>

namespace Ui {
class s3_config2;
}

class s3_config2 : public QDialog
{
    Q_OBJECT

public:
    explicit s3_config2(QWidget *parent = nullptr);
    ~s3_config2();

private:
    Ui::s3_config2 *ui;
};

#endif // S3_CONFIG2_H
