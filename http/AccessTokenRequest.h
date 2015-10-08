#ifndef ACCESSTOKENREQUEST_H
#define ACCESSTOKENREQUEST_H

#include <QObject>

class AccessTokenRequest : public QObject
{
    Q_OBJECT
public:
    explicit AccessTokenRequest(QObject *parent = 0);
    ~AccessTokenRequest();

signals:

public slots:
};

#endif // ACCESSTOKENREQUEST_H
