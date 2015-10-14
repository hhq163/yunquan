#include "AuthCodeGetResponse.h"
#include "common/ProtJsonGetValue.h"

AuthCodeGetResponse::AuthCodeGetResponse()
{

}

AuthCodeGetResponse::~AuthCodeGetResponse()
{

}

/**
 * 包解析
 * @brief AuthCodeGetResponse::Parse
 */
int AuthCodeGetResponse::Parse(QString qstr){
    qDebug()<< QDate::currentDate() << "AuthCodeGetResponse::Parse in";

    std::string str = qstr.toStdString();//QString转换为string
    const char* pdata = str.c_str();

    int iErr = BaseResponse::Parse(qstr);
    if(ERR_SUCCESS != iErr){
        return iErr;
    }

    Json::Reader reader;
    Json::Value value;
    if (reader.parse(pdata, value))
    {
        SAFE_GET_JSON_INT_VALUE(m_errCode, value, "errcode", asUInt);
        SAFE_GET_JSON_STR_VALUE(m_errMsg, value, "errmsg");
    }
    else
    {
        qDebug()<< QDate::currentDate() << "Json parse  failed！";
        return ERR_FAILED;
    }

    qDebug()<<QDate::currentDate() << "after json prase:" << m_errCode << ":" << m_errMsg;

    return ERR_SUCCESS;
}

/**
 * 包封装
 * @brief AuthCodeGetResponse::Pack
 */
QString AuthCodeGetResponse::Pack(){
    qDebug()<< QDate::currentDate() << "AuthCodeGetResponse::Pack in";

    Json::Value root;
    Json::FastWriter writer;

    root["errcode"]  = m_errCode;
    root["errmsg"] = m_errMsg.toUtf8().constData();

    std::string json_obj = writer.write(root);
    return QString::fromStdString(json_obj);
}
