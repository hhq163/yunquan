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
    QString m_mobile;
    int m_type;
public:
    AuthCodeGetRequest();
    ~AuthCodeGetRequest();
public:
    int Parse(QString pBuf);
    QString Pack();
};

#endif // AUTHONCODEGET_H
