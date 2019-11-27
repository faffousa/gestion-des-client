#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gerer_client.h"
#include<QMessageBox>
#include "gerer_categorie.h"
#include <QPixmap>
#include<QLabel>
#include <QtWidgets>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
son=new QSound("fares.wav");
son->play();
QMovie *movie = new QMovie("snow.gif");
    ui->back->setMovie(movie);
    movie->start();
//ui->tab_1->setModel(tmpclient.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    gerer_client gc;
    gc.setModal(true);
    gc.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    gerer_categorie gcca;
    gcca.setModal(true);
    gcca.exec();
}
