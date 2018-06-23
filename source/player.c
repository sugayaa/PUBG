#include "../include/includes.h"

void IniciarPlayer(player *p){
	p->pos = 0;
	p->afk = 0;
	p->sprite = NULL;
}

bool IsAFK(player *p){
	return (bool) p->afk;
}

void Mover(player *p){
	if(isAFK(p)){
		afk -= 1;
		return;
	}
	srand(time(NULL));
	p->pos += (rand() % TAM_DADO) + 1;
}

void Dormir(player *p){
	p->afk += 3;
}

void Paralisar(player *p){
	p->afk += 5;
}

int getPosicao(player *p){
	return p->pos;
}
