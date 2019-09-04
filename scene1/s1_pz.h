#ifndef S1_PZ_H
#define S1_PZ_H

#include <QDialog>
#include <QList>
#include <QStandardItemModel>
#include <QStandardItem>

namespace Ui {
class s1_pz;
}

class s1_pz : public QDialog
{
    Q_OBJECT

public:
    explicit s1_pz(QWidget *parent = nullptr);
    ~s1_pz();

private:
    Ui::s1_pz *ui;
};

#endif // S1_PZ_H
