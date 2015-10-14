#ifndef AUTHCODEGETRESPONSE_H
#define AUTHCODEGETRESPONSE_H
#include "BaseResponse.h"

class AuthCodeGetResponse:public BaseResponse
{
public:
    AuthCodeGetResponse();
    ~AuthCodeGetResponse();
public:
    virtual int Parse(QString pBuf);
    virtual QString Pack();
};

#endif // AUTHCODEGETRESPONSE_H
