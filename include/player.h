#ifndef PLAYER_H
#define PLAYER_H

typedef struct p{
	int pos;
	int afk;
	allegro_bitmap* sprite;
}player;

void IniciarPlayer(player*);

bool IsAFK(player*);

void Mover(player*);

void Dormir(player*);

void Paralisar(player*);

int getPosicao(player*);

#endif
