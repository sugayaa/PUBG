#include "../include/includes.h"

//carta baralho[TAM_BARALHO]
void preencherCartas(carta* baralho){
	FILE *cartas;
	cartas = fopen("include/cartas.sugaya","r");

	if(cartas == NULL){
		printf("Erro ao abrir o arquivo cartas.sugaya");
	}else{
		int i = 0;
		char texto_tmp[100];

		while(i < TAM_BARALHO && fgets(texto_tmp, 100, cartas) != NULL){
			baralho[i].id = i;
			baralho[i].texto = malloc(sizeof(char) * 100);
			strcpy(baralho[i].texto, texto_tmp);
			baralho[i].mov = fgetc(cartas);
			i += 1;
		}
	}
}

void embaralha(carta* baralho){
	int i, idx1, idx2;
	carta tmp;
	srand(time(NULL));
	for(i = 0; i < TAM_BARALHO; i++){
		idx1 = rand()%TAM_BARALHO;
		idx2 = rand()%TAM_BARALHO;
		if(idx1 == idx2)
			continue;
		tmp = baralho[idx1];
		baralho[idx1] = baralho[idx2];
		baralho[idx2] = tmp;
	}
}

int getMove(carta* c){
	return c->mov;
}

char* getTexto(carta* c){
	return c->texto;
}
