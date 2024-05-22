#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * fun(void * param)
{
int i;
for(i=0;i<=10;i++)
{
printf("thread :%d\n",i);
sleep(1);
}
return NULL;
}

int main() 
{
pthread_t t1;
pthread_create(&t1,NULL,fun,NULL);
printf("press enter to cancle the thread .. \n");
getchar();
pthread_cancel(t1);
printf("bye!\n");
return 0;
}

