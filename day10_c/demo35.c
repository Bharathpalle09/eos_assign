#include<stdio.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/wait.h>

#define MQ_KEY 0x1909

typedef struct mes {
	long type;
	char data[32];
}msg_t;

int main() {
	int mqid,ret,s;
	mqid = msgget(MQ_KEY,IPC_CREAT|0600);
	if(mqid < 0)
	{
		perror("msgget() failed");
		_exit(1);
	}

	ret=fork();
	if(ret == 0)
	{
		msg_t m1;
		m1.type=1;
		printf("sender : enter a string :\n");
		scanf("%s",m1.data);
		ret=msgsnd(mqid,&m1,sizeof(m1.data),0);
		printf("sender : message sent: %d\n ",ret);
	}
	else
	{
		msg_t m2;
		printf("reciever :waiting for the message ...\n");
		ret=msgrcv(mqid,&m2,sizeof(m2.data),1,0);
		printf("receiver : message received : %d--%s\n",ret,m2.data);

		wait(&s);

	}
	return 0;

}













