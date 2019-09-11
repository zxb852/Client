#ifndef S3_CONFIG3_H
#define S3_CONFIG3_H

#include <QDialog>

namespace Ui {
class s3_config3;
}

class s3_config3 : public QDialog
{
    Q_OBJECT

public:
    explicit s3_config3(QWidget *parent = nullptr);
    ~s3_config3();

private:
    Ui::s3_config3 *ui;
};

#endif // S3_CONFIG3_H
