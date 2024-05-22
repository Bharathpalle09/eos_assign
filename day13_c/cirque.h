#ifndef _CIRQUE_H
#define _CIRQUE_H
#include<stdio.h>

#define SIZE 6

typedef struct {
int arr[SIZE];
int front,rear;
int count;
}cirque_t;


void cq_init(cirque_t *cq);
void cq_push(cirque_t *cq,int val);
int cq_pop(cirque_t *cq);
int cq_peek(cirque_t *cq);
int cq_isfull(cirque_t *cq);
int cq_isempty(cirque_t *cq);

#endif




