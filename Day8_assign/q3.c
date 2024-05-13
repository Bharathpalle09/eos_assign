#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
int ret,s,i,count;
i=1;
while(1){
ret=fork();
if(ret==0){
count++;
_exit(0);
}
//printf("no:of pid :%d\n",count);
else if(ret==-1)
break;
else{
i++;
}
printf("total count: %d\n",i);
}
for(int j=1;j<=i;j++)
wait(&s);
}


