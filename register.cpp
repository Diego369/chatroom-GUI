#include "register.h"

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

