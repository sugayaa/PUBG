#include "../include/includes.h"

void Game(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer,
	 ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_EVENT *event,
	 int numberPlayers){
	//Variáveis
	int loops;
	bool exit = false;

	ALLEGRO_BITMAP *spritePlayers = al_load_bitmap("media/img/players.png");
	ALLEGRO_BITMAP *gameBackground = al_load_bitmap("media/img/game_background.png");

	player players[4];
	queue playersQueue;
	tabuleiro gameArena;

	IniciarPlayers(players);
	initQueue(&playersQueue, numberPlayers);
	Inicia(&gameArena);

	for(loops = 0; loops < numberPlayers; loops++){
		push(&playersQueue, players[loops]);
	}


	while(!exit){
		al_clear_to_color(COLOR_BLACK);
		al_draw_bitmap(gameBackground, 0, 0, 0);
		for(loops = 0; loops < numberPlayers; loops++){
			al_draw_bitmap_region(spritePlayers, players[loops].ID * 128, 0, 128, 128, WIDTH * 0.05, HEIGHT * 0.1, 0);
		}
		
		al_flip_display();

		al_wait_for_event(eventQueue, event);

		if(event->type == ALLEGRO_EVENT_KEY_DOWN){
			//ESC para SAIR
			if(event->keyboard.keycode == ALLEGRO_KEY_ESCAPE){
				exit = true;
			}

			if(event->keyboard.keycode == ALLEGRO_KEY_SPACE){
				push(&playersQueue, pop(&playersQueue));
			}
		}
		//Clicar no X para SAIR
		if(event->type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			exit = true;
		}
	}
}
