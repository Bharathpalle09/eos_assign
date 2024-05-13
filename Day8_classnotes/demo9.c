#include<unistd.h>
#include<stdio.h>

int main()
{
	int ret;
	printf("program started ..\n");
	ret=fork();
	if(ret==0){
	printf("child process:.\n");
	}
	else
	{
	printf("parent process\n");
	}
	printf("sucessfully done\n");
}
