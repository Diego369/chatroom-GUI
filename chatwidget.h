#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
//#include <QDialog>
#include <QTextDocument>
#include <QTextFrame>
#include <QDateTime>

namespace Ui {
class ChatWidget;
}

class ChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWidget(QWidget *parent = nullptr);
    ~ChatWidget();

    void Init(QString name);

    void scrollBarAdjust();
    void MessageOut(QString msg);
    void MessageIn(QString msg,QDateTime *time=nullptr);
    void setUserName(QString usr);
    void setSender(QString sender);
    void setReceiver(QString receiver);
    void setPlainFormat(QFont target,Qt::GlobalColor color);
    void setSignature(QString sgn);
    void setAvatar(QPixmap &avatar, int length, int width, int radius);
    void setInMsgFormat(QFont target,Qt::GlobalColor color);
    void setOutMsgFormat(QFont target,Qt::GlobalColor color);


    QString getBareJid() const;
    void setBareJid(const QString &value);

    static QMap<QString,ChatWidget *> openedWidgets;
//    static ChatWidget *getChatWidget(QString bareJid, QString username, QString signature, QString receiver, QPixmap avatar);
//    static bool ifChatWidgetExist(QString jid);
//    static void closeChatWidget(ChatWidget *widget);

private:
    Ui::ChatWidget *ui;

    QTextDocument *document;
    QTextFrame *rootFrame;
    QTextBlockFormat inMsgFormat;
    QTextBlockFormat outMsgFormat;
    QTextCharFormat inMsgCharFormat;
    QTextCharFormat outMsgCharFormat;
    QTextCharFormat plainFormat;
    QString sender;
    QString receiver;
    QString timeFormat;
    QPixmap *avatar;
    QTextCursor save;
    int savepos;

    QString bareJid;

//public slots:
//    void windowclosed() override;

signals:
    void newMessage(QString sender,QString receive,QDateTime time,QString content);
private slots:
    void on_pushButton_send_clicked();
};

#endif // CHATWIDGET_H
