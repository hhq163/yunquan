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
        AuthCodeGetRequest authCodeGetRequest = new AuthCodeGetRequest();
        authCodeGetRequest.mobile = userName;
        authCodeGetRequest.type = 1;
        User *user = new User();
        user->load(authCodeGetRequest, this);
    }
}


void LoginDialog::onResponse(QNetworkReply *reply)
{
    QString all = reply->readAll();
    reply->deleteLater();
    if(reply->error() == QNetworkReply::NoError){
        //解析json
        AuthCodeGetResponse authCodeGetResponse = new AuthCodeGetResponse();
        authCodeGetResponse.Parse(all);
        QDialog::accept();
    }else{
        QDialog::reject();
    }
}
