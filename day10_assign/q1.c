#include<stdio.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/wait.h>

#define MQ_KEY 0x1909

typedef struct mes{
	long type;
	int op1;
	int op2;
	
}msg_t;

typedef struct res{
long type;
int ret;
}mr_t;

int main() {
	int mqid,ret1,ret,s;
	mqid=msgget(MQ_KEY,IPC_CREAT|0600);
	if(mqid < 0)
	{
		perror("msgget() failed");
		_exit(1);
	}

	ret=fork();
	if(ret==0)
	{
		msg_t m1;
		m1.type=1;
		printf("sender :enter the oparand 1 and 2 :\n");
		scanf("%d %d",&m1.op1,&m1.op2);
		ret=msgsnd(mqid,&m1,sizeof(m1)-sizeof(long),0);
		printf("sender : message sent :%d\n", ret);
		mr_t m4;
		ret=msgrcv(mqid,&m4,sizeof(m4)-sizeof(long),23,0);
		printf("received sum :%d\n",m4.ret);
	}
	else
	{
		msg_t m2;
		printf("reciever is waiting for message .....\n");
		ret=msgrcv(mqid,&m2,sizeof(m2)-sizeof(long),1,0);
		
		printf("receiver : message received :%d--%d and  %d\n",ret,m2.op1,m2.op2);
		mr_t m3;
		m3.ret = m2.op1+m2.op2;
		m3.type=23;
		ret=msgsnd(mqid,&m3,sizeof(m3)-sizeof(long),0);
		printf("to verify result :%d\n",m3.ret);
		wait(&s);
	}
	return 0;
}






