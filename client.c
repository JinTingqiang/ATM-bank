#include <stdio.h>
#include <unistd.h>
#include "bank.h"
#include "zmsg.h"

int main(int argc,const char* argv[])
{
	int msgid = get_msg(A_OUT_PATH,120);

	CtoS_MSG ctos = {};
	sprintf(ctos.acc.id,"12341234");
	ctos.acc.balance = 88.8;
	ctos.type = MSGTYPE_OPEN;
	ctos.pid = getpid();
	
	send_msg(msgid,&ctos,sizeof(ctos));
	StoC_MSG stoc = {};
	recv_msg(msgid,&stoc,sizeof(stoc),ctos.pid);
	printf("recv server:%s\n",stoc.info);
	
}