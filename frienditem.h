#ifndef FRIENDITEM_H
#define FRIENDITEM_H

#include <QWidget>
#include "baseitem.h"
class FriendItem : public BaseItem
{
    Q_OBJECT
public:
    explicit FriendItem(QString mainTitle, QString iconAddr, QString subTitle,QWidget *parent=nullptr);

signals:
    void showWidget(QString str);
public slots:
    void mouseClicked();
    void mouseDoubleClickEvent(QMouseEvent*);


};

#endif // FRIENDITEM_H
