#ifndef BASEITEM_H
#define BASEITEM_H

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
class BaseItem : public QWidget
{
    Q_OBJECT
public:
    explicit BaseItem(QString mainTitle, QString iconAddr, QString subTitle,QWidget *parent=nullptr);

//    void Init()
    QLabel *mainLabel;
    QLabel *subLabel;
    QLabel *iconLabel;
    QPixmap *avatar;
    QLabel *addr;

signals:
    void clicked();

public slots:
    void mouseClicked();
    void mouseDoubleClickEvent(QMouseEvent*);

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

private:
    QPoint mousePos;

};

#endif // BASEITEM_H
