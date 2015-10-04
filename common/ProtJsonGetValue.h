/*
ProtJsonGetValue.h

*/
#ifndef _PROT_JSON_GET_VALUE_H_
#define _PROT_JSON_GET_VALUE_H_


#include "../jsonlib/json.h" 
#include "../jsonlib/reader.h" 
#include "../jsonlib/value.h" 
#include "../jsonlib/writer.h" 

//#include "Log.h"

//////////////////////////////////////////////////////////////////////////
//internal protocol


#define CHECK_IF_NULL(p)                                                        \
do                                                                              \
{                                                                               \
    if ( NULL == p )                                                            \
    {                                                                           \
        sleep(1);                                                               \
        exit(0);                                                                \
    }                                                                           \
}while(0);

//Base Class

#ifndef SAFE_GET_JSON_INT_VALUE
#define SAFE_GET_JSON_INT_VALUE(arg, jvalue, name, func)                        \
do                                                                              \
{                                                                               \
    if ( jvalue.isNull() || !jvalue.isMember(name) )                            \
    {                                                                           \
        break;                                                                  \
    }                                                                           \
    if (!jvalue[name].isIntegral())                                             \
    {                                                                           \
        break;                                                                  \
    }                                                                           \
    arg = jvalue[name].func();                                                  \
}while(0)
#endif

#ifndef SAFE_GET_JSON_STR_VALUE
#define SAFE_GET_JSON_STR_VALUE(arg, jvalue, name)                              \
do                                                                              \
{                                                                               \
    if ( jvalue.isNull() || !jvalue.isMember(name) )                            \
    {                                                                           \
        break;                                                                  \
    }                                                                           \
    if ( !jvalue[name].isString())                                              \
    {                                                                           \
        break;                                                                  \
    }                                                                           \
    arg = QString::fromStdString(jvalue[name].asString());                                              \
}while(0)
#endif

#ifndef SAFE_GET_JSON_OBJ_VALUE
#define SAFE_GET_JSON_OBJ_VALUE(arg, jvalue, name)                              \
do                                                                              \
{                                                                               \
    if ( jvalue.isNull() || !jvalue.isMember(name) )                            \
    {                                                                           \
        break;                                                                  \
    }                                                                           \
    if ( !jvalue[name].isObject())                                              \
    {                                                                           \
        break;                                                                  \
    }                                                                           \
    arg = jvalue[name];                                                         \
}while (0)
#endif

#ifndef SAFE_GET_JSON_ARRAY_VALUE
#define SAFE_GET_JSON_ARRAY_VALUE(arg, jvalue, name)                            \
do                                                                              \
{                                                                               \
    if ( jvalue.isNull() || !jvalue.isMember(name) )                            \
    {                                                                           \
        break;                                                                  \
    }                                                                           \
    if ( !jvalue[name].isArray())                                               \
    {                                                                           \
        break;                                                                  \
    }                                                                           \
    arg = jvalue[name];                                                         \
}while (0)
#endif


#endif

