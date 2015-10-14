#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QtNetwork>
#include <QDialog>
#include "http/NetWorker.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
private slots:
    void on_loginBtn_clicked();


public slots:
    void onResponse(QNetworkReply *);

private:
    Ui::LoginDialog *ui;
    QNetworkReply *reply;

    QNetworkAccessManager* manager;
//    NetWorker *netWorker;

};

#endif // LOGINDIALOG_H
