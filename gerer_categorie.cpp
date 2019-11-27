#include "gerer_categorie.h"
#include "categorie.h"
#include "ui_gerer_categorie.h"
#include <QMessageBox>
#include <QString>

#include <QtWidgets>
#include<QPixmap>

gerer_categorie::gerer_categorie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gerer_categorie)
{
    ui->setupUi(this);
    QMovie *movie = new QMovie("snow.gif");
        ui->back->setMovie(movie);
        ui->back_2->setMovie(movie);

        movie->start();

  ui->table1->setModel(tmpcategorie.afficher());

}

gerer_categorie::~gerer_categorie()
{
    delete ui;
}

void gerer_categorie::on_pushButton_4_clicked()
{
    bool test;
    QString NOM =ui->lineEdit_4->text();

    int TAUX_REDUCTION =ui->lineEdit_2->text().toInt();
    categorie c(NOM,TAUX_REDUCTION);
    test=c.ajouter();
    if(test)
    {ui->table1->setModel(tmpcategorie.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter une categorie"),
                      QObject::tr("categorie ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          {QMessageBox::critical(nullptr, QObject::tr("Ajouter une categorie"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);}


    }




void gerer_categorie::on_pushButton_3_clicked()
{
    QString NOM = ui->lineEdit_3->text();
    bool test=tmpcategorie.supprimer(NOM);
    if(test)
    {ui->table1->setModel(tmpcategorie.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une categorie"),
                    QObject::tr("categorie supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une categorie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }


void gerer_categorie::on_pushButton_2_clicked()
{

        QString NOM=ui->lineEdit_4->text();
        float TAUX_REDUCTION=ui->lineEdit_2->text().toFloat();
          categorie c(NOM,TAUX_REDUCTION);
        bool test2= c.modifier();
        if(test2)
        {
            ui->table1->setModel(tmpcategorie.afficher());//refresh

                 QMessageBox::information(nullptr, QObject::tr("modifier une categorie"),
                             QObject::tr("categorie modifié.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

             }
             else
                 QMessageBox::critical(nullptr, QObject::tr("modifier une categorie"),
                             QObject::tr("Erreur !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}
void gerer_categorie::on_pushButton_clicked()
{

    QString NOM=ui->noom->text();
                    ui->noom->clear();
                    QSqlQueryModel *model;
                    categorie *c=new categorie();

                          QString nom,taux_reduction;




                            QSqlQuery  *q  = new QSqlQuery();
                            q->prepare("select * from CATEGORIE where (NOM=:NOM)");
                            q->addBindValue(NOM);
                            if(q->exec())
                            {
                                while(q->next())
                                {


                                    NOM=q->value(0).toString();
                                    taux_reduction=q->value(1).toString();


                                }
                            }

                            ui->lineEdit_4->setText(NOM);
                            ui->lineEdit_2->setText(taux_reduction);
}
