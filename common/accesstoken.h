#ifndef ACCESSTOKEN_H
#define ACCESSTOKEN_H

#include <QObject>

class AccessToken : public QObject
{
    Q_OBJECT
public:
    explicit AccessToken(QObject *parent = 0);
    ~AccessToken();

signals:

public slots:
};

#endif // ACCESSTOKEN_H
