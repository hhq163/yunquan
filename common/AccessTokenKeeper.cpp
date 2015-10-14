#include <QCoreApplication>
#include "common/common.h"
#include "AccessTokenKeeper.h"

AccessTokenKeeper accessTokenKeeper;

AccessTokenKeeper::AccessTokenKeeper(QObject *parent) : QObject(parent)
{
//    QSettings settings("yunlai", "yunquan");
    QCoreApplication::setOrganizationName("yunlai");
    QCoreApplication::setApplicationName("yunquan");

    QString m_sSettingsFile = "settings.ini";
    qDebug()<< QDate::currentDate() << "m_sSettingsFile:" + m_sSettingsFile;

    settings = new QSettings(m_sSettingsFile,QSettings::IniFormat);

}

AccessTokenKeeper::~AccessTokenKeeper()
{
    delete settings;
}

QString AccessTokenKeeper::ReadClientId(){
    qDebug()<< QDate::currentDate() << "AccessTokenKeeper::ReadClientId (in) 111";
    return settings->value("clientId").toString();
}

int AccessTokenKeeper::WriteClientId(QString clientId){
    qDebug()<< QDate::currentDate() << "AccessTokenKeeper::WriteClientId (in) 111";
    settings->setValue("clientId", clientId);
    return ERR_SUCCESS;
}

QString AccessTokenKeeper::ReadClientSecret(){
    return settings->value("secret").toString();
}

int AccessTokenKeeper::WriteClientSecret(QString secret){
    settings->setValue("secret", secret);
    return ERR_SUCCESS;
}

QString AccessTokenKeeper::ReadAccessToken(){
    return settings->value("accessToken").toString();
}

int AccessTokenKeeper::WriteAccessToken(QString accessToken){
    settings->setValue("accessToken", accessToken);
    return ERR_SUCCESS;
}

QString AccessTokenKeeper::ReadExpireTime(){
    return settings->value("expireTime").toString();
}

int AccessTokenKeeper::WriteExpireTime(QString expireTime){
    settings->setValue("expireTime", expireTime);
    return ERR_SUCCESS;
}

/**
 * 鉴权Authorization字段
 * @brief AccessTokenKeeper::getAuthorization
 * @return
 */
QString AccessTokenKeeper::getAuthorization(){
    QString concatenated = ReadClientId() + ":" + ReadClientSecret();
    QByteArray data = concatenated.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    return headerData;
}
