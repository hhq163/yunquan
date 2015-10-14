#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <QObject>
#include <QtNetwork>
#include "HttpResponse.h"

class HttpRequest : public QObject
{
    Q_OBJECT
public:
    explicit HttpRequest(QObject *parent = 0);
    ~HttpRequest();

signals:

public slots:
    virtual void execute();
    virtual void prepareAndExecuteRequest();
    virtual void onResponse(QNetworkReply *reply);
};

#endif // HTTPREQUEST_H
