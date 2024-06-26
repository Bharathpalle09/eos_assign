#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

void sig_handler(int sig)
{
	printf("signal caught :%d\n",sig);
	switch(sig)
	{
	case SIGINT: printf("SIGINT handled\n");
			break;
	case SIGTERM:printf("SIGTERM handled\n");
			break;
	case SIGALRM:printf("SIGALRM handled\n");
			alarm(3);
			break;

}
}

int main()
{
	int i=1,ret;
	struct sigaction sa;
	memset(&sa,0,sizeof(struct sigaction));
	sa.sa_handler = sig_handler;

	ret = sigaction(SIGINT,&sa,NULL);
		if(ret < 0)
		{
			perror("sigaction() failed");
			_exit(1);
		}

	ret=sigaction(SIGTERM,&sa,NULL);
	if(ret<0)
	{
		perror("sigaction() failed");
		_exit(1);
	}

	ret=sigaction(SIGALRM, &sa ,NULL);
	if(ret < 0)
	{
		perror("sigaction() failed");
		_exit(1);
	}

	alarm(3);

	while(1){
		printf("running :%d\n",i++);
		sleep(1);
	}
	return 0;
}

