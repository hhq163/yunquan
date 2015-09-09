#ifndef P2PCHAT_H
#define P2PCHAT_H

#include <QWidget>
#include<Qsplitter>
#include <QListWidget>
#include<QTextEdit>

class P2pChat : public QWidget
{
    Q_OBJECT
public:
    explicit P2pChat(QWidget *parent = 0);
    ~P2pChat();

public:
     QSplitter *spLeftMain;
     QListWidget *list; //成员列表
     QSplitter *splitterRight;//右边窗口
     QListWidget *upList;//右上窗口
     QTextEdit *textBottom;//右下输入框
};

#endif // P2PCHAT_H
