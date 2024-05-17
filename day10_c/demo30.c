#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

int main()
{
	sigset_t set;
	int i=1,ret;
	sigemptyset(&set);
	sigaddset(&set,SIGTERM);
	sigaddset(&set,SIGINT);
	ret=sigprocmask(SIG_SETMASK,&set,NULL);
	if(ret < 0)
	{
		perror("sigpromask() failed");
		_exit(1);
	}
	while(1)
	{
		printf("running :%d\n",i++);
		sleep(2);
	}
	return 0;
}

