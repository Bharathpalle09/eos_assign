#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/sem.h>

#define SEM_KEY 0x7327


int main()
{
int i,ret,s,semid;
union semun su;
struct sembuf ops[1];

semid=semget(SEM_KEY,1,IPC_CREAT|0600);
if(semid <0)
{
perror("semid failed");
_exit(2);
}

su.val=0;
ret=semctl(semid,0,SETVAL,su);
if(ret < 0)
{
perror("semctl () failed");
_exit(6);
}

ret=fork();
if(ret==0)
{

char *str="Sunbeam \n";
for(i=0;str[i] !='\0';i++)
{
putchar(str[i]);
fflush(stdout);
sleep(1);
}

ops[0].sem_num = 0;
ops[0].sem_op=+1;
ops[0].sem_flg=0;
ret=semop(semid,ops,1);

}
else
{
char *str="Infotech\n";
ops[0].sem_num=0;
ops[0].sem_op=-1;
ops[0].sem_flg=0;
semop(semid,ops,1);
for(i=0;str[i] !='\0';i++)
{
putchar(str[i]);
fflush(stdout);
sleep(1);
}
waitpid(ret,&s,0);

semctl(semid,0,IPC_RMID);
}
return 0;
}
















