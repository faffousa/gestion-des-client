#include "gerer_client.h"
#include "client.h"
#include "ui_gerer_client.h"
#include "client.h"
#include <QMessageBox>
#include <QPixmap>
#include <QtWidgets>
#include <QString>
#include<QSqlError>
#include<QtCharts>
#include<QPieSeries>
#include<QApplication>
#include "stat_bib.h"
#include "notification.h"
#define CARACTERE_SPECIAUX "&é~\"#'{([-|è`_\ç^à@)]=}aze€rtyuiop¨$£¤qsdfghjklmù%*µ<>wxcvbn,?;.:/!§+"

QT_CHARTS_USE_NAMESPACE

gerer_client::gerer_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gerer_client)
{
    ui->setupUi(this);
    QMovie *movie = new QMovie("snow.gif");
        ui->back->setMovie(movie);
        ui->back_2->setMovie(movie);
        movie->start();
    ui->tab_1->setModel(tmpclient.afficher());

}

gerer_client::~gerer_client()
{
    delete ui;
}



void gerer_client::on_pushButton_clicked()
{
    bool test;
    int m=-1;
    notification n;

    QString var=ui->lineEdit_4->text();
    for (int i = 0; i < ui->lineEdit_4->text().length(); i++){
             if(var[i]!="0" && var[i]!="1" && var[i]!="2" && var[i]!="3"&& var[i]!="4" && var[i]!="5" && var[i]!="6" && var[i]!="7" && var[i]!="8" && var[i]!="9"){
                 m=0;
             }
         else{m=1;
             ui->lineEdit_4->clear();
             }}



    QString NOM =ui->lineEdit_4->text();

    QString PRENOM =ui->lineEdit->text();
    int CIN =ui->lineEdit_2->text().toInt();
    int TEL =ui->lineEdit_3->text().toInt();
    QString CATEGORIE= ui->comboBox->currentText();
    int CODE_POSTAL =ui->lineEdit_5->text().toInt();
    QString SEXE= ui->comboBox_2->currentText();
    client c(NOM,PRENOM,TEL,SEXE,CODE_POSTAL,CIN,CATEGORIE);
    if(m==0){test=c.ajouter();
        QString titre="succée";
        QString ams="ajouté";
        n.notification_ajout_client(CIN);

        ui->tab_1->setModel(tmpclient.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                              QObject::tr("client ajouté.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


    }
    if(m==1 ){   QMessageBox::critical(nullptr, QObject::tr("client non ajouter"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}
    }



void gerer_client::on_pushButton_3_clicked()
{
    int cin = ui->lineEdit_6->text().toInt();
    bool test=tmpclient.supprimer(cin);
    if(test)
    {ui->tab_1->setModel(tmpclient.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }


void gerer_client::on_pushButton_2_clicked()
{

        QString NOM=ui->lineEdit_4->text();
        QString PRENOM=ui->lineEdit->text();
        int TEL=ui->lineEdit_3->text().toInt();
        QString SEXE=ui->comboBox_2->currentText();
        QString CATEGORIE=ui->comboBox->currentText();
        int CODE_POSTAL =ui->lineEdit_5->text().toInt();
        int CIN=ui->lineEdit_2->text().toInt();
        client c (NOM,PRENOM,TEL,SEXE,CODE_POSTAL,CIN,CATEGORIE);
        bool test2= c.modifier();
        if(test2)
        {
            ui->tab_1->setModel(tmpclient.afficher());//refresh

                 QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                             QObject::tr("client modifié.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

             }
             else
                 QMessageBox::critical(nullptr, QObject::tr("modifier un client"),
                             QObject::tr("Erreur !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}
void gerer_client::on_pushButton_5_clicked()
{

    QString CIN=ui->ciin->text();
                    ui->ciin->clear();
                    QSqlQueryModel *model;
                    client *c=new client();

                          QString SEXE,NOM,PRENOM,TEL,CODE_POSTAL,CATEGORIE;




                            QSqlQuery  *q  = new QSqlQuery();
                            q->prepare("select * from CLIENT where (CIN=:CIN)");
                            q->addBindValue(CIN);
                            if(q->exec())
                            {
                                while(q->next())
                                {


                                    NOM=q->value(0).toString();
                                    PRENOM=q->value(1).toString();
                                    TEL=q->value(2).toString();
                                     SEXE=q->value(3).toString();
                                     CODE_POSTAL=q->value(4).toString();
                                     CIN=q->value(5).toString();
                                     CATEGORIE=q->value(6).toString();


                                }
                            }

                            ui->lineEdit_4->setText(NOM);
                            ui->lineEdit->setText(PRENOM);
                            ui->lineEdit_3->setText(TEL);
                            ui->comboBox_2->setCurrentText(SEXE);
                            ui->lineEdit_5->setText(CODE_POSTAL);
                            ui->lineEdit_2->setText(CIN);
                            ui->comboBox->setCurrentText(CATEGORIE);
}

//shinkyokushin

void gerer_client::on_comboBox_activated(const QString &arg1)
{

}



void gerer_client::on_pushButton_4_clicked()
{
    QSqlQueryModel * modal= new QSqlQueryModel;
   QSqlQuery *mode= new QSqlQuery;
   mode->prepare("SELECT NOM FROM CATEGORIE");
   mode->exec();
   modal->setQuery(*mode);
   ui->comboBox->setModel(modal);
}

/*void gerer_client::on_chercher_clicked()
{
    client p;
            QSqlQueryModel * model=new QSqlQueryModel();
           p.setcin(ui->lineEdit_7->text().toInt());
            model=p.rechercher();
            ui->tab_3->setModel(model);
            if(model->lastError().isValid())
            {
              qDebug()<<model->lastError();
              ui->tab_3->show();
            }
}*/


void gerer_client::on_pushButton_19_clicked()
{
    stat_bib sb;
    sb.setModal(true);
    sb.exec();
}

void gerer_client::on_lineEdit_7_textChanged(const QString &arg1)
{
    client c;
        QSqlQueryModel *model=c.rechercher_client(ui->lineEdit_7->text());
        ui->tab_3->setModel(model);
}
