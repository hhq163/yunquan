#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H
#include <QThread>
#include "http/HttpRequest.h"

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    WorkerThread();
    WorkerThread(HttpRequest* request);
    ~WorkerThread();
public:
    void run();
private:
    HttpRequest* httpRequest;
};

#endif // WORKERTHREAD_H
