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

void Mover(player *p, int dieNumber){
	if(IsAFK(p)){
		p->afk -= 1;
		return;
	}
	
	p->pos += dieNumber;
}

void Dormir(player *p){
	p->afk += 3;
}

void Paralisar(player *p){
	p->afk += 2;
}

int getPosicao(player *p){
	return p->pos;
}
