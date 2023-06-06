#include <stdio.h>
#include <unistd.h>

int main(int argc,const char* argv[])
{
	for(;;)
	{
		printf("%s\n",argv[0]);
		sleep(1);
	}
}
