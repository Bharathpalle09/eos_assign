#include <stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

void sigint_handler(int sig)
{
printf("signal caught :%d\n",sig);
}

int main()
{
	sigset_t set;
	int i=1,ret;
	struct sigaction sa;

	memset(&sa,0,sizeof(struct sigaction));
	sa.sa_handler=sigint_handler;
	ret=sigaction(SIGINT,&sa,NULL);
	if(ret<0)
	{
		perror("sigaction() failed");
		_exit(1);
	}

	printf("waiting for sigint or sigterm !\n");
	sigfillset(&set);
	sigdelset(&set,SIGTERM);
	sigdelset(&set,SIGINT);
	sigsuspend(&set);

	if(ret<0)
	{
		perror("sigprocmask() failed ");
		_exit(1);
	}
	while(1)
	{
		printf("running : %d\n",i++);
		sleep(1);
	}
	return 0;
}

