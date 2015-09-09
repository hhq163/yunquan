#include "groupchatview.h"
#include "ui_groupchatview.h"

GroupChatView::GroupChatView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GroupChatView)
{
    ui->setupUi(this);
}

GroupChatView::~GroupChatView()
{
    delete ui;
}
