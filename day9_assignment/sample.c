#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
int i;
while(1)
{
printf("running:%d\n",i);
i++;
sleep(1);
}
return 0;
}
