#include "register.h"
#include "registerv.h"
#include "ui_register.h"
#include <QMessageBox>
#include <QEvent>
Register::Register(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    //setWindowFlags(Qt::WindowStaysOnTopHint);
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
    auto r = new RegisterV(this);
    r->setAttribute(Qt::WA_DeleteOnClose);
    r->show();
}
