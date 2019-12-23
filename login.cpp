#include "login.h"
#include "ui_login.h"

#include "register.h"

Login::Login(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->verticalLayout->setContentsMargins(0,0,0,0);
    ui->horizontalLayout->setContentsMargins(0,0,0,0);

    connect(ui->pushButton_login,&QPushButton::clicked,this,&Login::confirm);
    connect(ui->pushButton_register,&QPushButton::clicked,this,&Login::regist);
}

Login::~Login()
{
    delete ui;
}

int Login::exec()
{
    this->show();
    m_eventLoop=new QEventLoop(this);
    m_eventLoop->exec();
    return m_result;
}

void Login::accept()
{
    m_result=QDialog::Accepted;
    this->close();
}

void Login::reject()
{
    m_result=QDialog::Rejected;
    this->close();
}

void Login::loginSucceed()
{

    this->accept();
}

void Login::regist()
{
    auto r = new Register(this);
    r->setAttribute(Qt::WA_DeleteOnClose);
    r->show();
}
void Login::closeEvent(QCloseEvent *event)
{
    if(m_eventLoop != nullptr) {
        m_eventLoop->exit();
    }
    QWidget::closeEvent(event);
}



void Login::confirm()
{
    //todo
    //验证过程

    if(true)
        this->loginSucceed();
}
