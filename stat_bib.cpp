#include "stat_bib.h"
#include "ui_stat_bib.h"

stat_bib::stat_bib(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_bib)
{
    ui->setupUi(this);
}

int stat_bib::tot_m()
{
int numtot=0;
QSqlQuery query;
int homme;
query.prepare("SELECT * from CLIENT where SEXE = :m");
query.bindValue(":m", "m");
query.exec();
while (query.next()) {
    numtot++;
}
return  numtot;
}
int stat_bib::tot_f()
{
int numtot=0;
QString femme;
QSqlQuery query;
query.prepare("SELECT * from CLIENT where SEXE = :f");
query.bindValue(":f", "f");
query.exec();
while (query.next()) {
    numtot++;
}
return  numtot;
}


stat_bib::~stat_bib()
{
    delete ui;
}

void stat_bib::on_pushButton_4_clicked()
{
    int totf=tot_f();
    int totm=tot_m();
    int tot=totf+totm;
    int percent=0;
    QString totf1=QString::number(totf);
    QString totm1=QString::number(totm);



    percent = (totm*100)/tot;
    ui->math->setValue(percent);
    percent = (totf*100)/tot;
    ui->francais->setValue(percent);

}

void stat_bib::on_pushButton_5_clicked()
{
    hide();
}




