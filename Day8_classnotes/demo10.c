#include<unistd.h>
#include<stdio.h>

int main() {
	int ret,i;
	ret = fork();
	if(ret == 0){
	for(i=0;i<15;i++)
	printf("child process:%d\n",i);
	}
	else{
	for(i=0;i<15;i++)
	printf("parent process:%d\n",i);
	}
	printf("sucessfully done\n");
}
