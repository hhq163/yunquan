
#include <QtNetwork>
#include "user.h"
#include "common/common.h"
#include "protocol/AuthCodeGetRequest.h"

User::User()
{
}

User::~User()
{
}
void User::load(AuthCodeGetRequest &authCodeGetRequest, LoginDialog &loginDialog){
    request = QNetworkRequest();
    postData.append("mobile=" + authCodeGetRequest.mobile);
    postData.append("type=" + authCodeGetRequest.type);

    request->setUrl(QUrl(AuthCodeSendUrl));

    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),loginDialog,SLOT(onResponse(QNetworkReply*)));
    manager->post(request, postData);
}

