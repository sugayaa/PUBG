#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H
#include"includes.h"

struct tipo_Noh{
	stack_item_type valor;
	apontador anterior;
};

void initDStack(apontador* pilha);

bool emptyDStack(apontador* pilha);

void pushDStack(apontador* pilha, stack_item_type item);

int popDStack(apontador* pilha);

stack_item_type topD(apontador* pilha);

void preencherBaralhoD(carta* baralho, apontador* s);

#endif

