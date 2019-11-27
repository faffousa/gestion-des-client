#include "statistique.h"
#include<QPainter>
statistique::statistique(QWidget *parent) : QWidget(parent)
{

}

void statistique::Paintevent(QPaintEvent *)
{
    QPainter painter(this);
    QRectF size= QRectF(10,10,this->width()-10,this->width()-10);
    painter.setBrush(Qt::red);
    painter.drawPie(size,0,90*14);
    painter.setBrush(Qt::blue);
    painter.drawPie(size,90*16,270*16);
}

