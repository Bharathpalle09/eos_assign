#include "demo36.h"
int main()
{
int mqid,ret;
msg_t m2;
mqid=msgget(MQ_KEY,0);
if(mqid < 0)
{
	perror("msgget() is failed");
	_exit(1);
}
printf("p2:is waiting for message\n");
ret=msgrcv(mqid,&m2,sizeof(m2.str),11,0);
printf("p2:the message recieved is :%s\n",m2.str);
msgctl(mqid,IPC_RMID,NULL);
}



