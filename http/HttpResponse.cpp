#include "HttpResponse.h"

HttpResponse::HttpResponse(QObject *parent) : QObject(parent)
{
    m_errCode = 0;
}

HttpResponse::~HttpResponse()
{

}

