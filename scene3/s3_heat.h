#ifndef S3_HEAT_H
#define S3_HEAT_H

#include <QDialog>

namespace Ui {
class s3_heat;
}

class s3_heat : public QDialog
{
    Q_OBJECT

public:
    explicit s3_heat(QWidget *parent = nullptr);
    ~s3_heat();

private:
    Ui::s3_heat *ui;
};

#endif // S3_HEAT_H
