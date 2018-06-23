#ifndef STATICQUEUE_H
#define STATICQUEUE_H
#include "includes.h"

typedef struct queue{
	item_type body[MAX];
	int start, end, tam;
}queue;

void initQueue(queue*,int);

int emptyQueue(queue*);

int fullQueue(queue*);

void push(queue*, item_type);

item_type front(queue*);

item_type pop(queue*);

void clearQueue(queue*);

//void printQueue(queue*);

#endif
