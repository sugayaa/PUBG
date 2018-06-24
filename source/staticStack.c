#include "../include/includes.h"

void initStack(stack* s){
	//memset(s->body,(stack_item_type){}, MAX);
	
	s->end = -1;
}

int pushStack(stack* s, stack_item_type item){
	if(s->end == MAX)
		return ERROR;

	s->end += 1;
	s->body[s->end] = item;
	return SUCCESS;
}

stack_item_type top(stack* s){
	carta n_dah;
	n_dah.id = 0xFFFFFFFF;
	if(!emptyStack(s))
		return s->body[s->end];
	else
		return n_dah;
}

int emptyStack(stack *s){
	return s->end == -1;
}

//Ideal scenario would be passing top as a reference
//and returning the successfulness of the pop() operation
//Or top() and then pop()
//but that's not convenient sometimes

int popStack(stack* s){
	if(emptyStack(s)){
		//printf("Empty Stack\n");
		return IMPOSSIBLE;
	}
	s->end--;
	return SUCCESS;
}

/*
int popStack(stack* s, stack_item_type* reference){
	if(emptyStack(s)){
		//printf("Empty Stack\n");
		return IMPOSSIBLE;
	}
	*reference = s->body[s->end];
	s->end--;
	return SUCCESS;
}*/

//if user instantiate a non int stack, return types will be different
/*
stack_item_type pop(stack* s){
	if(emptyStack(s)){
		//printf("Empty Stack\n");
		return IMPOSSIBLE;
	}
	s->end--;
	return s->body[s->end + 1];
}
*/

void clearStack(stack* s){
	s->end = -1;
}

void preencherBaralho(carta* baralho, stack* s){
    preencherCartas(baralho);
    embaralha(baralho);
	short int i;
	for(i = 0; i < TAM_BARALHO; ++i){
		pushStack(s, baralho[i]);
	}
}
