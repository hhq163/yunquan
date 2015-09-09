#include "mainwin.h"
#include "content.h"

Mainwin::Mainwin(QWidget *parent) :QMainWindow(parent)
{

    //主窗口
    QSplitter *splitterMain = new QSplitter(Qt::Horizontal, 0);
    splitterMain->setMinimumSize(1000, 600);
    splitterMain->setOpaqueResize(true);
    QListWidget *list =new QListWidget(splitterMain);
    list->setMaximumWidth(150);
    list->insertItem(0,QObject::tr("单聊"));
    list->insertItem(1,QObject::tr("群聊"));
    list->insertItem(2,QObject::tr("我的好友"));
    list->insertItem(3,QObject::tr("设置"));


    Content *content =new Content(splitterMain);
    QObject::connect(list,SIGNAL(currentRowChanged(int)),content->stack,SLOT(setCurrentIndex(int)));

    splitterMain->setWindowTitle(QObject::tr("大咖荟测试程序"));
    splitterMain->setMinimumSize(splitterMain->minimumSize());
    splitterMain->setMaximumSize(splitterMain->maximumSize());
//    splitterMain->show();

}

Mainwin::~Mainwin()
{

}

