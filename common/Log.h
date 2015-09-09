#ifndef _LOG_H
#define _LOG_H

#include "Util.h"

enum LOG_LEVEL
{
    //the level value start from 0, and the level value is bigger, the level is lower.
    EMERG_LEVEL = 0x0001,
    ALERT_LEVEL = 0x0002,
    ERROR_LEVEL = 0x0004,
    NOTIC_LEVEL = 0x0008,
    INFO_LEVEL  = 0x0010,
    STAT_LEVEL  = 0x0020,
    DEBUG_LEVEL = 0x0040,
    ALL_LEVEL   = 0xFFFF
};

#define EMERG __FILE__,__LINE__,EMERG_LEVEL
#define ALERT __FILE__,__LINE__,ALERT_LEVEL
#define ERROR __FILE__,__LINE__,ERROR_LEVEL
#define NOTIC __FILE__,__LINE__,NOTIC_LEVEL
#define INFO  __FILE__,__LINE__,INFO_LEVEL
#define STAT  __FILE__,__LINE__,STAT_LEVEL
#define DEBUG __FILE__,__LINE__,DEBUG_LEVEL

#define MAX_LOG_BUFFER  2048
#define MAX_LOG_PATH    256

#ifdef __CONNECT_SVR__
#define DEFAULT_LOG_PATH    "../../log/connector/cn"
#define DEFAULT_STAT_PATH   "../../stat/cn"

#elif defined(__CIRCLE_SVR__)
#define DEFAULT_LOG_PATH    "../../log/circlesvr/cs"
#define DEFAULT_STAT_PATH   "../../static/cs"

#elif defined(__DATA_CENTER__)
#define DEFAULT_LOG_PATH    "../../log/datacenter/dc"
#define DEFAULT_STAT_PATH   "../../stat/dc"

#elif defined(__STORAGE_SVR__)
#define DEFAULT_LOG_PATH    "../../log/storagesvr/ss"
#define DEFAULT_STAT_PATH   "../../stat/ss"

#elif defined(__STATISTIC_SVR__)
#define DEFAULT_LOG_PATH    "../../log/statisticsvr/ss"
#define DEFAULT_STAT_PATH   "../../stat/ss"

#endif

typedef struct 
{
    LOG_LEVEL   eLevel;
    time_t      tTime;
    uint16      wLen;
    char        cBuffer[MAX_LOG_BUFFER];
}LOG_INFO;

/**
 * ��־������
 */
class CLogger
{
public:
    CLogger();
    ~CLogger();

    bool Init(uint32 dwID, uint32 dwIP, uint16 wPort);
    void SetLogLevel(uint16 wLevel, bool bSet);

    int  Log(const char *pFileName, unsigned int nLine, LOG_LEVEL eLevel, const char *pBuffer, ...);

protected:
    static void * ThreadCallback(void *pParam);
    bool ConnServer();
    int Write(LOG_INFO *pLogInfo);
    const char* GetLevelString(LOG_LEVEL eLevel);

private:
    uint16          m_wLevel;   
    uint32          m_dwLogID;
    uint32          m_dwIP;
    uint16          m_wPort;
    int32           m_dwSockFd;

    CObjectPool<LOG_INFO>   m_oLogQ, m_oIdleQ;
    CSem            m_oSem;

    uint32          m_dwIndexL;
    FILE*           m_pLogFile;
    uint32          m_dwIndexS;
    FILE*           m_pStatFile;
};

extern CLogger Logger;

#ifdef __CONNECT_SVR__
void stat_log(const char* pszFileName, const int nLine, const char* func, const char *pszInfo, ...);
#define statlog(fmt, args...) stat_log( __FILE__, __LINE__, __func__, fmt , ##args);
int init_stat_log(uint32 dwid);
#endif

#endif

