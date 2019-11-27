#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QWidget>

class statistique : public QWidget
{
    Q_OBJECT
public:
    explicit statistique(QWidget *parent = 0);
protected:
    void Paintevent(QPaintEvent *);
signals:

public slots:
};

#endif // STATISTIQUE_H
