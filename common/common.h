#ifndef COMMON
#define COMMON

#include <string>
#include <cstring>

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

const string ApiUrl = "http://api.iyunquan.cn";
const string UserLoginUrl = ApiUrl + "/user/register";  //注册
const string UserRegisterUrl = ApiUrl + "/user/login";  //登录

const string AuthCodeSendUrl = ApiUrl + "/user/sendauthcodev25";    //获取短信验证码





#endif // COMMON

