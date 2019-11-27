#include "client.h"
#include <QDebug>
#include <QMessageBox>

 client::client(QString NOM,QString PRENOM,int TEL,QString SEXE,int CODE_POSTAL,int CIN,QString CATEGORIE)
 {

     this->NOM=NOM;
     this->PRENOM=PRENOM;
     this->TEL=TEL;
     this->SEXE=SEXE;
     this->CODE_POSTAL=CODE_POSTAL;
     this->CIN=CIN;
     this->CATEGORIE=CATEGORIE;
 }
 bool client::ajouter()
 {
 QSqlQuery query;
 query.prepare("INSERT INTO CLIENT ( NOM, PRENOM, TEL, SEXE, CODE_POSTAL, CIN, CATEGORIE) "
                     "VALUES (:NOM, :PRENOM, :TEL, :SEXE, :CODE_POSTAL, :CIN, :CATEGORIE)");

 query.bindValue(":NOM", NOM);
 query.bindValue(":PRENOM", PRENOM);
 query.bindValue(":TEL", TEL);
 query.bindValue(":SEXE", SEXE);
 query.bindValue(":CODE_POSTAL", CODE_POSTAL);
 query.bindValue(":CIN", CIN);
  query.bindValue(":CATEGORIE", CATEGORIE);
//query.prepare("WHERE not exists (select NOM from CLIENT where NOM = NOM)");
 return    query.exec();
 }

 QSqlQueryModel * client::afficher()
 {QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select * from CLIENT");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM "));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEL"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("SEXE"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("CODE_POSTAL"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN"));
 model->setHeaderData(6, Qt::Horizontal, QObject::tr("CATEGORIE"));


     return model;
 }
 bool client::supprimer(int CIN)
 {

 QSqlQuery query;
 query.prepare("Delete from CLIENT where CIN = :CIN ");
 query.bindValue(":CIN", CIN);
 return    query.exec();
 }
bool client::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE  CLIENT set   NOM=:NOM , PRENOM=:PRENOM, TEL=:TEL, CODE_POSTAL=:CODE_POSTAL, SEXE=:SEXE, CIN=:CIN, CATEGORIE=:CATEGORIE where( CIN=:CIN)");

    query.bindValue(":NOM",NOM);
    query.bindValue(":PRENOM",PRENOM);
    query.bindValue(":TEL",TEL);
    query.bindValue(":SEXE",SEXE);
    query.bindValue(":CODE_POSTAL",CODE_POSTAL);
    query.bindValue(":CIN",CIN);
    query.bindValue(":CATEGORIE",CATEGORIE);
    return  query.exec();
}
QSqlQueryModel * client::rechercher_client(QString NOM)
{



    QString req="select * from CLIENT where NOM like '%'||?||'%' " ;
    QSqlQuery qry;
    qry.prepare(req);


    qry.addBindValue(NOM);
    QSqlQueryModel *model=new QSqlQueryModel();
    qry.exec();
    model->setQuery(qry);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TEL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("SEXE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("CODE_POSTAL"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("CATEGORIE"));

    return model;
}
/*QSqlQueryModel *client::rechercher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
       QSqlQuery q;
       q.prepare("select * from CLIENT where (CIN=:CIN) ");
       q.addBindValue(getcin());
       q.exec();
     model->setQuery(q);
     return(model);
}*/
