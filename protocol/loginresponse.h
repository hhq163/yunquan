#ifndef LOGINRESPONSE_H
#define LOGINRESPONSE_H
#include "protocol/BaseResponse.h"

class LoginResponse : public BaseResponse
{
public:
    LoginResponse();
    ~LoginResponse();

public:
    virtual int Parse(QString pBuf);
    virtual QString Pack();
public:
    int m_userId;
    QString m_clientId;
    QString m_clientSecret;
};

#endif // LOGINRESPONSE_H
