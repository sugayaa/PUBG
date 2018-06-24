#include "../include/includes.h"

void Game(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer,
	 ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_EVENT *event,
	 int numberPlayers){
	//Variáveis
	int loops;
	bool exit = false;

	ALLEGRO_BITMAP *spritePlayers = al_load_bitmap("media/img/players.png");

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
		//al_draw_bitmap_region(spritePlayers, front(&playersQueue).ID * 64, 0, 64, 64, WIDTH * 0.5, HEIGHT * 0.5, 0);
		//PRINT ALL 4 Players
		int i;
		for(i = 0; i < numberPlayers; i++)
			al_draw_bitmap_region(spritePlayers, players[i].ID * 64, 0, 64, 64, getPosicao(&players[i]) + players[i].ID*30, getPosicao(&players[i]) + 30, 0);

		
		al_flip_display();

		al_wait_for_event(eventQueue, event);

		if(event->type == ALLEGRO_EVENT_KEY_DOWN){
			//ESC para SAIR
			if(event->keyboard.keycode == ALLEGRO_KEY_ESCAPE){
				exit = true;
			}

			if(event->keyboard.keycode == ALLEGRO_KEY_SPACE){
				//push(&playersQueue, pop(&playersQueue));
				player atual = pop(&playersQueue);
				players[atual.ID].pos += 100;
				push(&playersQueue, players[atual.ID]);
			}
		}
		//Clicar no X para SAIR
		if(event->type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			exit = true;
		}
	}
}
