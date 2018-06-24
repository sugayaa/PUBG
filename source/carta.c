#include "../include/includes.h"

//carta baralho[TAM_BARALHO]
void preencherCartas(carta* baralho){
	FILE *cartas;
	cartas = fopen("cartas.sugaya","r");

	if(cartas != NULL){
		int i = 0;
		char texto_tmp[100];

		while(i < TAM_BARALHO && fgets(texto_tmp, 100, cartas) != NULL){
			baralho[i].id = i;
			baralho[i].texto = malloc(sizeof(char) * 100);
			strcpy(baralho[i].texto, texto_tmp);
			baralho[i].mov = fgetc(cartas);
			i += 1;
		}
	}else{
		printf("Erro ao abrir o arquivo cartas.sugaya");
	}
}

void preencherBaralho(carta* baralho, stack* s){
    preencherCartas(baralho);
	short int i;
	for(i = 0; i < TAM_BARALHO; ++i){
		pushStack(s, baralho[i]);
	}
}

int getMove(carta* c){
	return c->mov;
}

char* getTexto(carta* c){
	return c->texto;
}
