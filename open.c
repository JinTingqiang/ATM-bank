#include <stdio.h>
#include <unistd.h>
#include "bank.h"
#include "zmsg.h"

CtoS_MSG ctos;
StoC_MSG stoc;

void open_acc(void)
{
	//	具体功能实现
	printf("recvfrom:%u banlanc:%lf id:%s\n",
	ctos.pid,ctos.acc.balance,ctos.acc.id);
	
	sprintf(stoc.info,"OPEN success!\n");
	stoc.type = ctos.pid;
}

int main(int argc,const char* argv[])
{
	printf("%s\n",argv[0]);
	int msgid = get_msg(A_OUT_PATH,120);
	
	for(;;)
	{
		recv_msg(msgid,&ctos,sizeof(ctos),MSGTYPE_OPEN);
		open_acc();
		send_msg(msgid,&stoc,sizeof(stoc));
	}
}
