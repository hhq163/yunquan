#ifndef USER_H
#define USER_H
#include "controller/logindialog.h"

class QNetworkReply;
class QNetworkAccessManager;

class User
{
public:
    User();
    ~User();
    void load(AuthonCodeGet &authonCodeGet, LoginDialog &loginDialog);

private:
    QNetworkRequest *request;
    QByteArray postData;
    QNetworkAccessManager *manager;


private slots:
//    void replyFinished(QNetworkReply *);

};

#endif // USER_H
