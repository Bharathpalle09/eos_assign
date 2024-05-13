#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
int ret,i,j,s;
for(i=0;i<5;i++)
{
ret=fork();
if(ret==0)
{
for(j=0;j<5;j++)
{
printf("the count:%d\n",j);
printf("the pid:%d\n",getpid());
sleep(1);
}
_exit(0);
}
}
for(j=0;j<5;j++)
{
wait(&s);
printf("child exit %d\n",WEXITSTATUS(s));
}
return 0;
}


