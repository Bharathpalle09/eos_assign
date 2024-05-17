#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
int ret1,ret2,err1,err2,s1,s2;
int arr[2],ret;
printf("parent strated\n");
ret=pipe(arr);
if(ret<0)
{
perror("the pipe() has failed \n");
_exit(1);
}


ret1=fork();
if(ret1==0)
{
close(arr[0]);
dup2(arr[1],1);
close(arr[1]);

err1=execlp("who","who",NULL);
if(err1<0)
{
perror("exec() failed");
_exit(1);
}

}

ret2=fork();
if(ret2==0)
{
close(arr[1]);
dup2(arr[0],0);
close(arr[0]);

err2 =execlp("wc","wc",NULL);
if(err2<0)
{
perror("execlp() failed");
_exit(1);
}
}

close(arr[1]);
close(arr[0]);
waitpid(ret1,&s1,0);
waitpid(ret2,&s2,0);
printf("parent completed\n");
return 0;
}

