#include "register.h"
#include "ui_register.h"
#include <QMessageBox>
#include <QEvent>
Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowStaysOnTopHint);
}

Register::~Register()
{
    delete ui;
}
