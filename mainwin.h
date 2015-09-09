#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include "p2pchat.h"
#include "groupchat.h"

class Mainwin : public QMainWindow
{
    Q_OBJECT
public:
   explicit Mainwin(QWidget *parent=0);
    ~Mainwin();

    QStackedWidget *stack;
    QPushButton *AmendBtn;
    QPushButton *CloseBtn;

    P2pChat *p2pChat;
    GroupChat *groupChat;

};

#endif // MAINWIN_H
