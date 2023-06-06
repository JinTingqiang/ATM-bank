#ifndef ZMSG_H
#define ZMSG_H

int get_msg(const char *pathname, int proj_id);

int send_msg(int msqid,const void *msgp,size_t size);

int recv_msg(int msqid,void *msgp,size_t size,long type);

int del_msg(int msqid);

#endif//ZMSG_H
