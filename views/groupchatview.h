#ifndef GROUPCHATVIEW_H
#define GROUPCHATVIEW_H

#include <QWidget>

namespace Ui {
class GroupChatView;
}

class GroupChatView : public QWidget
{
    Q_OBJECT

public:
    explicit GroupChatView(QWidget *parent = 0);
    ~GroupChatView();

private:
    Ui::GroupChatView *ui;
};

#endif // GROUPCHATVIEW_H
