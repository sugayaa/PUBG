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
#define WIDTH 1280
#define HEIGHT 720
#define GAME_TITLE "PUBG - Planet Ultimate Board Game"

//Bibliotecas Próprias
#include "menu.h"
#include "tabuleiro.h"

//Cores
#define COLOR_RED al_map_rgb(255,0,0)
#define COLOR_BLACK al_map_rgb(0,0,0)
#define COLOR_GREEN al_map_rgb(0,255,0)
#define COLOR_BLUE al_map_rgb(0, 0, 255)
#define COLOR_WHITE al_map_rgb(255,255,255)

#endif  //INCLUDES_H
