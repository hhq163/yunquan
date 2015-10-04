#include "BaseResponse.h"
#include "common/ProtJsonGetValue.h"

BaseResponse::BaseResponse():m_errCode(0)
{
}

BaseResponse::~BaseResponse()
{
}

/**
 * 包解析
 * @brief BaseResponse::Parse
 */
int BaseResponse::Parse(QString qstr){
    std::string str = qstr.toStdString();//QString转换为string
    const char* pdata = str.c_str();

    Json::Reader reader;
    Json::Value value;
    if (reader.parse(pdata, value))
    {
        SAFE_GET_JSON_INT_VALUE(m_errCode, value, "errcode", asUInt);
        SAFE_GET_JSON_STR_VALUE(m_errMsg, value, "errmsg");
    }
    else
    {
        QMessageLogger().debug()<<"Json parse  failed！";
        return ERR_FAILED;
    }
    return ERR_SUCCESS;
}

/**
 * 包封装
 * @brief BaseResponse::Pack
 */
QString BaseResponse::Pack(){
    Json::Value root;
    Json::FastWriter writer;

    root["errcode"]  = m_errCode;
    root["errmsg"] = m_errMsg.toUtf8().constData();

    std::string json_obj = writer.write(root);
    return QString::fromStdString(json_obj);
}
