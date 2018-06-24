#ifndef PLAYER_H
#define PLAYER_H

typedef struct p{
	int ID;
	int pos;
	int afk;
}player;

void IniciarPlayers(player*);

bool IsAFK(player*);

void Mover(player*);

void Dormir(player*);

void Paralisar(player*);

int getPosicao(player*);

#endif
