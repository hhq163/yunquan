#include "LoginResponse.h"
#include "common/ProtJsonGetValue.h"

LoginResponse::LoginResponse()
{
}

LoginResponse::~LoginResponse()
{

}

/**
 * 包解析
 * @brief LoginResponse::Parse
 */
int LoginResponse::Parse(QString qstr){
    qDebug()<< QDate::currentDate() << "LoginResponse::Parse in";
    qDebug()<< QDate::currentDate() << qstr;

    int iErr = BaseResponse::Parse(qstr);
    if(ERR_SUCCESS != iErr){
        return iErr;
    }

    std::string str = qstr.toStdString();//QString转换为string
    const char* pdata = str.c_str();

    Json::Reader reader;
    Json::Value value;
    if (reader.parse(pdata, value))
    {
        SAFE_GET_JSON_INT_VALUE(m_userId, value, "userId", asUInt);
        SAFE_GET_JSON_STR_VALUE(m_clientId, value, "clientId");
        SAFE_GET_JSON_STR_VALUE(m_clientSecret, value, "clientSecret");
        //其它信息暂不解析
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
 * @brief LoginResponse::Pack
 */
QString LoginResponse::Pack(){
    qDebug()<< QDate::currentDate() << "LoginResponse::Pack in";

    Json::Value root;
    Json::FastWriter writer;

    root["userId"]  = m_userId;
    root["clientId"] = m_clientId.toUtf8().constData();
    root["clientSecret"] = m_clientSecret.toUtf8().constData();

    std::string json_obj = writer.write(root);
    return QString::fromStdString(json_obj);
}
