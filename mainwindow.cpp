#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QToolButton>
#include <QMouseEvent>
#include <QStyle>
#include <QLabel>
#include <QDebug>
#include <QTreeWidgetItem>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

    connect(closeButton, &QToolButton::clicked, this, &MainWindow::windowclosed);
    connect(minButton, &QToolButton::clicked, this, &MainWindow::windowmin);

    //this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    //this->setGeometry(QRect(950, 55, 350, 250));//可设置窗口显示的方位与大小

    //this->setWindowOpacity(0.7);//设置透明1-全体透明
    //this->setAttribute(Qt::WA_TranslucentBackground, true);//设置透明2-窗体标题栏不透明,背景透明
    //this->resize(300,300);//显示大小

    ui->widget_friend1->Init("Jay Chou");
    ui->widget_friend2->Init("Ten");

//    QStringList header;
//    header<<"friend";
    ui->treeWidget_friend->setHeaderLabel("friend");
    ui->treeWidget_friend->setHeaderHidden(true);
    ui->treeWidget_friend->setRootIsDecorated(false);
    ui->treeWidget_friend->setColumnHidden(1,true);
    qDebug()<<"connext";
    connect(ui->treeWidget_friend,SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)),this,SLOT(showWidget(QTreeWidgetItem*,int)));
    ui->treeWidget_group->setHeaderLabel("group");
    ui->treeWidget_group->setHeaderHidden(true);
    ui->treeWidget_group->setRootIsDecorated(false);
    ui->treeWidget_group->setColumnHidden(1,true);
    //ui->verticalLayout->setSpacing(0);

    ui->treeWidget_message->setHeaderLabel("message");
    ui->treeWidget_message->setHeaderHidden(true);
    ui->treeWidget_message->setColumnHidden(1,true);


    //************** test ******************
    auto abc=createFriendGroup("abc");
    createFriendGroup("qwe");
    addFriendtoGroup(abc,"roo","hello",":/pic/test4.png");
    createMessage("roo","hello",":/pic/test4.png");

//    auto mylist=ui->treeWidget_friend->findItems("dady",Qt::MatchExactly);
//    auto mylist=ui->treeWidget_friend->findItems("dady",Qt::MatchContains | Qt::MatchRecursive);

//    if(mylist.isEmpty())
//    {
//        qDebug()<<"em";
//    }
//    else
//    {
//        qDebug()<<"not em";
//        foreach(QTreeWidgetItem* item, mylist)
//        {
//            qDebug() << item->text(0);
//        }
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 鼠标拖动移动窗口位置
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    last=e->globalPos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

void MainWindow::windowclosed()
{
//    client->disconnectFromServer();
    this->close();
    QApplication::exit();
}

void MainWindow::windowmin()
{
    this->showMinimized();
}


void MainWindow::on_ChatButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_FriendButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_pushButton_2_clicked()
{
    ui->ChatSpace->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->ChatSpace->setCurrentIndex(1);
}

void MainWindow::on_pushButton_friend_clicked()
{
    ui->stackedWidget_list->setCurrentIndex(0);
}

void MainWindow::on_pushButton_group_clicked()
{
    ui->stackedWidget_list->setCurrentIndex(1);
}


//好友列表相关
void MainWindow::setMenu()
{
    //设置左下角弹出菜单的
    menu=new QMenu(this);
    QAction *setProfile=new QAction("设置个人资料",this);
    //QAction *setAvatar=new QAction("设置头像",this);
    //把建立的动作添加到菜单
    menu->addAction(setProfile);
    menu->addSeparator();
    //menu->addAction(setAvatar);

    connect(setProfile,&QAction::triggered,this,&MainWindow::displayProfilePanel);
    //connect(setAvatar,&QAction::triggered,this,&MainWindow::displayAvatarChangePanel);

    //设置右下角弹出菜单
    addMenu=new QMenu(this);
    QAction *addFriendOrRoom=new QAction("添加好友或群里",this);
    //QAction *setAvatar=new QAction("设置头像",this);
    //把建立的动作添加到菜单
    addMenu->addAction(addFriendOrRoom);
    addMenu->addSeparator();
    //menu->addAction(setAvatar);

    connect(addFriendOrRoom,&QAction::triggered,this,&MainWindow::displayProfilePanel);
    //connect(setAvatar,&QAction::triggered,this,&MainWindow::displayAvatarChangePanel);

}

void MainWindow::setAddMenu()
{
    //设置右下角弹出菜单
    addMenu=new QMenu(this);
    QAction *addFriendOrRoom=new QAction("添加好友或群组",this);
    QAction *createRoom=new QAction("创建群组",this);
    //把建立的动作添加到菜单
    addMenu->addAction(addFriendOrRoom);
    addMenu->addAction(createRoom);
    addMenu->addSeparator();
    //menu->addAction(setAvatar);

    connect(addFriendOrRoom,&QAction::triggered,this,&MainWindow::displayAddPanel);
    connect(createRoom,&QAction::triggered,this,&MainWindow::displayCreateRoomPanel);

}
void MainWindow::displayProfilePanel()
{
    //显示个人资料窗口
//    DataFrame* d=new DataFrame;

//    d->show();
}
void MainWindow::displayAvatarChangePanel()
{
    //显示头像
//    ChangeHeaderWnd* d=new ChangeHeaderWnd;
//    d->show();
}
//显示添加好友和群组面板
void MainWindow::displayAddPanel()
{
//    AddNewFriend *dialog=new AddNewFriend(client,this);
//    dialog->show();
//    dialog->setWindowModality(Qt::ApplicationModal);
//    updateAllFriends();
}

//显示创建群组面板
void MainWindow::displayCreateRoomPanel()
{
//    CreateRoom *dialog=new CreateRoom(this);
//    dialog->show();
//    dialog->setWindowModality(Qt::ApplicationModal);
//    //updateAllFriends();
}
QWidget *MainWindow::createItem(QString mainTitle, QString iconAddr, QString subTitle, int type)
{
    //本函数用于向一个已经存在的表项里添加控件
    QWidget *myItem=new QWidget(this);
//    QWidget *myItem;
//    switch (type) {
//    case 1:
//        myItem=new FriendItem(mainTitle, iconAddr, subTitle,this);
//        connect(myItem, SIGNAL(showWidget(QString)), this, SLOT(showWidget(QString)));
//        break;
//    default:
//        myItem=new FriendItem(mainTitle,iconAddr,subTitle,this);
//        connect(myItem, SIGNAL(showWidget(QString)), this, SLOT(showWidget(QString)));
//    }
//    QWidget *myItem=new FriendItem(this);

    QLabel *mainLabel=new QLabel(this);
    QLabel *subLabel=new QLabel(this);
    QLabel *iconLabel=new QLabel(this);
    QPixmap *avatar=new QPixmap(iconAddr);
    QLabel *addr=new QLabel(iconAddr,this);

    addr->hide();

    QPixmap avatarAfter=avatar->scaled(50,50,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    //分别代表一个消息条中的用户名、个性签名和头像，addr存头像地址，隐藏起来，发射信号用
    mainLabel->setText(mainTitle);
    subLabel->setText(subTitle);
    iconLabel->setPixmap(avatarAfter);

    mainLabel->setStyleSheet(QString("font:bold 12pt \"微软雅黑\";padding:5pt;"));
    subLabel->setStyleSheet(QString(""));
    //其余内容都是设置布局
    QVBoxLayout *vLayout=new QVBoxLayout();
    vLayout->addStretch();
    vLayout->addWidget(mainLabel);
    vLayout->addWidget(subLabel);
    vLayout->addWidget(addr);

    vLayout->addStretch();
    vLayout->setSpacing(5);
    vLayout->setContentsMargins(0,0,0,0);
    vLayout->setMargin(3);

    QHBoxLayout *hLayout=new QHBoxLayout();
    hLayout->addWidget(iconLabel);
    hLayout->addLayout(vLayout);
    hLayout->addStretch();
    hLayout->addStretch();
    hLayout->setContentsMargins(0,0,0,0);

    hLayout->setMargin(10);
    myItem->setLayout(hLayout);

    return myItem;
}

void MainWindow::showWidget(QTreeWidgetItem* item1,int c)
{
    qDebug()<<"showw";
    //从列表移除分组或好友
    QTreeWidgetItem *parent=item1->parent();
//    int index;
    if(parent)
    {
        //如果不是一级列表！从父对象中删
//        index=parent->indexOfChild(toSet);
//        parent->removeChild(toSet);
        qDebug()<<"child";
            auto mylist=ui->treeWidget_message->findItems(item1->text(1),Qt::MatchContains | Qt::MatchRecursive,1);
            qDebug()<<"text1:"<<item1->text(1);

            if(mylist.isEmpty())
            {
                qDebug()<<"empty";
            }
            else
            {
                qDebug()<<"not empty";
                foreach(QTreeWidgetItem* item, mylist)
                {
                    qDebug() << item->text(0);
                }
            }
        //ui->treeWidget_friend->removeItemWidget(parent->takeChild(index),0);
    }
    else {
        //是一级列表，从根节点下删
//        index=ui->treeWidget_friend->indexOfTopLevelItem(toSet);
//        qDebug()<<parent<<"   "<<index;
//        ui->treeWidget_friend->takeTopLevelItem(index);
        qDebug()<<"root";
    }
//    return toSet;
}

//新建一个好友分组
QTreeWidgetItem *MainWindow::createFriendGroup(QString grpName)
{
    QTreeWidgetItem *item=new QTreeWidgetItem;
    item->setText(0,grpName);
    //添加到列表的顶层
    ui->treeWidget_friend->addTopLevelItem(item);
    return item;
}
QTreeWidgetItem *MainWindow::addFriendtoGroup(QTreeWidgetItem *grp,QString mainTitle,QString subTitle,QString avatarAddr)
{
    //向一个分组里添加一个好友，也就是向二级表项里插入一个三级表项
    QTreeWidgetItem *item11=new QTreeWidgetItem(grp);
    item11->setText(1,mainTitle);
    ui->treeWidget_friend->setItemWidget(item11,0,createItem(mainTitle,avatarAddr,subTitle,ItemType_Friend));
    return item11;
}
QTreeWidgetItem *MainWindow::removeFriendOrGroup(QTreeWidgetItem *toSet)
{
    //从列表移除分组或好友
    QTreeWidgetItem *parent=toSet->parent();
    int index;
    if(parent)
    {
        //如果不是一级列表！从父对象中删
        index=parent->indexOfChild(toSet);
        parent->removeChild(toSet);
        //ui->treeWidget_friend->removeItemWidget(parent->takeChild(index),0);
    }
    else {
        //是一级列表，从根节点下删
        index=ui->treeWidget_friend->indexOfTopLevelItem(toSet);
        qDebug()<<parent<<"   "<<index;
        ui->treeWidget_friend->takeTopLevelItem(index);
    }
    return toSet;
}
QTreeWidgetItem *MainWindow::addFriendtoGroupAtTop(QTreeWidgetItem *grp,QString mainTitle,QString subTitle,QString avatarAddr)
{
    //和上面函数功能一样，但是上面是在末尾插，这个在顶部插
    QTreeWidgetItem *item11=new QTreeWidgetItem(grp,nullptr);
    QWidget *now=createItem(mainTitle,avatarAddr,subTitle);
    ui->treeWidget_friend->setItemWidget(item11,0,now);

    return item11;
}
QTreeWidgetItem *MainWindow::setFriendToTop(QTreeWidgetItem *toSet,QString mainTitle,QString subTitle,QString avatarAddr,QTreeWidgetItem *grp)
{
    //把某个好友放到顶部去，就是删了再加
    if(grp==nullptr)
        grp=toSet->parent();
    removeFriendOrGroup(toSet);
    return addFriendtoGroupAtTop(grp,mainTitle,subTitle,avatarAddr);
}

//创建群组面板里的控件
QWidget *MainWindow::createRoomItem(QString mainTitle, QString iconAddr)
{
    //本函数用于向一个已经存在的表项里添加控件
    QWidget *myItem=new QWidget(this);
    QLabel *mainLabel=new QLabel(this);
    QLabel *iconLabel=new QLabel(this);
    QPixmap *avatar=new QPixmap(iconAddr);
    QLabel *addr=new QLabel(iconAddr,this);
    addr->hide();
    QPixmap avatarAfter=avatar->scaled(50,50,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    //分别代表群组名称和头像，addr存头像地址，隐藏起来，发射信号用
    mainLabel->setText(mainTitle);
    iconLabel->setPixmap(avatarAfter);

    mainLabel->setStyleSheet(QString("font:bold 12pt \"微软雅黑\";padding:5pt;"));
    //其余内容都是设置布局
    QVBoxLayout *vLayout=new QVBoxLayout();
    vLayout->addStretch();
    vLayout->addWidget(mainLabel);
    vLayout->addWidget(addr);
    vLayout->addStretch();
    vLayout->setSpacing(5);
    vLayout->setContentsMargins(0,0,0,0);
    vLayout->setMargin(3);

    QHBoxLayout *hLayout=new QHBoxLayout();
    hLayout->addWidget(iconLabel);
    hLayout->addLayout(vLayout);
    hLayout->addStretch();
    hLayout->setContentsMargins(0,0,0,0);
    hLayout->setMargin(10);

    myItem->setLayout(hLayout);


    return myItem;
}
//在消息面板添加一个消息
QTreeWidgetItem *MainWindow::createMessage(QString mainTitle,QString subTitle,QString avatarAddr)
{
    //先添加一个表项到消息列表
    QTreeWidgetItem *item1=new QTreeWidgetItem;
    ui->treeWidget_message->addTopLevelItem(item1);
    item1->setText(1,mainTitle);
    qDebug()<<"msgtext1:"<<item1->text(1);
    //再把这个表项里的控件插入进去，下面都是这样
    ui->treeWidget_message->setItemWidget(item1,0,createItem(mainTitle,avatarAddr,subTitle));
    return item1;
}
