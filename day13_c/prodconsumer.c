#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait>
#include<signal.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include"cirque.h"
#include<string.h>

#define SHM_key 0x2832
#define SEM_key 0x1234

int semid,shmid;
cirque_t *ptr;



     union semun {
             int     val;            /* value for SETVAL */
             struct  semid_ds *buf;  /* buffer for IPC_STAT & IPC_SET */
             u_short *array;         /* array for GETALL & SETALL */
     };


int main()
{

int ret,pid,val;
union semun su;
struct sembuf ops[2];
int sighandler sa;
memset(&sa,0,sizeof(struct sigaction));
sa.sa_handler = sigint_handler;
ret=sigaction(SIGINT,&sa,NULL);
shmid=shmget(SHM_key,sizeof(cirque_t),IPC_CREAT|0644);
ptr=shmat(shmid,,NULL,0);
cq_init(ptr);
semid=semget(SEM_key,3,IPC_CREAT|0600);
su.val=1;
ret=semctl(semid,0,SETVAL,su);
su.val=6;
ret=semctl(semid,1,SETVAL,su);
su.val=0;
ret=semctl(semid,2,SETVAL,su);
pid=fork();
if(pid==0)
{
ops[0].sem_num=2;
ops[0].sem_op=-1;
ops[0].sem_flg=0;
ops[1].sem_num=0;
ops[1].sem_op=-1;
ops[1].sem_flg=0;
ret=semop(semid,ops,2);
val=cq_pop(ptr);
printf("RD:%d\n",val);
ops[0].sem_num=



























