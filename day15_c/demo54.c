#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void* table(void* param)
{
int i,*num = (int*)param;
for(i=1;i<=10;i++)
{
printf("%d*%d=%d\n",*num,i,*num*i);
sleep(1);
}
return NULL;
}

int main()
{
pthread_t t1,t2,t3;
int num1=13,num2=32,num3=12,ret;
ret=pthread_create(&t1,NULL,table,&num1);
ret=pthread_create(&t2,NULL,table,&num2);
ret=pthread_create(&t3,NULL,table,&num3);

printf("press enter to exit()");
getchar();
return 0;
}
 
