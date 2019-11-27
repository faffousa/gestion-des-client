#ifndef GERER_CLIENT_H
#define GERER_CLIENT_H

#include <QDialog>
#include "client.h"
namespace Ui {
class gerer_client;
}

class gerer_client : public QDialog
{
    Q_OBJECT

public:
    explicit gerer_client(QWidget *parent = nullptr);
    ~gerer_client();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();
    void on_lineEdit_recherche_textChanged(const QString &arg1);


    void on_comboBox_activated(const QString &arg1);

    void on_chercher_clicked();


    void on_pushButton_4_clicked();

    void on_pushButton_19_clicked();

    void on_lineEdit_7_textChanged(const QString &arg1);

private:
    Ui::gerer_client *ui;
    client tmpclient;
};

#endif // GERER_CLIENT_H
