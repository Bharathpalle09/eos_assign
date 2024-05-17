#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
int r,res,ret1,ret2,n1,n2,s,num1,num2,arr1[2],arr2[2];
ret2=pipe(arr1);
ret1=pipe(arr2);
res=fork();
if(res==0)
{
close(arr1[0]);
close(arr2[1]);
printf("enter the number1 and number2");
scanf("%d %d",&num1,&num2);
ret1=write(arr1[1],&num1,sizeof(num1));
ret2=write(arr1[1],&num2,sizeof(num2));
ret1=read(arr2[0],&res,sizeof(res));
printf("result :%d\n",res);
close(arr2[0]);
close(arr1[0]);

_exit(1);
}
else
{
close(arr1[1]);
close(arr2[0]);
read(arr1[0],&n1,sizeof(n1));
read(arr1[0],&n2,sizeof(n2));
r=n1+n2;
ret2=write(arr2[1],&r,sizeof(r));
close(arr2[1]);
close(arr1[0]);
waitpid(-1,&s,0);
}
return 0;
}

