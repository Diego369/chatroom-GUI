#include "registerv.h"
#include "ui_registerv.h"

RegisterV::RegisterV(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::RegisterV)
{
    ui->setupUi(this);
}

RegisterV::~RegisterV()
{
    delete ui;
}
