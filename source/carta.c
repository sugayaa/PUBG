#include "../include/includes.h"

//carta baralho[TAM_BARALHO]
void preencherCartas(carta* baralho){
	FILE *carts;
	cartas = fopen("cartas.sugaya","r");

	if(cartas != NULL){
		int i = 0;
		char texto_tmp[100];
		char num_tmp;
		while(i < TAM_BARALHO && fgets(texto_tmp, 100, cartas) != NULL){
			baralho[i].id = i;
			baralho[i].texto = malloc(sizeof(char) * 100);
			strcpy(baralho[i].texto, texto_tmp);
			baralho[i].mov = atoi(fgetc(cartas));
			i += 1;
		}
	}else{
		printf("Erro ao abrir o arquivo cartas.sugaya");
	}
}

int getMove(carta* c){
	return c->mov;
}

char* getTexto(carta* c){
	return c->texto;
}
