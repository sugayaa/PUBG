#ifndef TABULEIRO_H
#define TABULEIRO_H
#include "includes.h"

//fila estaticamente implementada
typedef struct tabTile{
	int nJogadores;
	char efeito;
}tabTile;

typedef struct tabuleiro{
	tabTile corpo[TAM];
	int inicio;
	int _final;
}tabuleiro;

void Limpa(tabuleiro*);
void RandomizaTabuleiro(tabuleiro*);
void Randomiza(tabuleiro*, int, int);
void Inicia(tabuleiro*);
void Armageddon(tabuleiro*);

#endif
