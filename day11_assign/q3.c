#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

int arr[2],ret;
void sigint_handler(int sig) {
	//printf("SIGINT caught: %d\n", sig)
	close(arr[1]);
	close(arr[0]);
	_exit(0);
}
int main()
{
	char ch='A';
	ret=pipe(arr);
	signal(SIGINT, sigint_handler);
	int count=0;
	while(1)
	{
		write(arr[1],&ch,1);
		count++;
		printf("bytes writtern :%d\n",count);
	}}
