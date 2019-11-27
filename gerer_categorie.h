#ifndef GERER_CATEGORIE_H
#define GERER_CATEGORIE_H

#include <QDialog>
#include "categorie.h"
namespace Ui {
class gerer_categorie;
}

class gerer_categorie : public QDialog
{
    Q_OBJECT

public:
    explicit gerer_categorie(QWidget *parent = nullptr);
    ~gerer_categorie();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::gerer_categorie *ui;
    categorie tmpcategorie;
};

#endif // GERER_CLIENT_H
