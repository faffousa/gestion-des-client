#include "notification.h"
#include<QSystemTrayIcon>
#include<QString>
notification::notification()
{
    num=0;

}
void notification::notification_ajout_client(int num)
{

    int cin=num;
    QSystemTrayIcon *notifyicon=new QSystemTrayIcon;
    notifyicon->show();
    notifyicon->setIcon(QIcon("add.png"));
    QString s= QString::number(cin);
    notifyicon->showMessage("ajouter client","un nouveau client avec cin: "+s+" a ete ajouter",QSystemTrayIcon::Information,15000);

}



void notification::notification_ajout_categorie(int num)
{

    int number=num;
    QSystemTrayIcon *notifyicon=new QSystemTrayIcon;
    notifyicon->show();
    QString s= QString::number(number);
    notifyicon->showMessage("ajouter bloc","un nouveau bloc "+s+" a ete ajouter",QSystemTrayIcon::Information,15000);
}
