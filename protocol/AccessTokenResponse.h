#ifndef ACCESSTOKENRESPONSE_H
#define ACCESSTOKENRESPONSE_H

#include <QObject>

class AccessTokenResponse : public QObject
{
    Q_OBJECT
public:
    explicit AccessTokenResponse(QObject *parent = 0);
    ~AccessTokenResponse();
public:
    virtual int Parse(QString pBuf);
    virtual QString Pack();
signals:

public slots:
    QString m_accessToken;
    QString m_expireTime;
};

#endif // ACCESSTOKENRESPONSE_H
