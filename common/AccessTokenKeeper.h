#ifndef AccessTokenKeeper_H
#define AccessTokenKeeper_H

#include <QObject>
#include <QSettings>

class AccessTokenKeeper : public QObject
{
    Q_OBJECT
public:
    explicit AccessTokenKeeper(QObject *parent = 0);
    ~AccessTokenKeeper();

signals:

public:
    QString ReadClientId();
    int WriteClientId(QString clientId);

    QString ReadClientSecret();
    int WriteClientSecret(QString secret);

    QString ReadAccessToken();
    int WriteAccessToken(QString accessToken);

    QString ReadExpireTime();
    int WriteExpireTime(QString expireTime);
    QString getAuthorization();
private:
    QSettings* settings;

};

extern AccessTokenKeeper accessTokenKeeper;

#endif // AccessTokenKeeper_H
