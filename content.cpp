#include "content.h"

 Content::Content(QWidget *parent)
      :QFrame(parent)
{
    stack =new QStackedWidget(this);
    stack->setFrameStyle(QFrame::Panel|QFrame::Raised);

    p2pChat =new P2pChat();
    groupChat =new GroupChat();
    stack->addWidget(p2pChat);
    stack->addWidget(groupChat);

    QVBoxLayout *RightLayout =new QVBoxLayout(this);
    RightLayout->setMargin(10);
    RightLayout->setSpacing(6);
    RightLayout->addWidget(stack);

}

Content::~Content()
{

}

