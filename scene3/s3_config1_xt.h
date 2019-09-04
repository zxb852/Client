#ifndef S3_CONFIG1_XT_H
#define S3_CONFIG1_XT_H

#include <QDialog>

namespace Ui {
class s3_config1_xt;
}

class s3_config1_xt : public QDialog
{
    Q_OBJECT

public:
    explicit s3_config1_xt(QWidget *parent = nullptr);
    ~s3_config1_xt();

private:
    Ui::s3_config1_xt *ui;
};

#endif // S3_CONFIG1_XT_H
