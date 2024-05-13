#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int ret1,ret2,ret3,i,s1,s2,s3;
	ret1=fork();
	if(ret1==0)
	{
		ret2=fork();
		if(ret2==0)
		{
			ret3=fork();
			if(ret3==0)
			{
				for(i=0;i<5;i++)
				{
					printf("child3 :%d\n",i);
					sleep(1);
				}
				_exit(0);
				
}

				for(i=0;i<5;i++)
				{
					printf("child2 :%d\n",i);
					sleep(1);

				}
					_exit(0);
}			
			for(i=0;i<5;i++)
			{
				printf("child1 :%d\n",i);
				sleep(1);
			}
			_exit(0);


		
}
	waitpid(ret1,&s1,0);
			waitpid(ret2,&s2,0);
					waitpid(ret3,&s3,0);
				printf("child 3 exit :%d\n",WEXITSTATUS(s3));
			printf("child 2 exit :%d\n",WEXITSTATUS(s2));
	printf("child 1 exit :%d\n",WEXITSTATUS(s1));
{

	printf("this is the parent A");
}
}
