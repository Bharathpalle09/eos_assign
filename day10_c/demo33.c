#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

void sigint_handler(int sig){
	int i;
	    for (i=1;i<=5;i++)
	    {
		    printf("singal caught :%d\n",sig);
		    sleep(1);
	    }
}

int main()
{
	int i=1,ret;
	struct sigaction sa;
	memset(&sa,0,sizeof(struct sigaction));
	sa.sa_handler=sigint_handler;
	sigfillset(&sa.sa_mask);
	ret=sigaction(SIGINT,&sa,NULL);
	if(ret<0)
	{
		perror("sigaction() failed");
		_exit(1);
	}
	while(1){
		printf("running :%d\n",i++);
		sleep(2);
	}
	return 0;
}

