#include "mainwindow.h"
#include <QApplication>
#include "connexion.h"
#include <iostream>
#include <QMessageBox>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connexion c;
    w.show();
    bool test=c.ouvrirConnexion();
    if(test){w.show();
    QMessageBox::information(nullptr,QObject::tr("DataBase ope"),QObject::tr("connection ok"), QMessageBox::Cancel);
    }

    return a.exec();
}
