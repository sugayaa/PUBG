#ifndef CARTA_H
#define CARTA_H
#include "../include/includes.h"

typedef struct{
	int id;
	char* texto;
	int mov;
}carta;

//carta baralho[TAM_BARALHO]
void preencherCartas(carta*);

void embaralha(carta*);

int getMove(carta*);

char* getTexto(carta*);

#endif
