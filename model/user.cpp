
#include <QtNetwork>
#include "user.h"
#include "common/common.h"
#include "controller/logindialog.h"

User::User(QObject *parent) : QObject(parent)
{
}

User::~User()
{
}
void User::load(AuthCodeGetRequest &authCodeGetRequest, LoginDialog &loginDialog){
//    request = new QNetworkRequest();
//    postData.append("mobile=" + authCodeGetRequest.m_mobile);
//    postData.append("type=" + authCodeGetRequest.m_type);

//    request->setUrl(QUrl(AUTH_CODE_SEND_URL));

//    manager = new QNetworkAccessManager(this);
//    connect(manager,SIGNAL(finished(QNetworkReply*)),loginDialog,SLOT(onResponse(QNetworkReply*)));
//    manager->post(request, postData);
}

