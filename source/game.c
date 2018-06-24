#include "../include/includes.h"

void Game(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer,
	 ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_EVENT *event,
	 int numberPlayers){
	//Variáveis
	int loops;
	bool exit = false;

	ALLEGRO_BITMAP *spritePlayers = al_load_bitmap("media/img/players.png");
	ALLEGRO_BITMAP *gameBackground = al_load_bitmap("media/img/game_background.png");

	srand(time(NULL));

	pair playersPositions[39];
	player players[4];
	queue playersQueue;
	tabuleiro gameArena;

	IniciarPlayers(players);
	initQueue(&playersQueue, numberPlayers);
	Inicia(&gameArena);
	setAllPosition(playersPositions);

	for(loops = 0; loops < numberPlayers; loops++){
		push(&playersQueue, players[loops]);
	}


	while(!exit){
		al_clear_to_color(COLOR_BLACK);
		al_draw_bitmap(gameBackground, 0, 0, 0);

		int i;
		for(i = 0; i < numberPlayers; i++)
			al_draw_bitmap_region(spritePlayers, players[i].ID * 128, 0, 128, 128, getPosicao(&players[i]) + players[i].ID * 30, getPosicao(&players[i]) + 30, 0);
		//
		printf("Vez do jogador %d !\nRole sua sorte\n", front(&playersQueue).ID+1);
		//


		al_flip_display();
		al_wait_for_event(eventQueue, event);

		if(event->type == ALLEGRO_EVENT_KEY_DOWN){
			//ESC para SAIR
			if(event->keyboard.keycode == ALLEGRO_KEY_ESCAPE){
				exit = true;
			}

			if(event->keyboard.keycode == ALLEGRO_KEY_SPACE){
				players[0].pos++;

				int avanco = (rand() % TAM_DADO) + 1;

				//push(&playersQueue, pop(&playersQueue));
				player atual = pop(&playersQueue);
				players[atual.ID].pos += avanco;
				if(players[atual.ID].pos >= TAM)
					printf("Jogador %d ganhou o jogo!!", atual.ID + 1);
				push(&playersQueue, players[atual.ID]);

			}
		}
		//Clicar no X para SAIR
		if(event->type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			exit = true;
		}
	}
}
