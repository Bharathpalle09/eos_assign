#include<stdlib.h>
#include "cirque.h"

void cq_init(cirque_t *cq)
{
cq->front =-1;
cq->rear =-1;
cq->count=0;
}

void cq_push(cirque_t *cq,int val)
{
cq->rear=(cq->rear+1)%SIZE;
cq->arr[cq->rear]=val;
cq->count++;
}

int cq_pop(cirque_t *cq)
{
int val;
 cq->front=(cq->front+1)%SIZE;
val=cq->arr[cq->front];
cq->count--;
return val;
}

int cq_peek(cirque_t *cq)
{
int val;
int i=(cq->front+1)%SIZE;
val = cq->arr[i];
return val;
}

int cq_isfull(cirque_t *cq)
{	return (cq->count==SIZE);
}

int cq_isempty(cirque_t *cq)
{
	return (cq->count ==0);
}
