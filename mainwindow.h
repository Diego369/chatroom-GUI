#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>

#define ItemType_Default 0
#define ItemType_Friend 1
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initNoweStyle();

    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    //好友列表相关
    QMenu *menu;
    QMenu *addMenu;
    void setMenu();
    void setAddMenu();

    QWidget *createItem(QString mainTitle, QString iconAddr, QString subTitle, int type=ItemType_Default);
    QWidget *createRoomItem(QString mainTitle, QString iconAddr);

    QTreeWidgetItem *createFriendGroup(QString grpName);
    QTreeWidgetItem *addFriendtoGroup(QTreeWidgetItem *grp, QString mainTitle, QString subTitle, QString avatarAddr);
    QTreeWidgetItem *removeFriendOrGroup(QTreeWidgetItem *toSet);
    QTreeWidgetItem *addFriendtoGroupAtTop(QTreeWidgetItem *grp, QString mainTitle, QString subTitle, QString avatarAddr);
    QTreeWidgetItem *setFriendToTop(QTreeWidgetItem *toSet, QString mainTitle, QString subTitle, QString avatarAddr, QTreeWidgetItem *grp = nullptr);
    QTreeWidgetItem *createMessage(QString mainTitle, QString subTitle, QString avatarAddr,int index);

    void displayProfilePanel();
    void displayAvatarChangePanel();
    void displayAddPanel();
    void displayCreateRoomPanel();


private slots:
    void on_ChatButton_clicked();

    void on_FriendButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_friend_clicked();

    void on_pushButton_group_clicked();

    void windowclosed();
    void windowmin();

    void on_pushButton_clicked();

    void showWidget(QTreeWidgetItem* item1,int c);
    void setCurrentChatPage(QTreeWidgetItem* item,int c);

private:
    Ui::MainWindow *ui;

    QPoint last;

};

#endif // MAINWINDOW_H
