#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    //this->setGeometry(QRect(950, 55, 350, 250));//可设置窗口显示的方位与大小

    //this->setWindowOpacity(0.7);//设置透明1-全体透明
    //this->setAttribute(Qt::WA_TranslucentBackground, true);//设置透明2-窗体标题栏不透明,背景透明
    //this->resize(300,300);//显示大小

    ui->widget_friend1->Init("Jay Chou");
    ui->widget_friend2->Init("Ten");

    ui->verticalLayout->setSpacing(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ChatButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_FriendButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->ChatSpace->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->ChatSpace->setCurrentIndex(1);
}
