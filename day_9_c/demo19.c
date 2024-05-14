#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int ret,err,s;
	printf("the parent process has started: \n");
	ret=fork();
	if(ret==0)
	{
		err=execlp("/usr/sbin/google-chrome","google-chrome","http://sunbeaminfo.in",NULL);
		
		if(err<0){
			printf("exec() failed\n");
			_exit(1);
		}
	}else
{
	wait(&s);
	printf("The exit status of child : %d\n",WEXITSTATUS(s));
}
printf("parent completed\n");
return 0;
}
