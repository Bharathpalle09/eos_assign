#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

typedef struct ad {
int start;
int stop;
}ad_t;

void* sum_fun(void* param)
{
ad_t *sum=(ad_t *)param;
int s=0,i,*res;
for(i=sum->start;i<=sum->stop;i++)
{
s=i+s;
printf("adding ...%d\n",i);
sleep(1);
}
printf("%d",s);
res=(int*)malloc(sizeof(int));
*res=s;
return res;
}



int main()
{
int res,*result;
ad_t s={.start=20,.stop=30};
pthread_t t1;
res=pthread_create(&t1,NULL,sum_fun,&s);
if(res<0)
{
perror("pthread_create () is failed");
_exit(1);
}
printf("thread 1 is waiting .....");
pthread_join(t1, (void**) &result);
printf("t1 result :%d\n",*result);
return 0;
}

