//#pragma execution_character_set("UTF-8")

#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    Login l;
//    l.show();
//    return a.exec();
    Login w;
    if (w.exec() == QDialog::Accepted) {
        // 登录成功，则转到主窗口
        MainWindow m;
        m.show();
        return a.exec();
    } else {
        return 0;
    }
}
