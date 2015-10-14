#include <QCoreApplication>
#include "common/common.h"
#include "AccountKeeper.h"


AccountKeeper accountKeeper;

AccountKeeper::AccountKeeper(QObject *parent)
{
    QCoreApplication::setOrganizationName("yunlai");
    QCoreApplication::setApplicationName("yunquan");

    QString m_sSettingsFile = "settings.ini";
    settings = new QSettings(m_sSettingsFile,QSettings::IniFormat);
}

AccountKeeper::~AccountKeeper()
{

}

int AccountKeeper::getUserId(){
    return settings->value("userId").toInt();
}

void AccountKeeper::setUserId(int userId){
    settings->setValue("userId", userId);
}
