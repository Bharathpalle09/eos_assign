#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/sem.h>

#define SHM_KEY 0x4231
#define SEM_KEY 0X1432

typedef struct shm {
	int count ;
}shm_t;

union semum {
	int              val;    /* Value for SETVAL */
	struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
	unsigned short  *array;  /* Array for GETALL, SETALL */
	struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
};

int main()
{
	int i,ret,s,shmid,semid;
	shm_t *ptr;
	union semum su;
	struct sembuf ops[1];

	shmid = shmget(SHM_KEY,sizeof(shm_t),IPC_CREAT|0600);
	if(shmid <0)
	{
		perror("shmget() failed");
		_exit(2);
	}
	ptr=(shm_t *)shmat(shmid,NULL,0);
	if(ptr==(void *)-1)
	{
		perror("shmat() failed");
		_exit(1);
	}
	printf("memory attached to the address : %p\n",ptr);

	shmctl(shmid,IPC_RMID,NULL);

	semid=semget(SEM_KEY,1,IPC_CREAT|0600);  //create
	if(semid<0)
	{
		perror("semid() failed");
		_exit(3);
	}

	//inti semaphore
	su.val=1;
	ret=semctl(semid,0,SETVAL,su);
	if(ret<0)
	{
		perror("semctl() failed");
		_exit(2);
	}

	ptr->count=0;
	ret=fork();
	if(ret ==0 )
	{
		for(i=1;i<=200;i++)
		{
			ops[0].sem_num = 0;
			ops[0].sem_op=-1;
			ops[0].sem_flg=0;
			ret=semop(semid,ops,1);

			ptr->count++;
			printf("incr:%d\n", ptr->count);

			ops[0].sem_num =0;
			ops[0].sem_op=+1;
			ops[0].sem_flg=0;
			ret=semop(semid,ops,1);


		}
		shmdt(ptr);
	}
	else
	{
		for(i=1;i<=200;i++)
		{
			ops[0].sem_num=0;
			ops[0].sem_op=-1;
			ops[0].sem_flg=0;
			ret = semop(semid,ops,1);

			ptr->count--;
			printf("decr : %d\n",ptr->count);

			ops[0].sem_num=0;
			ops[0].sem_op=+1;
			ops[0].sem_flg=0;
			ret = semop(semid,ops,1);
		}
		waitpid(ret,&s,0);
		printf("final count :%d \n",ptr->count);
		shmdt(ptr);

		semctl(semid,0,IPC_RMID);
	}
	return 0;
}




































