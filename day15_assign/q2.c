#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<pthread.h>
#include<stdlib.h>

typedef struct arr{
int *arr;
int size;
}arr_t;


void* thread_func(void* param)
{
arr_t *ret,*arr=(arr_t *)param;
	   int i, j, min_idx,temp,n;
	n=arr->size;

    // One by one move the boundary of the unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in the unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr->arr[j] < arr->arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element

        temp=arr->arr[min_idx];
        arr->arr[min_idx]= arr->arr[i];
        arr->arr[i]=temp;
 }
ret=(arr_t*)malloc(sizeof(arr_t));
ret=arr->arr;
return ret;
}

int main()
{
int i,ret,*result;
pthread_t t1;
arr_t a1={.size=10};
printf("enter the elements");
for(i=0;i<=a1.size;i++)
{
scanf("%d",a1.arr[i]);
}

pthread_create(&t1,NULL,thread_func,&a1);
printf("press enter to get sorted array ");
getchar();
pthread_join(t1,(void **)&result);
a1.arr=(arr_t **)result;
for(int i=0;i<a1.size;i++)
{
printf("%d\n",a1.arr[i]);
sleep(1);
}
return 0;
}

 
