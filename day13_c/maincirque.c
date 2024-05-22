#include <stdio.h>
#include "cirque.h"

int main()
{
int v;
cirque_t q;
	cq_init(&q);
	cq_push(&q, 10);
	cq_push(&q, 20);
	cq_push(&q, 30);
	cq_push(&q, 40);
	cq_push(&q, 50);
	cq_push(&q, 60);
	printf("queue is full = %d\n", cq_isfull(&q)); // 1
	printf("popped: %d\n", cq_pop(&q));	// 10
	printf("popped: %d\n", cq_pop(&q));	// 20
	printf("popped: %d\n", cq_pop(&q));	// 30
	printf("queue is full = %d\n", cq_isfull(&q)); // 0
	cq_push(&q, 70);
	cq_push(&q, 80);
	cq_push(&q, 90);
	printf("queue is full = %d\n", cq_isfull(&q)); // 1
	while(!cq_isempty(&q)) {
		v = cq_pop(&q);
		printf("popped: %d\n", v); // 40 50 60 70 80 90
	}
	return 0;
}

