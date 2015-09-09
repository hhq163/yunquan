#include "mainwin.h"
#include <QApplication>
#include <QTextCodec>
#include "common/connection.h"
#include "controller/logindialog.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("AR PL KaitiM GB", 12);
    a.setFont(font);

    //设置APP图标
    QIcon icon;

    icon.addPixmap(QPixmap(":/logo_48.png"));
    icon.addPixmap(QPixmap(":/logo_72.png"));
    icon.addPixmap(QPixmap(":/logo_96.png"));
    QApplication::setWindowIcon(icon);

    Mainwin w;
    LoginDialog dlg;
    if(dlg.exec() == QDialog::Accepted){
        w.show();
        return a.exec();
    }else{
        return 0;
    }

}
