#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int ret,err,s;
	printf("parent started\n");
	ret=fork();
	if(ret==0)
	{
		err=execl("/Users/cherikiansh/Desktop/eos_assign/day_9_c/demo17.out","demo17.out","one","two","three","four",NULL);
		if(err<0)
		{
			perror("execution failed");
			_exit(1);
		}
	}
	else
	{
		wait(&s);
		printf("child exit status :%d\n",WEXITSTATUS(s));
	}
	printf("parent completed");
	return 0;
}
