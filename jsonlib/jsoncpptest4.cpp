//  g++ -g -Wall -o test_json test_json.cpp -I/usr/local/jsoncpp/include -L/usr/local/jsoncpp/libs -ljson_linux-gcc-4.1.1_libmt    

#include <string>   
#include <fstream> 
#include <cassert> 

#include "json.h" 
#include "reader.h" 
#include "value.h" 
#include "writer.h" 

typedef char int8;
typedef unsigned char uint8;
typedef short int16;
typedef unsigned short uint16;
typedef int int32;
typedef unsigned int uint32;
typedef long long int64;
typedef unsigned long long uint64;

#ifndef SAFE_GET_USERINFO_INT_VALUE
#define SAFE_GET_USERINFO_INT_VALUE(arg,jvalue,name,func)								\
	do																				\
{																				\
	if( jvalue.isNull() || !jvalue.isMember(name) )										\
	{																			\
		printf( "Parse Err  name[%s] is null", name);				\
		break;																	\
	}																			\
	if(!jvalue[name].isIntegral())														\
	{																			\
		printf( "Parse Err   name[%s] err type[%d]", name, jvalue[name].type());\
		break;																	\
	}																			\
	arg = jvalue[name].func();														\
}while(0)
#endif

#ifndef SAFE_GET_USERINFO_STR_VALUE
#define SAFE_GET_USERINFO_STR_VALUE(arg,jvalue,name)									\
	do																				\
{																				\
	if( jvalue.isNull() || !jvalue.isMember(name) )										\
	{																			\
		printf( "Parse Err   name[%s] is null", name);				\
		break;																	\
	}																			\
	if( !jvalue[name].isString())														\
	{																			\
		printf( "Parse Err   name[%s] err type[%d]", name, jvalue[name].type());\
		break;																	\
	}																			\
	arg = jvalue[name].asString();													\
}while(0)
#endif

#ifndef SAFE_GET_USERINFO_OBJ_VALUE
#define SAFE_GET_USERINFO_OBJ_VALUE(arg,jvalue,name)									\
	do																				\
{																				\
	if( jvalue.isNull() || !jvalue.isMember(name) )										\
	{																			\
		printf( "Parse Err   name[%s] is null", name);				\
		break;																	\
	}																			\
	if( !jvalue[name].isObject())														\
	{																			\
		printf( "Parse Err  name[%s] err type[%d]", name, jvalue[name].type());\
		break;																	\
	}																			\
	arg = jvalue[name];															\
}while(0)
#endif

#ifndef SAFE_GET_JSON_ARRAY_VALUE
#define SAFE_GET_JSON_ARRAY_VALUE(arg,jvalue,name)									\
	do																				\
{																				\
	if( jvalue.isNull() || !jvalue.isMember(name) )										\
	{																			\
		printf( "Parse Err  name[%s] is null\n", name);				\
		break;																	\
	}																			\
	if( !jvalue[name].isArray())														\
	{																			\
		printf( "Parse Err  name[%s] err type[%d]\n", name, jvalue[name].type());\
		break;																	\
	}																			\
	arg = jvalue[name];															\
}while(0)
#endif





using namespace std;  
int main() 
{  
//string str = "{\"srcuid\":10000,\"roomid\":0,\"touid\":0,\"msgtype\":3,\"globlead\":0,\"time\":0,\"msg\":[{\"objtype\":1},[{\"objtype\":2}]]}";
//string str = "{\"srcuid\":10000,\"roomid\":0,\"touid\":0,\"msgtype\":3,\"globlead\":0,\"time\":0,\"msg\":\"hello,chatserver!\"}}";
//string str = "22";
//string str = "{\"globlead\":0,\"msg\":[{\"data\":{\"desc\":null,\"id\":null,\"roomid\":1000648,\"status\":13,\"tips\":\"\",\"type\":3},\"objtype\":9},[]],\"msgtype\":25,\"msgver\":17235969,\"roomid\":1000648,\"srcuid\":52,\"time\":0,\"touid\":46912652712560}";

string str = "{\"globlead\":0,\"msg\":[{\"data\":{\"desc\":null,\"id\":null,\"roomid\":1900051,\"status\":13,\"tips\":\"\",\"type\":3},\"objtype\":9},[{\"data\":{\"flag\":1,\"id\":8,\"name\":\"火箭赢5分以上\",\"odds\":180},\"objtype\":11},{\"data\":{\"flag\":0,\"id\":9,\"name\":\"开拓者输5分以内\",\"odds\":180},\"objtype\":11}]],\"msgtype\":25,\"msgver\":17235969,\"roomid\":1900051,\"srcuid\":3619243069619663978,\"time\":0,\"touid\":7022344801680567421}";

//	Json::Features f = Json::Features::strictMode();
//	Json::Reader reader(f);  
	Json::Reader reader;  
	Json::Value value;  
	Json::FastWriter writer; 
	
	if (reader.parse(str, value)) 
	{
		printf("isNull[%d] empty[%d] type[%d] -%s-\n", value.isNull(), value.empty(), value.type(), value.toStyledString().c_str());
		Json::Value m_jSendMsgArray;
		SAFE_GET_JSON_ARRAY_VALUE(m_jSendMsgArray, value, "msg");
		printf("----------------iisArray[%d] arry size=%d --%s--\n", m_jSendMsgArray.isArray(), m_jSendMsgArray.size(), m_jSendMsgArray.toStyledString().c_str());
		for (uint32 i=0; i<m_jSendMsgArray.size(); i++) 
		{
			printf("start pares %d type[%d]\n", i, m_jSendMsgArray[i].type());
			Json::Value node;
			
			//Json::Value datakey = m_jSendMsgArray[i].get("data", Json::Value::null);	
			
			//printf("isNull[%d] empty[%d] type[%d] \n", datakey.isNull(), datakey.empty(), datakey.type());
				
			SAFE_GET_JSON_ARRAY_VALUE(node, m_jSendMsgArray[i], "data");
		}

	}	
	else
	{
		printf("err json\n");
	}

	return 0;  
}  
