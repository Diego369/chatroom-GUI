#include "baseitem.h"
#include <QDebug>
//#include <QLabel>
#include <QBoxLayout>
BaseItem::BaseItem(QString mainTitle, QString iconAddr, QString subTitle,QWidget *parent) : QWidget(parent)
{
    this->mainLabel=new QLabel(this);
    this->subLabel=new QLabel(this);
    this->iconLabel=new QLabel(this);
    this->avatar=new QPixmap(iconAddr);
    this->addr=new QLabel(iconAddr,this);

    this->addr->hide();

    QPixmap avatarAfter=this->avatar->scaled(50,50,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    //分别代表一个消息条中的用户名、个性签名和头像，addr存头像地址，隐藏起来，发射信号用
    this->mainLabel->setText(mainTitle);
    qDebug()<<"mainLabel:"<<mainTitle;
    this->subLabel->setText(subTitle);
    this->iconLabel->setPixmap(avatarAfter);

    this->mainLabel->setStyleSheet(QString("font:bold 12pt \"微软雅黑\";padding:5pt;"));
    this->subLabel->setStyleSheet(QString(""));
    //其余内容都是设置布局
    QVBoxLayout *vLayout=new QVBoxLayout();
    vLayout->addStretch();
    vLayout->addWidget(this->mainLabel);
    vLayout->addWidget(this->subLabel);
    vLayout->addWidget(this->addr);

    vLayout->addStretch();
    vLayout->setSpacing(5);
    vLayout->setContentsMargins(0,0,0,0);
    vLayout->setMargin(3);

    QHBoxLayout *hLayout=new QHBoxLayout();
    hLayout->addWidget(this->iconLabel);
    hLayout->addLayout(vLayout);
    hLayout->addStretch();
    hLayout->addStretch();
    hLayout->setContentsMargins(0,0,0,0);

    hLayout->setMargin(10);
    this->setLayout(hLayout);

    connect(this, SIGNAL(clicked()), this, SLOT(mouseClicked()));
}
void BaseItem::mouseClicked()
{
    qDebug()<<"clicked";
}
void BaseItem::mouseDoubleClickEvent(QMouseEvent* event)
{
    qDebug("doubleclicked");
}
void BaseItem::mousePressEvent(QMouseEvent *ev)
{
    mousePos = QPoint(ev->x(), ev->y());
}

void BaseItem::mouseReleaseEvent(QMouseEvent *ev)
{
    if(mousePos == QPoint(ev->x(), ev->y())) emit clicked();
}
