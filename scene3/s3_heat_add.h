#ifndef S3_HEAT_ADD_H
#define S3_HEAT_ADD_H

#include <QDialog>

namespace Ui {
class s3_heat_add;
}

struct add_rule
{
    add_rule(int mode,double min,double max):mode(mode),min(min),max(max)
    {}
    int mode;
    double min;
    double max;
};

class s3_heat_add : public QDialog
{
    Q_OBJECT

public:
    explicit s3_heat_add(int level,QWidget *parent = nullptr);
    ~s3_heat_add();

signals:
    void rule_common(add_rule new_rule);
    void rule_hard(add_rule new_rule);
    void rule_boom(add_rule new_rule);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::s3_heat_add *ui;
    int level;
};

#endif // S3_HEAT_ADD_H
