#ifndef AUTHCODEGETRESPONSE_H
#define AUTHCODEGETRESPONSE_H


class AuthCodeGetResponse
{
public:
    AuthCodeGetResponse();
    ~AuthCodeGetResponse();
public:
    Parse(uint8* pBuf);
    Pack(uint8* pBuf);
};

#endif // AUTHCODEGETRESPONSE_H
