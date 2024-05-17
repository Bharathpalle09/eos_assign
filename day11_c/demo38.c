#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
int main()
{
	int arr[2],ret,s;
	char datawr[32],datard[32];
	ret =pipe(arr);
	if(ret<0)
	{
		perror("pipe() failed");
		_exit(1);
	}
	ret=fork();
	if(ret==0)
	{       close(arr[0]);
		printf("enter a string");
		scanf("%s",datawr);
		ret=write(arr[1],datawr,strlen(datawr)+1);
		printf("data written in pipe : %d bytes\n",ret);
		close(arr[1]);
	}
	else
	{
		close(arr[1]);
		ret=read(arr[0],datard,sizeof(datard));
		printf("data read from pipe:%d bytes %s\n",ret,datard);
		close(arr[0]);
		waitpid(-1,&s,0);
	}
	return 0;
}
