#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

void sigint_handler(int sig)
{
printf("signal caught :%d\n", sig);
}



int main()
{
int i=1,ret=0;
struct sigaction sa;
memset(&sa,0,sizeof(struct sigaction));
sa.sa_handler=sigint_handler;
ret=sigaction(SIGINT,&sa,NULL);
if(ret<0)
{
perror("sigaction() failed");
_exit(1);
}
printf("waiting for any signal!\n");
pause();
while(1)
{
printf("running :%d\n",i);
i++;
}
return 0;
}

