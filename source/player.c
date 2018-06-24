#include "../include/includes.h"

void IniciarPlayers(player *p){
	int i;
	for(i = 0; i <= 3; i++){
		p[i].ID = i;
		p[i].pos = 0;
		p[i].afk = 0;
	}
}

bool IsAFK(player *p){
	return (bool) p->afk;
}

void Mover(player *p){
	if(IsAFK(p)){
		p->afk -= 1;
		return;
	}
	srand(time(NULL));
	p->pos += (rand() % TAM_DADO) + 1;
}

void Dormir(player *p){
	p->afk += 10;
}

void Paralisar(player *p){
	p->afk += 5;
}

int getPosicao(player *p){
	return p->pos;
}
