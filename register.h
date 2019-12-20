#ifndef REGISTER_H
#define REGISTER_H

//#include <QWidget>
#include "basewidget.h"
namespace Ui {
class Register;
}

class Register : public BaseWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
