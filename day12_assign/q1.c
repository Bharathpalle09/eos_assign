#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{	int fd,cnt,cnt1,fd1,arr[3],sum=0;
fd=open("/tmp/as1",O_WRONLY);
if(fd<0)
{
perror("fd failed");
_exit(1);
}
fd1=open("/tmp/res",O_RDONLY);
if(fd1<0)
{
perror("fd1() failed");
_exit(4);
}

printf("enter the num1 and num2 : \n");
for(int i=0;i<=1;i++)
scanf("%d",&arr[i]);

cnt=write(fd,arr,sizeof(arr)+1);
printf("writtern in fifo :%d bytes\n",cnt);

printf("the sum is\n");
cnt1=read(fd1,arr,sizeof(arr));
printf("%d",arr[2]);

close(fd1);
close(fd);
return 0;
}


