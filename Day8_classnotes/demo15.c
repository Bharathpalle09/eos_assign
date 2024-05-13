#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int ret,i,s;
	ret=fork();
	if(ret==0)
	{
		for(i=0;i<10;i++)
		{
			printf("child process : %d\n",i);
			sleep(1);
		}
		_exit(2);
	}
	else
	{
		for(i=0;i<20;i++)
		{	
			printf("parent process :%d\n",i);
			sleep(1);
			if(i==5)
			{
				wait(&s);
				printf("Child exit :%d\n",WEXITSTATUS(s));
			}
		}
	}
	return 0;
}
