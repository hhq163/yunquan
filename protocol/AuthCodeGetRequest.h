#ifndef AUTHONCODEGET_H
#define AUTHONCODEGET_H
#include "common/common.h"
/**
 *获取验证码
 * @brief The AuthCodeGetRequest class
 */
class AuthCodeGetRequest
{
public:
    QString mobile;
    int type;
public:
    AuthCodeGetRequest();
    ~AuthCodeGetRequest();
public:
    Parse(QString pBuf);
    Pack(QString pBuf);
};

#endif // AUTHONCODEGET_H
