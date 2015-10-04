#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QtSql>
#include "protocol/AuthCodeGetRequest.h"
#include "protocol/AuthCodeGetResponse.h"

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
//        AuthCodeGetRequest authCodeGetRequest = new AuthCodeGetRequest();
//        authCodeGetRequest.mobile = userName;
//        authCodeGetRequest.type = 1;

        QNetworkRequest request;
//        request = new QNetworkRequest();
        QByteArray postData;

        postData.append("mobile=" + userName);
        postData.append("type=1");
//        int contentLength = content.length();

        request.setUrl(QUrl(AUTH_CODE_SEND_URL));
//        request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
//        request.setHeader(QNetworkRequest::ContentLengthHeader,contentLength);

        manager = new QNetworkAccessManager(this);
        connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(onResponse(QNetworkReply*)));
        manager->post(request, postData);


//        User *user = new User();
//        user->load(authCodeGetRequest, this);
    }
}


void LoginDialog::onResponse(QNetworkReply *reply)
{
    QString all = reply->readAll();
    reply->deleteLater();
    if(reply->error() == QNetworkReply::NoError){
        //解析json
        AuthCodeGetResponse* authCodeGetResponse = new AuthCodeGetResponse();
        if(ERR_SUCCESS == authCodeGetResponse->Parse(all)){
            QDialog::accept();
        }else{
            QMessageBox::information(this,tr("错误信息"),tr("登录失败"),QMessageBox::Ok);
            QDialog::reject();
        }


    }else{
        QDialog::reject();
    }
}
