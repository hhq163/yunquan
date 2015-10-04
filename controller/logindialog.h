#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QtNetwork>
#include <QDialog>
#include "model/user.h"

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
//    void on_regBtn_clicked();

public slots:
    void onResponse(QNetworkReply *);
//    void on_quitBtn_clicked();

private:
    Ui::LoginDialog *ui;
    QNetworkReply *reply;

//    QNetworkRequest request;
//    QByteArray postData;
    QNetworkAccessManager *manager;

};

#endif // LOGINDIALOG_H
