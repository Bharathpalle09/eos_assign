#include<unistd.h>
#include<stdio.h>
int main(){
int ret;
ret=fork();
if(ret==0){
printf("child:fork returned :%d\n",ret);
printf("child:the pid=%d\n",getpid());
printf("child:the ppid=%d\n",getppid());
}
else
{
printf("parent:fork returned :%d\n",ret);
printf("parent:the pid=%d\n",getpid());
printf("parent:the ppid=%d\n",getppid());
}
printf("program completed\n");
getchar();
return 0;
}
