#ifndef USER_H
#define USER_H
#include "protocol/AuthCodeGetRequest.h"

class QNetworkRequest;
class QNetworkAccessManager;
class LoginDialog;

class User: public QObject
{
    Q_OBJECT
public:
    User(QObject *parent = 0);
    ~User();
    void load(AuthCodeGetRequest &authCodeGetRequest, LoginDialog &loginDialog);

private:
    QNetworkRequest *request;
    QByteArray postData;
    QNetworkAccessManager *manager;


private slots:
//    void replyFinished(QNetworkReply *);

};

#endif // USER_H
