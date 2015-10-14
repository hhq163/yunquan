#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include "common/common.h"
class HttpResponse : public QObject
{
    Q_OBJECT
public:
    explicit HttpResponse(QObject *parent = 0);
    ~HttpResponse();

signals:

public slots:
public:
    int32 m_errCode;
    QString m_errMsg;
};

#endif // HTTPRESPONSE_H
