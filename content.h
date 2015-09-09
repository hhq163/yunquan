#ifndef CONTENT_H
#define CONTENT_H

#include <QLayout>
#include <QStackedWidget>
#include <QPushButton>
#include "p2pchat.h"
#include "groupchat.h"

class Content : public QFrame
{
    Q_OBJECT
public:
    Content(QWidget *parent=0);
    ~Content();

    QStackedWidget *stack;
    QPushButton *AmendBtn;
    QPushButton *CloseBtn;

    P2pChat *p2pChat;
    GroupChat *groupChat;

};

#endif // CONTENT_H
