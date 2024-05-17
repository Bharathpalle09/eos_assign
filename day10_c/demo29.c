#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<string.h>

void sigint_handler(int sig)
{
printf("SIGINT caught :%d|| current process: %d\n",sig,getpid());
}


int main()
{
int ret,i=1;
struct sigaction sa;
memset(&sa,0,sizeof(struct sigaction));
sa.sa_handler=sigint_handler;
ret=sigaction(SIGINT,&sa,NULL);
if(ret < 0)
{
perror("sigaction() failed");
_exit(1);
}
while(1)
{
printf("running :%d\n",i++);
sleep(1);
}
return 0;
}

