#include "gca.h"
#include "ui_gca.h"

gca::gca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gca)
{
    ui->setupUi(this);
}

gca::~gca()
{
    delete ui;
}
