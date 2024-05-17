#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>


void sigint_handler( int sig)
{
	printf("SIgint caught : %d\n",sig);
}

int main()
{
	int i=1,ret;
	struct sigaction sa;
	memset(&sa,0,sizeof(struct sigaction));
	sa.sa_handler= sigint_handler;
	ret = sigaction(SIGINT,&sa,NULL);
	if(ret<0)
	{
		perror("sigaction() failed");
		_exit(1);
	}
	while(1){
		printf("running :%d\n",i++);
			sleep(1);
	}
	return 0;
}
