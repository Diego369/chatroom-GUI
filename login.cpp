#include "login.h"
#include "ui_login.h"

#include "mainwindow.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->verticalLayout->setContentsMargins(0,0,0,0);
    ui->horizontalLayout->setContentsMargins(0,0,0,0);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_login_clicked()
{
    switch(confirm())
    {
    case 0:
        close();
        MainWindow *w=new MainWindow();
        w->show();
        break;
    }
}

int Login::confirm()
{
    return 0;
}

void Login::on_pushButton_register_clicked()
{
    if(r==nullptr)
    {
        r=new Register();
        r->show();
    }
}
