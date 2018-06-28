#include"../include/includes.h"

void initDStack(apontador* pilha){
	(*pilha)->anterior = NULL;
}

int emptyDStack(apontador* pilha){
	return (*pilha) == NULL;
	//true caso for nulo, false caso proximo apontar para outro lugar
}

void pushDStack(apontador* pilha, stack_item_type item){
	tipo_Noh *novo = (tipo_Noh*)malloc(sizeof(tipo_Noh));
	if(novo == NULL){ //n conseguiu alocar memoria
		printf("Memoria cheia!!\n");
	}else{
		novo->anterior = *pilha;
		novo->valor = item;
		*pilha = novo;
	}
}

int popDStack(apontador* pilha){
	if(emptyDStack(pilha)){
		printf("Pilha vazia!!");
		return 0;
	}
	tipo_Noh *remover = *pilha;
	//stack_item_type retorno = remover->valor;
	*pilha = (*pilha)->anterior;
	remover->anterior = NULL;
	free(remover);
	return 1;
}

stack_item_type topD(apontador* pilha){
	carta falhou = {.id=-1,.mov=0};
	falhou.texto = (char*)malloc(sizeof(char)*10);
	falhou.texto = "deu ruim!";

	if(emptyDStack(pilha))
		return falhou;
	return (*pilha)->valor;
}

void preencherBaralhoD(carta* baralho, apontador* s){
	preencherCartas(baralho);
	embaralha(baralho);
	short int i;
	for(i = 0; i < TAM_BARALHO; ++i){
		pushDStack(s, baralho[i]);
	}
}
