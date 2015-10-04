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

#define API_URL = "http://api.iyunquan.cn"
//注册
#define  USER_LOGIN_URL "http://api.iyunquan.cn/user/register"
//登录
#define  USER_REGISTER_URL "http://api.iyunquan.cn/user/login"
//获取短信验证码
#define  AUTH_CODE_SEND_URL "http://api.iyunquan.cn/user/sendauthcodev25"




#endif // COMMON

