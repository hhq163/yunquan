#include "AccessTokenResponse.h"

AccessTokenResponse::AccessTokenResponse(QObject *parent) : QObject(parent)
{

}

AccessTokenResponse::~AccessTokenResponse()
{

}

/**
 * 包解析
 * @brief AccessTokenResponse::Parse
 */
int AccessTokenResponse::Parse(QString qstr){
    qDebug()<< QDate::currentDate() << "AccessTokenResponse::Parse in";
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
        SAFE_GET_JSON_INT_VALUE(m_accessToken, value, "access_token", asUInt);
        SAFE_GET_JSON_STR_VALUE(m_expireTime, value, "expires_in");
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
 * @brief AccessTokenResponse::Pack
 */
QString AccessTokenResponse::Pack(){
    qDebug()<< QDate::currentDate() << "AccessTokenResponse::Pack in";

    Json::Value root;
    Json::FastWriter writer;

    root["access_token"] = m_accessToken.toUtf8().constData();
    root["expires_in"] = m_expireTime.toUtf8().constData();

    std::string json_obj = writer.write(root);
    return QString::fromStdString(json_obj);
}
