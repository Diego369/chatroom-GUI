#include "frienditem.h"
#include <QLabel>
#include <QBoxLayout>
#include <QDebug>
FriendItem::FriendItem(QString mainTitle, QString iconAddr, QString subTitle,QWidget *parent):
    BaseItem(mainTitle, iconAddr, subTitle,parent)
{
}

void FriendItem::mouseClicked()
{
    qDebug()<<"clicked";
    qDebug()<<"infi:"<<mainLabel->text();
}
void FriendItem::mouseDoubleClickEvent(QMouseEvent* event)
{
    qDebug("doubleclicked");
    emit showWidget(this->mainLabel->text());
}
