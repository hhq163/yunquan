#ifndef ACCESSTOKENREQUEST_H
#define ACCESSTOKENREQUEST_H

#include <QObject>
#include "http/NetWorker.h"
#include "http/HttpRequest.h"

class AccessTokenRequest : public HttpRequest
{
public:
    explicit AccessTokenRequest(QObject *parent = 0);
    ~AccessTokenRequest();

signals:

public slots:
    virtual void execute();
    virtual void prepareAndExecuteRequest();
    virtual void onResponse(QNetworkReply *reply);
private:
//    NetWorker *netWorker;
};

#endif // ACCESSTOKENREQUEST_H
