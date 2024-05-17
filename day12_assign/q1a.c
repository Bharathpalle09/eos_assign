#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
int arr[3],fd,cnt,cnt1,fd1,sum;
fd=open("/tmp/as1",O_RDONLY);
if(fd<0)
{
perror("fd() failed");
_exit(1);
}
fd1=open("/tmp/res",O_WRONLY);
if(fd1<0)
{
perror("fd1() failed");
_exit(2);
}

printf("waiting of the data ......\n");
cnt=read(fd,arr,sizeof(arr));
for(int i=0;i<2;i++)
printf("the number are %d\n",arr[i]);

printf("the sum of two numbers id ...\n");
arr[2]=arr[0]+arr[1];
cnt1=write(fd1,arr,sizeof(arr));
printf("the result to verify: %d\n",arr[2]);
close(fd1);
close(fd);
return 0;
}


