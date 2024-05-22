#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void* inc_fun(void* param)
{
	int i;
	for(i=1;i<=10;i++)
	{
		printf("inc_fun :%d\n",i);
//	sleep(1);
	}
	return NULL;
}

void* desc_fun(void* param)
{
	int j;
	for(j=10;j>=1;j--)
	{
		printf("desc_fun :%d\n",j);
//	sleep(1);
	}
	return NULL;

}

int main()
{
	pthread_t in,dt;
	int res,res1;
	res=pthread_create(&in,NULL,inc_fun,NULL);
	if(res<0)
	{
		perror("the pthread_create() failed");
		_exit(1);
	}
	res1=pthread_create(&dt,NULL,desc_fun,NULL);
	if(res1<0)
	{
		perror("pthread failed()");
		_exit(2);
	}
	int i;
	for(i=1;i<=10;i++)
	{
		
	printf("main() :%d\n ",i);
	sleep(1);
	}
	return 0;
}

