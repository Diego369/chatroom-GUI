#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QDialog>
#include <QEventLoop>
#include "register.h"
#include "basewidget.h"
namespace Ui {
class Login;
}

class Login : public BaseWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

public slots:
    int exec();
    void accept();
    void reject();
    void loginSucceed();
    void regist();
    void confirm();
protected:
    void closeEvent(QCloseEvent *event);


private:
    Ui::Login *ui;

    //Register *r;
    QEventLoop *m_eventLoop;
    int m_result = QDialog::Rejected;

};

#endif // LOGIN_H
