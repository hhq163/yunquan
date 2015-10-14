#include <QtNetwork>
#include "protocol/AccessTokenResponse.h"
#include "common/AccessTokenKeeper.h"
#include "AccessTokenRequest.h"

AccessTokenRequest::AccessTokenRequest(QObject *parent)
{

}

AccessTokenRequest::~AccessTokenRequest()
{

}
void AccessTokenRequest::execute(){
//    HttpRequest::execute();

    try{
        prepareAndExecuteRequest();
    }catch(std::runtime_error&e){
        qDebug()<< QDate::currentDate() << "HttpRequest::execute() error";
    }
}
void AccessTokenRequest::prepareAndExecuteRequest(){
//    HttpRequest::prepareAndExecuteRequest();
//    netWorker = NetWorker::instance();
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(onResponse(QNetworkReply*)));

    QString grantType = "client_credentials";
    QString scope = "read write";
    QString clientId = accessTokenKeeper.ReadClientId();
    QString authorization = accessTokenKeeper.getAuthorization();

    QNetworkRequest request;
    QUrl qurl(AccessTokenUrl);
    QUrlQuery tmpQuery;//request参数
    tmpQuery.addQueryItem("grant_type",grantType);
    tmpQuery.addQueryItem("client_id",clientId);
    tmpQuery.addQueryItem("scope",scope);
    qurl.setQuery(tmpQuery);
    request.setUrl(qurl);
    request.setRawHeader("Authorization", authorization.toLocal8Bit());

    manager->get(request);

//    connect(netWorker,&NetWorker::finished,this,SLOT(onResponse(QNetworkReply*)));

//    netWorker->get(request);
}

void AccessTokenRequest::onResponse(QNetworkReply *reply)
{
    QString all = reply->readAll();
    qDebug()<< QDate::currentDate() << "AccessTokenRequest::onResponse (in) 111，all:";
    reply->deleteLater();
    if(reply->error() == QNetworkReply::NoError){
        qDebug()<< QDate::currentDate() << "AccessTokenRequest::onResponse (in) 222，all:";
        qDebug()<< QDate::currentDate() << all;

        AccessTokenResponse* accessTokenResponse = new AccessTokenResponse();
        accessTokenResponse->Parse(all);

        accessTokenKeeper.WriteAccessToken(accessTokenResponse->m_accessToken);
        accessTokenKeeper.WriteExpireTime(accessTokenResponse->m_expireTime);

    }else{
        qDebug()<< QDate::currentDate() << "AccessTokenRequest::onResponse (in) error";
    }
}
