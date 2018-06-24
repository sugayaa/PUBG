#ifndef PAIR_H
#define PAIR_H

#include "includes.h"

typedef struct{
	int x;
	int y;
}pair;

void setPos(pair*, int, int);
void setAllPosition(pair *p);

#endif
