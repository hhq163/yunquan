#ifndef ACCESSTOKENRESPONSE_H
#define ACCESSTOKENRESPONSE_H

#include <QObject>

class AccessTokenResponse : public QObject
{
    Q_OBJECT
public:
    explicit AccessTokenResponse(QObject *parent = 0);
    ~AccessTokenResponse();

signals:

public slots:
};

#endif // ACCESSTOKENRESPONSE_H
