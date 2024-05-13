#include<unistd.h>
#include<stdio.h>
int main()
{
int ret,i;
ret=fork();
if(ret==0){
for(i=0;i<30;i++){
printf("child process: %d\n",i);
sleep(1);
}
}
else {
for(i=0;i<30;i++){
printf("parent process: %d\n",i);
sleep(1);
}
}
printf("successfully done\n");
}
