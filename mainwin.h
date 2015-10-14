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

    QSplitter *splitterMain;

public:
    int show();
//    void onEventAsync(QObject *parent = 0);//异步执行请求
};

#endif // MAINWIN_H
