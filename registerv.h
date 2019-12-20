#ifndef REGISTERV_H
#define REGISTERV_H

#include <QWidget>
#include "basewidget.h"
namespace Ui {
class RegisterV;
}

class RegisterV : public BaseWidget
{
    Q_OBJECT

public:
    explicit RegisterV(QWidget *parent = nullptr);
    ~RegisterV();

private:
    Ui::RegisterV *ui;
};

#endif // REGISTERV_H
