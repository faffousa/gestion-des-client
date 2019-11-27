#ifndef GCA_H
#define GCA_H

#include <QDialog>

namespace Ui {
class gca;
}

class gca : public QDialog
{
    Q_OBJECT

public:
    explicit gca(QWidget *parent = nullptr);
    ~gca();

private:
    Ui::gca *ui;
};

#endif // GCA_H
