#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

int main()
{
int ret,pid,sig_num;
printf("enter the pid,sig_num\n");
scanf("%d %d",&pid,&sig_num);
ret=kill(pid,sig_num);
if(ret==0)
{
printf("kill successfully \n");

}
else 
{
perror("failed");
_exit(1);
}
return 0;
}

