#ifndef _STRUCT_H
#define _STRUCT_H



#pragma pack(1) //指明下面结构体按照1字节方式进行对齐，无空字节

struct CLIENT_INFO_T
{
    pthread_t recvmsg_task_handle;
    pthread_t heartbeat_task_handle;
    int sockfd;
    int user_port;
    int user_id;
    int circle_id;
    bool islogin;
};

#endif
