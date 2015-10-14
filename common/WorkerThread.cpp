#include "WorkerThread.h"

WorkerThread::WorkerThread()
{

}

WorkerThread::WorkerThread(HttpRequest* request)
{
    httpRequest = request;
}

WorkerThread::~WorkerThread()
{
    delete httpRequest;
}

void WorkerThread::run(){
    httpRequest->execute();
}
