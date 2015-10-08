#ifndef COMMON
#define COMMON

#include <string>
#include <cstring>
#include <QtCore/qstring.h>
#include <QDebug>
#include <QDate>

using namespace std;

typedef char int8;
typedef unsigned char uint8;
typedef short int16;
typedef unsigned short uint16;
typedef int int32;
typedef unsigned int uint32;
typedef long long int64;
typedef unsigned long long uint64;

#define MAX_BUFFER_SIZE         1024*128        //128K

//error code
#define ERR_SUCCESS			 0
#define ERR_FAILED			-1
#define ERR_NO_MORE_DATA	-2
#define ERR_NO_MORE_SPACE	-3
#define ERR_PROTOCOL		-4

const QString ApiUrl("http://baidu.com/");//因保密需要，未填写真实的URL
const QString UserRegisterUrl(ApiUrl + "/user/register");  //注册
const QString UserLoginUrl(ApiUrl + "/user/login");  //登录
const QString AuthCodeSendUrl(ApiUrl + "/user/sendauthcodev25");    //获取短信验证码




#endif // COMMON

