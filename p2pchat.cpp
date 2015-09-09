#include "p2pchat.h"

P2pChat::P2pChat(QWidget *parent) : QWidget(parent)
{

    spLeftMain = new QSplitter(Qt::Horizontal, this);
    spLeftMain->setOpaqueResize(false);

    //成员列表
    list =new QListWidget(spLeftMain);
    list->insertItem(0,QObject::tr("用户1"));
    list->insertItem(1,QObject::tr("用户2"));
    list->insertItem(2,QObject::tr("用户3"));


    //右边窗口
    splitterRight =new QSplitter(Qt::Vertical,spLeftMain);
    splitterRight->setOpaqueResize(false);

    //右上窗口
    upList =new QListWidget(splitterRight);
    upList->insertItem(0,QObject::tr("第一条消息"));

    //右下输入框
    textBottom =new QTextEdit(QObject::tr("Bottom Widget"),splitterRight);
    textBottom->resize(300, 50);
    textBottom->setAlignment(Qt::AlignCenter);
    splitterRight->setStretchFactor(1,1);
}

P2pChat::~P2pChat()
{

}

