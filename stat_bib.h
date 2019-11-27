#ifndef STAT_BIB_H
#define STAT_BIB_H

#include <QDialog>
#include <QSqlQuery>

namespace Ui {
class stat_bib;
}

class stat_bib : public QDialog
{
    Q_OBJECT

public:
    explicit stat_bib(QWidget *parent = nullptr);
    int tot_f();
    int tot_m();
    ~stat_bib();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();



private:
    Ui::stat_bib *ui;
};

#endif // STAT_BIB_H
