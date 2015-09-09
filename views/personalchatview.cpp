#include "personalchatview.h"
#include "ui_personalchatview.h"

personalchatview::personalchatview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::personalchatview)
{
    ui->setupUi(this);
}

personalchatview::~personalchatview()
{
    delete ui;
}
