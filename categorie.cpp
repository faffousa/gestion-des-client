#include "categorie.h"
#include <QDebug>

 categorie::categorie(QString NOM,int TAUX_REDUCTION)
 {

     this->NOM=NOM;
     this->TAUX_REDUCTION=TAUX_REDUCTION;
 }
 bool categorie::ajouter()
 {
 QSqlQuery query;
 query.prepare("INSERT INTO CATEGORIE (NOM, TAUX_REDUCTION) "
                     " VALUES (:NOM, :TAUX_REDUCTION)");

 query.bindValue(":NOM", NOM);
 query.bindValue(":TAUX_REDUCTION", TAUX_REDUCTION);

 return    query.exec();
 }

 QSqlQueryModel * categorie::afficher()
 {QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select * from CATEGORIE");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("TAUX_REDUCTION"));


     return model;
 }
 bool categorie::supprimer(QString nom)
 {

 QSqlQuery query;
 query.prepare("Delete from CATEGORIE where NOM = :NOM ");
 query.bindValue(":NOM", nom);
 return    query.exec();
 }
bool categorie::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE  CATEGORIE set   NOM=:NOM , TAUX_REDUCTION=:TAUX_REDUCTION");

    query.bindValue(":NOM",NOM);
    query.bindValue(":TAUX_REDUCTION",TAUX_REDUCTION);

    return  query.exec();
}
QSqlQueryModel *categorie::rechercher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
       QSqlQuery q;
       q.prepare("select * from CATEGORIE where (NOM=:NOM) ");
       q.addBindValue(getnom());
       q.exec();
     model->setQuery(q);
     return(model);
}
