#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>
#include <sys/syscall.h>
void sigint_handler(int sig)
{

	printf("signal caught");
	printf("current PID=%d,current posix thread ID:%lu\n",getpid(),pthread_self());
	//int r=pthread_threadid_np(NULL, &tid);
	//if(r==getpid())
	//_exit(0);
	//else
	pthread_exit(NULL);

}



void* fun(void* param)
{
	int i;
	for(i=0;i<=10;i++)
	{
		printf("thread :%d",i);
		sleep(1);
	}
	return NULL;
}

int main()
{
	pthread_t t1;
	int ret;
	struct sigaction sa;
	memset(&sa,0,sizeof(sa));
	sa.sa_handler=sigint_handler;
	ret=sigaction(SIGINT,&sa,NULL);
	ret=pthread_create(&t1,NULL,fun,NULL);
	printf("press enter to send the signal to the thread");
	getchar();
	pthread_kill(t1,SIGINT);
	printf("press enter to exit....\n");
	getchar();

	printf("bye!\n");
	return 0;
}

