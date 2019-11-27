#ifndef categorie_H
#define categorie_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class categorie
{
public:
    categorie()
    {}
    categorie(QString,int);
    QSqlQueryModel *rechercher();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier();
    QString getnom()
    {return  NOM ;
    }
    void setnom (QString noom)
    {NOM=noom;}
private:
   QString NOM;
   int TAUX_REDUCTION;

};

#endif // categorie_H
