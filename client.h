#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class client
{
public:
    client()
    {}
    client(QString,QString,int,QString,int,int,QString);
    //QSqlQueryModel *rechercher();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    int getcin()
    {return  CIN ;
    }
    void setcin (int ciin)
    {CIN=ciin;}
    bool testString(QString);
    QSqlQueryModel * rechercher_client(QString);
private:
   QString NOM,PRENOM,SEXE,CATEGORIE;
    int CIN;
    int SALAIRE;
    int TEL;
    int CODE_POSTAL;

};

#endif // CLIENT_H
