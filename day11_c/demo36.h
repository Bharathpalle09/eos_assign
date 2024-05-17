#ifndef _DEMO36_H
#define _DEMO36_H

#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>

#define MQ_KEY 0x1909

typedef struct {
long type;
char str[32];
}msg_t;

#endif
