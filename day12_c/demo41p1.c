#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
int fd,cnt;
char str[35];
fd=open("/tmp/desd_fifo",O_WRONLY);
if(fd<0)
{
perror("open() failed");
_exit(1);
}

printf("enter the string\n");
scanf("%s",str);

cnt=write(fd,str,strlen(str)+1);
printf("the no.of bytes written fifo:%d\n",cnt);

close(fd);
return 0;
}

