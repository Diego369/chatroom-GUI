#include "basewidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QToolButton>
#include <QMouseEvent>
#include <QStyle>

BaseWidget::BaseWidget(QWidget *parent) : QWidget(parent) {
    setWindowFlags(Qt::FramelessWindowHint|Qt::Window);

    // 居中显示
    QDesktopWidget *deskdop=QApplication::desktop();
    move((deskdop->width()-this->width())/2, (deskdop->height()-this->height())/2);

    QToolButton *minButton = new QToolButton(this);
    QToolButton *closeButton= new QToolButton(this);


    //获取最小化、关闭按钮图标
    QPixmap minPix= style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);


    //设置最小化、关闭按钮图标
    minButton->setIcon(minPix);
    closeButton->setIcon(closePix);

    //设置最小化、关闭按钮在界面的位置
    minButton->setGeometry(this->width()-46,5,20,20);
    closeButton->setGeometry(this->width()-25,5,20,20);


    //设置鼠标移至按钮上的提示信息
    minButton->setToolTip(tr("最小化"));
    closeButton->setToolTip(tr("关闭"));

    //设置最小化、关闭按钮的样式
    minButton->setStyleSheet("background:none;border:none");
    closeButton->setStyleSheet("background:none;border:none");

    connect(closeButton, &QToolButton::clicked, this, &BaseWidget::windowclosed);
    connect(minButton, &QToolButton::clicked, this, &BaseWidget::windowmin);
}

//void BaseWidget::initNoweStyle()
//{
//    setWindowFlags(Qt::FramelessWindowHint|Qt::Window);

//    // 居中显示
//    QDesktopWidget *deskdop=QApplication::desktop();
//    move((deskdop->width()-this->width())/2, (deskdop->height()-this->height())/2);

//    QToolButton *minButton = new QToolButton(this);
//    QToolButton *closeButton= new QToolButton(this);


//    //获取最小化、关闭按钮图标
//    QPixmap minPix= style()->standardPixmap(QStyle::SP_TitleBarMinButton);
//    QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);


//    //设置最小化、关闭按钮图标
//    minButton->setIcon(minPix);
//    closeButton->setIcon(closePix);

//    //设置最小化、关闭按钮在界面的位置
//    minButton->setGeometry(this->width()-46,5,20,20);
//    closeButton->setGeometry(this->width()-25,5,20,20);


//    //设置鼠标移至按钮上的提示信息
//    minButton->setToolTip(tr("最小化"));
//    closeButton->setToolTip(tr("关闭"));

//    //设置最小化、关闭按钮的样式
//    minButton->setStyleSheet("background:none;border:none");
//    closeButton->setStyleSheet("background:none;border:none");

//    connect(closeButton, &QToolButton::clicked, this, &BaseWidget::windowclosed);
//    connect(minButton, &QToolButton::clicked, this, &BaseWidget::windowmin);
//}

// 鼠标拖动移动窗口位置
void BaseWidget::mousePressEvent(QMouseEvent *e)
{
    last=e->globalPos();
}

void BaseWidget::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}

void BaseWidget::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

void BaseWidget::windowclosed()
{
    this->close();
}

void BaseWidget::windowmin()
{
    this->showMinimized();
}
