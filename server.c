#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "zmsg.h"
#include "bank.h"

pid_t pid[FORK_COUNT];
int msgid;

void sigint(int num)
{
	for(int i=0; i<FORK_COUNT; i++)
	{
		kill(pid[i],SIGINT);
	}
	usleep(1000);
	del_msg(msgid);
	exit(0);
}

int main(int argc,const char* argv[])
{
	msgid = get_msg(A_OUT_PATH,120);
	signal(SIGINT,sigint);

	const char* path[FORK_COUNT] = {
	"./bin/open",
	"./bin/destroy",
	"./bin/login",
	"./bin/unlock",
	"./bin/save",
	"./bin/take",
	"./bin/query",
	"./bin/transfer",
	"./bin/repass"};
	for(int i=0; i<FORK_COUNT; i++)
	{
		pid[i] = vfork();		
		if(0 == pid[i])
		{
			execl(path[i],path[i],NULL);	
		}
	}
	
	while(-1 != wait(NULL));
}

