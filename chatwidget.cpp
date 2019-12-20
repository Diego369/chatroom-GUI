#include "chatwidget.h"
#include "ui_chatwidget.h"


#include <QScrollBar>

ChatWidget::ChatWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatWidget)
{
    ui->setupUi(this);
    //做一些默认设置，用户调用下面的函数能覆盖掉
    document=ui->textEdit_msg->document();
    rootFrame=document->rootFrame();
    inMsgFormat.setAlignment(Qt::AlignLeft);
    outMsgFormat.setAlignment(Qt::AlignRight);
    inMsgFormat.setTopMargin(5);
    outMsgFormat.setTopMargin(5);
    inMsgCharFormat.setFont(QFont("微软雅黑",9));
    inMsgCharFormat.setForeground(Qt::green);
    outMsgCharFormat.setFont(QFont("微软雅黑",9));
    outMsgCharFormat.setForeground(Qt::blue);
    sender="发送者昵称";
    receiver="接受者昵称";
    timeFormat="yyyy-MM-dd hh:mm:ss";
    plainFormat.setFont(QFont("微软雅黑",10));
    plainFormat.setForeground(Qt::black);

    //设置按钮1，默认是表情按钮
//    QPixmap button1;
//    button1.load(":/images/1.png");
//    button1.scaled(20,20);
//    ui->button1->setPixmap(button1);
//    ui->button1->setScaledContents(true);

    //设置按钮2，图片按钮
//    QPixmap button2;
//    button2.load(":/images/2.png");
//    button2.scaled(20,20);
//    ui->button2->setPixmap(button2);
//    ui->button2->setScaledContents(true);


    save=ui->textEdit_msg->textCursor();
    savepos=ui->textEdit_msg->textCursor().position();
}

ChatWidget::~ChatWidget()
{
    delete ui;
}

void ChatWidget::Init(QString name)
{
    ui->label_name->setText(name);
    ui->textEdit->setText("hello "+name);
}

void ChatWidget::MessageOut(QString msg)
{
    ui->textEdit_msg->moveCursor(QTextCursor::End);
    //插入对外发送消息，格式都一样，下同！
    QTextCursor cursor=ui->textEdit_msg->textCursor();
    ui->textEdit_msg->moveCursor(QTextCursor::End);
    //qDebug()<<savepos<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    //cursor.setPosition(QTextCursor::Start);
    //ui->textEdit_msg->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
    cursor.insertBlock(outMsgFormat);
    ui->textEdit_msg->moveCursor(QTextCursor::End);
    //插入文本块儿
    cursor.setCharFormat(outMsgCharFormat);
    ui->textEdit_msg->moveCursor(QTextCursor::End);
    //设置字符模式
    cursor.insertText(sender);
    cursor.insertText("  ");
    cursor.insertText(QDateTime::currentDateTime().toString(timeFormat));
    cursor.insertText("\n");
    cursor.setCharFormat(plainFormat);
    ui->textEdit_msg->moveCursor(QTextCursor::End);
    cursor.insertText(msg);
    //cursor.insertText("\n");
    save=ui->textEdit_msg->textCursor();
    savepos=ui->textEdit_msg->textCursor().position();
    scrollBarAdjust();
}

void ChatWidget::MessageIn(QString msg,QDateTime *time)
{
    ui->textEdit_msg->moveCursor(QTextCursor::End);
    //插入接受消息，同上
    QTextCursor cursor=ui->textEdit_msg->textCursor();
    //cursor.setPosition(QTextCursor::End);
    //ui->textEdit_msg->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
    cursor.insertBlock(inMsgFormat);
    cursor.setCharFormat(inMsgCharFormat);
    cursor.insertText(receiver);
    cursor.insertText("  ");
    if(time==nullptr)
        //如果没有传入时间，就用系统当前时间
        cursor.insertText(QDateTime::currentDateTime().toString(timeFormat));
    else
        cursor.insertText(time->toString(timeFormat));
    cursor.insertText("\n");
    cursor.setCharFormat(plainFormat);
    cursor.insertText(msg);
    //cursor.insertText("\n");
    scrollBarAdjust();
}

void ChatWidget::scrollBarAdjust()
{
    QScrollBar *scrollBar=ui->textEdit_msg->verticalScrollBar();
    if (scrollBar)
    {
        scrollBar->setSliderPosition(scrollBar->maximum());
    }
}

void ChatWidget::setUserName(QString usr)
{
    //设置用户名，显示在每次发消息的消息标题上
    sender=usr;
    ui->label_name->setText(usr);
}

void ChatWidget::setSignature(QString sgn)
{
    //设置标题上的个性签名
//    ui->signature->setText(sgn);
}

void ChatWidget::setSender(QString sender)
{
    //设置
    this->sender=sender;
}

void ChatWidget::setReceiver(QString receiver)
{
    //设置接受者，显示在接受消息标题上
    this->receiver=receiver;
    ui->label_name->setText(receiver);
}

void ChatWidget::setPlainFormat(QFont target,Qt::GlobalColor color)
{
    //设置消息正文格式
    plainFormat.setFont(target);
    plainFormat.setForeground(color);
}

void ChatWidget::setAvatar(QPixmap &avatar, int length, int width, int radius)
{
//    //设置头像
//    QPixmap pixMap= avatar.scaled(width,length, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
//    //搞成圆形
//    pixMap =  PixmapToRound(pixMap, radius);
//    ui->avaterLabel->setPixmap(pixMap);

}

void ChatWidget::setInMsgFormat(QFont target,Qt::GlobalColor color)
{
    //设置接受消息的格式
    inMsgCharFormat.setFont(target);
    inMsgCharFormat.setForeground(color);
}

void ChatWidget::setOutMsgFormat(QFont target,Qt::GlobalColor color)
{
    //设置发送消息的格式
    outMsgCharFormat.setFont(target);
    outMsgCharFormat.setForeground(color);
}

//void ChatWidget::on_messageReceived(const QXmppMessage &msg)
//{
//    if (QXmppUtils::jidToBareJid(msg.from()) == bareJid) {
//        auto time = msg.stamp();
//        insertInMessage(msg.body(), &time);
//    }
//}

//void ChatWidget::windowclosed()
//{
//    closeChatWidget(this);
//    close();
//}

//QPixmap ChatWidget::PixmapToRound(const QPixmap &src, int radius)
//{
//    //图片变圆的
//    if (src.isNull()) {
//        return QPixmap();
//    }
//    QSize size(2*radius, 2*radius);
//    QBitmap mask(size);
//    QPainter painter(&mask);
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.setRenderHint(QPainter::SmoothPixmapTransform);
//    painter.fillRect(0, 0, size.width(), size.height(), Qt::white);
//    painter.setBrush(QColor(0, 0, 0));
//    painter.drawRoundedRect(0, 0, size.width(), size.height(), 99, 99);
//    QPixmap image = src.scaled(size);
//    image.setMask(mask);
//    return image;
//}

QString ChatWidget::getBareJid() const
{
    return bareJid;
}
void ChatWidget::setBareJid(const QString &value)
{
    bareJid = value;
}

// 获取聊天窗口的指针，如果不存在，则打开一个新的聊天窗口
//ChatWidget *ChatWidget::getChatWidget(QString bareJid,QString username,QString signature,QString receiver,QPixmap avatar)
//{

//    QMap<QString,ChatWidget *>::const_iterator i= openedWidgets.find(bareJid);
//    if(i==openedWidgets.end())
//    {
//        ChatWidget *chat=new ChatWidget();
//        chat->setUserName(username);
//        chat->setBareJid(bareJid);
//        chat->setSignature(signature);
//        chat->setReceiver(receiver);
//        chat->setAvatar(avatar,80,80,45);
//        chat->show();
//        openedWidgets.insert(bareJid,chat);
//        return chat;
//    }
//    else {
//        return i.value();
//    }
//}
//bool ChatWidget::ifChatWidgetExist(QString jid)
//{
//    QMap<QString,ChatWidget *>::const_iterator i= openedWidgets.find(jid);
//    return !(i==openedWidgets.end());

//}

//void ChatWidget::closeChatWidget(ChatWidget *widget)
//{
//    QString jid=openedWidgets.key(widget);
//    QMap<QString,ChatWidget *>::iterator i= openedWidgets.find(jid);
//    openedWidgets.erase(i);
//    //qDebug()<<"             erase!";
//}

void ChatWidget::on_pushButton_send_clicked()
{
    MessageOut(ui->textEdit->toPlainText());
//    emit newMessage(sender,receiver,QDateTime::currentDateTime(),ui->contentBox->toPlainText());
    ui->textEdit->clear();
}
