#include "common/common.h"
#include "common/AccessTokenKeeper.h"
#include "http/AccessTokenRequest.h"
#include "HttpRequest.h"

HttpRequest::HttpRequest(QObject *parent) : QObject(parent)
{

}
HttpRequest::~HttpRequest()
{

}

void HttpRequest::execute(){
    QString clientId = accessTokenKeeper.ReadClientId();
    QString authorization =accessTokenKeeper.getAuthorization();
    if(!clientId.isEmpty() && !authorization.isEmpty()){
        AccessTokenRequest* accessTokenRequest = new AccessTokenRequest();
        accessTokenRequest->execute();
        return ;
    }

//    try{
//        prepareAndExecuteRequest();
//    }catch(std::runtime_error&e){
//        qDebug()<< QDate::currentDate() << "HttpRequest::execute() error";
//    }

}

void HttpRequest::prepareAndExecuteRequest(){

}

void HttpRequest::onResponse(QNetworkReply *reply){
    qDebug()<< QDate::currentDate() << "HttpRequest::onResponse (in) 111，all:";
}
