#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main()
{
	int ret,err,s,fd;
	printf("parent started");
	ret=fork();
	if(ret==0)
	{
		fd=open("in.txt",O_RDONLY);
		dup2(fd,0);
		close(fd);

		err=execlp("wc","wc",NULL);
		if(err < 0) {
			perror("exec() failed");
			_exit(1);
		}
	}
	else
		waitpid(-1, &s, 0);
	printf("parent completed!\n");
	return 0;
}

