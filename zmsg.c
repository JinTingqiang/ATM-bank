#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "zmsg.h"

int get_msg(const char *pathname, int proj_id)
{
	int msgid = msgget(ftok(pathname,proj_id),IPC_CREAT|0666);
	if(0 > msgid)
	{
		perror("msgget");
	}
	return msgid;
}

int send_msg(int msqid,const void *msgp,size_t size)
{
	int ret = msgsnd(msqid,msgp,size-sizeof(long),0);
	if(0 > ret)
	{
		perror("msgsnd");
	}
	return ret;
}

int recv_msg(int msqid,void *msgp,size_t size,long type)
{
	int ret = msgrcv(msqid,msgp,size,type,0);
	if(0 > ret)
	{
		perror("msgrcv");
	}
	return ret;
}

int del_msg(int msqid)
{
	int ret = msgctl(msqid,IPC_RMID,NULL);
	if(0 > ret)
	{
		perror("msgctl");
	}
	return ret;
}

