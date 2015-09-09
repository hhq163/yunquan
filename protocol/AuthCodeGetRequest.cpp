#include "AuthCodeGetRequest.h"
#include "common/ProtJsonGetValue.h"

AuthCodeGetRequest::AuthCodeGetRequest()
{
    type = 0;
}

AuthCodeGetRequest::~AuthCodeGetRequest()
{

}
/**
 * 包解析
 * @brief AuthCodeGetRequest::Parse
 */
AuthCodeGetRequest::Parse(QString qstr){
    std::string str = qstr.toStdString();//QString转换为string
    const char* pdata = str.c_str();

    Json::Reader reader;
    Json::Value value;
    if (reader.parse(pdata, value))
    {
        SAFE_GET_JSON_INT_VALUE(type, value, "type", asUInt);
        SAFE_GET_JSON_STR_VALUE(mobile, value, "mobile");
    }
    else
    {
//        Logger.Log(ERROR, "cmd:[0x%04x] m_llSrcUid:%lld m_llDesUid:%lld Json parse  failed",
//        m_wCmd, m_llSrcUid,m_llDesUid);
        return ERR_FAILED;
    }

}

/**
 * 包封装
 * @brief AuthCodeGetRequest::Pack
 */
AuthCodeGetRequest::Pack(){

}
