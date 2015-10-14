#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QtSql>
#include "http/AccessTokenRequest.h"
#include "protocol/LoginResponse.h"
#include "common/AccessTokenKeeper.h"
#include "common/AccountKeeper.h"
#include <QUuid>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{

    ui->setupUi(this);
    setFixedSize(240,360);
    setWindowTitle(tr("登录"));
    ui->userName->setFocus();
    ui->loginBtn->setDefault(true);

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

/**
 * 用户登录响应
 * @brief LoginDialog::on_loginBtn_clicked
 */
void LoginDialog::on_loginBtn_clicked()
{
    QString userName = ui->userName->text();
    QString pass = ui->pass->text();
    if(userName.isEmpty()){
        QMessageBox::information(this,tr("请输入用户名"),tr("请先输入用户名！"),QMessageBox::Ok);
        ui->userName->setFocus();
    }else if(pass.isEmpty()){
        QMessageBox::information(this,tr("请输入密码"),tr("请先输入密码再登录！"),QMessageBox::Ok);
        ui->pass->setFocus();
    }else{

//        发送get请求
//        QNetworkRequest request;
//        QUrl qurl(AuthCodeSendUrl);
//        QUrlQuery tmpQuery;//request参数

//        tmpQuery.addQueryItem("mobile",userName);
//        tmpQuery.addQueryItem("type","1");
//        qurl.setQuery(tmpQuery);
//        request.setUrl(qurl);

        manager = new QNetworkAccessManager(this);
        connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(onResponse(QNetworkReply*)));
//        manager->get(request);

//        netWorker = NetWorker::instance();
//        manager = new QNetworkAccessManager(this);
//        connect(netWorker, &NetWorker::finished, this,SLOT(onResponse(QNetworkReply*)));

        QString uuid  = QUuid::createUuid().toString();
        QUrlQuery postData;
        postData.addQueryItem("username", userName);
        postData.addQueryItem("password", pass);
        postData.addQueryItem("uuid", uuid);

//        netWorker->post(UserLoginUrl, postData.toString(QUrl::FullyEncoded).toUtf8());
        QNetworkRequest request(UserLoginUrl);
        request.setHeader(QNetworkRequest::ContentTypeHeader,
            "application/x-www-form-urlencoded");
        manager->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());

//        qDebug()<< QDate::currentDate() << "on_loginBtn_clicked (in) 222";

    }
}

void LoginDialog::onResponse(QNetworkReply *reply)
{
    QString all = reply->readAll();

    reply->deleteLater();
    if(reply->error() == QNetworkReply::NoError){
        qDebug()<< QDate::currentDate() << "LoginDialog::onResponse (in) 222，all:";
        qDebug()<< QDate::currentDate() << all;
        //解析json
        LoginResponse* loginResponse = new LoginResponse();
        loginResponse->Parse(all);
        if(loginResponse->m_userId != 0){
            //存储
            accessTokenKeeper.WriteClientId(loginResponse->m_clientId);
            accessTokenKeeper.WriteClientSecret(loginResponse->m_clientSecret);
            accountKeeper.setUserId(loginResponse->m_userId);
            //开启一个线程获取accessToken
            AccessTokenRequest* accessTokenRequest = new AccessTokenRequest();
            accessTokenRequest->execute();

            QDialog::accept();
        }else{
            qDebug()<< QDate::currentDate() << "LoginDialog::onResponse (in) 333";
            QMessageBox::information(this,tr("错误信息"),tr("登录失败:" + loginResponse->m_errMsg.toUtf8()),QMessageBox::Ok);
            QDialog::reject();
        }


    }else{
        QDialog::reject();
    }
}
