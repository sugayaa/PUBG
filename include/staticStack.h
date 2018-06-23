#ifndef STATICSTACK_H
#define STATICSTACK_H
#include "includes.h"

typedef struct stack{
	item_type body[MAX];
	int end;
}stack;

void init(stack* s);

int pushStack(stack* s, item_type item);

item_type top(stack* s);

int emptyStack(stack *s);

int popStack(stack* s);

//int popStack(stack* s, item_type* reference);

void clearStack(stack* s);

#endif
