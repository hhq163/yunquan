#ifndef BASERESPONSE_H
#define BASERESPONSE_H
#include "common/common.h"

class BaseResponse
{
public:
    BaseResponse();
    ~BaseResponse();

public:
    virtual int Parse(QString pBuf);
    virtual QString Pack();
public:
    uint16 m_errCode;
    QString m_errMsg;
};

#endif // BASERESPONSE_H
