#include"demo36.h"

int main()
{
int ret,mqid;
msg_t m1;
mqid=msgget(MQ_KEY,IPC_CREAT |0600);
if(mqid<0)
{
perror("msgget() is failed");
_exit(1);
}

printf("p1:printf the message");
scanf("%s",m1.str);
m1.type=11;
ret=msgsnd(mqid,&m1,sizeof(m1.str),0);
printf("the message has been sent :%d\n",ret);
return 0;
}

