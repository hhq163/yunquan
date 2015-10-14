#include "NetWorker.h"

/**
 * 单例模式
 */
class NetWorker::Private
{
public:
    Private(NetWorker *q) :
        manager(new QNetworkAccessManager(q))
    {}

    QNetworkAccessManager *manager;
};

/**
 * 实例化
 * @brief NetWorker::instance
 * @return
 */
NetWorker *NetWorker::instance()
{
    static NetWorker netWorker;
    return &netWorker;
}

NetWorker::NetWorker(QObject *parent) :
    QObject(parent),
    d(new NetWorker::Private(this))
{
    connect(d->manager, &QNetworkAccessManager::finished,
            this, &NetWorker::finished);
}

NetWorker::~NetWorker()
{
    delete d;
    d = 0;
}

//void NetWorker::finished(QNetworkReply *reply){
//    qDebug()<< QDate::currentDate() << "NetWorker::finished (in) 111";
//}

/**
 * @brief 发送get请求
 * @param url
 */
void NetWorker::get(QNetworkRequest &request)
{
    d->manager->get(request);
}

/**
 * @brief 发送Post请求
 * @param url
 * @param data
 */
void NetWorker::post(const QString &url, const QByteArray &data){
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,
        "application/x-www-form-urlencoded");

    d->manager->post(request, data);
}


