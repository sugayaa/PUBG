#ifndef STATICSTACK_H
#define STATICSTACK_H
#include "includes.h"

typedef struct stack{
	stack_item_type body[MAX];
	int end;
}stack;

void initStack(stack* s);

int pushStack(stack* s, stack_item_type item);

stack_item_type top(stack* s);

int emptyStack(stack *s);

int popStack(stack* s);

//int popStack(stack* s, item_type* reference);

void clearStack(stack* s);

void preencherBaralho(carta*, stack*);

#endif
