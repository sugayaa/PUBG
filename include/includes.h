#ifndef INCLUDES_H
#define INCLUDES_H

//Bibliotecas Padrões
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Bibliotecas Allegro5
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>

//Constantes
#define FPS 30
#define TAM 100
#define TAM_DADO 20
#define WIDTH 1280
#define HEIGHT 720
#define GAME_TITLE "PUBG - Planet Ultimate Board Game"

//Definições para pilha
#define stack_item_type carta
#define SUCCESS 1
#define ERROR -1
#define IMPOSSIBLE 0xFFFFFFFF;
#define MAX 20

//Definições tipo carta
#define TAM_BARALHO 5

//Definições para pilha
#define item_type player

//Bibliotecas Próprias
#include "menu.h"
#include "tabuleiro.h"
#include "player.h"
#include "staticQueue.h"
#include "carta.h"
#include "staticStack.h"

//Cores
#define COLOR_RED al_map_rgb(255,0,0)
#define COLOR_BLACK al_map_rgb(0,0,0)
#define COLOR_GREEN al_map_rgb(0,255,0)
#define COLOR_BLUE al_map_rgb(0, 0, 255)
#define COLOR_WHITE al_map_rgb(255,255,255)

#endif  //INCLUDES_H
