#include "../include/includes.h"

void Game(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer,
		ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_EVENT *event,
		int numberPlayers){
	//Variáveis
	int loops, count, dieNumber = 0;
	bool exit = false, movimentation = false, readCard = false;
	char texto[2][53];
	player atual;
	atual.ID = -1;

	ALLEGRO_FONT *font = al_load_ttf_font("media/fonts/EliteDanger.ttf", (HEIGHT * 0.08), 0);
	ALLEGRO_FONT *fontHalf = al_load_ttf_font("media/fonts/EliteDanger.ttf", (HEIGHT * 0.06), 0);
	ALLEGRO_BITMAP *spritePlayers = al_load_bitmap("media/img/players.png");
	ALLEGRO_BITMAP *gameBackground = al_load_bitmap("media/img/game_background.png");

	srand(time(NULL));

	//jogadores
	player players[4];
	//fila de turnos
	queue playersQueue;
	//pilha de cartas
	//stack baralho;
	//pilha dinamica de cartas;
	apontador baralhoDinamico;
	//cartas
	//carta monte[MAX];
	carta monte[TAM_BARALHO];
	//tabuleiro
	tabuleiro gameArena;
	//lista de posições
	pair playersPositions[39];

	//'construtor' de jogadores
	IniciarPlayers(players);
	//construtor da fila de turnos, limitando tamanho
	initQueue(&playersQueue, numberPlayers);
	//construtor da pilha de cartas
	//initStack(&baralho);
	//construtor de pilha dinamica de cartas
	initDStack(&baralhoDinamico);
	//inicia tabuleiro, limpa e randomiza efeitos
	Inicia(&gameArena);
	//ler cartas disponiveis e colocar na pilha	
	preencherBaralho(monte, &baralho);
	//ler cartas disponiveis e colocar na pilha dinamica
	preencherBaralhoD(monte,&baralhoDinamico);

	//insere jogadores na fila de turnos
	for(loops = 0; loops < numberPlayers; loops++){
		push(&playersQueue, players[loops]);
	}

	//Adiciona as posições do tabuleiro na lista
	setAllPosition(playersPositions);

	while(!exit){
		al_wait_for_event(eventQueue, event);

		if(event->type == ALLEGRO_EVENT_KEY_DOWN){
			//ESC para SAIR
			if(event->keyboard.keycode == ALLEGRO_KEY_ESCAPE){
				exit = true;
			}

			if(event->keyboard.keycode == ALLEGRO_KEY_SPACE){
				if(!movimentation){
					movimentation = true;
					atual = pop(&playersQueue);

					if(IsAFK(&atual)){}
					//Exibir mensagem de apertar enter para passar a vez
					dieNumber = (rand() % TAM_DADO) + 1;

					if(!IsAFK(&atual) && getEfeito(&gameArena, getPosicao(&players[atual.ID]))){
						//Dormir(&players[atual.ID]);
						readCard=true;
					}

					//joga jogador novamente no final da fila de turnos
					push(&playersQueue, players[atual.ID]);
				}
			}
		}
		//Clicar no X para SAIR
		if(event->type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			exit = true;
		}

		al_draw_bitmap(gameBackground, 0, 0, 0);

		switch(numberPlayers){
			case 4:
				al_draw_bitmap_region(spritePlayers, 3 * 128, 0, 128, 128, playersPositions[getPosicao(&players[3])].x, playersPositions[getPosicao(&players[3])].y, 0);
			case 3:
				al_draw_bitmap_region(spritePlayers, 2 * 128, 0, 128, 128, playersPositions[getPosicao(&players[2])].x + 50, playersPositions[getPosicao(&players[2])].y, 0);
			case 2:
				al_draw_bitmap_region(spritePlayers, 1 * 128, 0, 128, 128, playersPositions[getPosicao(&players[1])].x + 25, playersPositions[getPosicao(&players[1])].y + 30, 0);
				al_draw_bitmap_region(spritePlayers, 0 * 128, 0, 128, 128, playersPositions[getPosicao(&players[0])].x + 75, playersPositions[getPosicao(&players[0])].y + 30, 0);
				break;
		}

		if(movimentation){
			al_draw_textf(font, COLOR_WHITE, WIDTH * 0.45, HEIGHT * 0.85, 0, "O Jogador %d rolou %d no dado!", atual.ID + 1, dieNumber);
			al_flip_display();
			al_rest(1.5);
			Mover(&players[atual.ID], dieNumber);
			//Condição de Vitória
			if(players[atual.ID].pos >= TAM){
				players[atual.ID].pos = 38;		//Ultima casa do Jogo
				TheEnd(display, timer, eventQueue, event, players[atual.ID].ID + 1);
				al_destroy_font(font);
				al_destroy_bitmap(spritePlayers);
				al_destroy_bitmap(gameBackground);
				return ;
			}
			movimentation = false;
		} else if(readCard){
			//if(!emptyStack(&baralho)){
			if(emptyDStack(&baralhoDinamico)){
				printf("Sem cartas no baralho!\n");
				preencherBaralhoD(monte,&baralhoDinamico);
			}
			if(!emptyDStack(&baralhoDinamico)){
				al_draw_filled_rectangle(0, HEIGHT * 0.4, WIDTH, HEIGHT * 0.6, COLOR_BLACK);
				//if(strlen(top(&baralho).texto) <= 50){
				if(strlen(topD(&baralhoDinamico).texto) < 60){
					al_draw_textf(fontHalf, COLOR_WHITE, WIDTH * 0.5, HEIGHT * 0.455, ALLEGRO_ALIGN_CENTER, "%s", topD(&baralhoDinamico).texto);
				}else{
					for(loops = 0; loops < 52; loops++){
						texto[0][loops] = topD(&baralhoDinamico).texto[loops];
					}
					for(loops = 52, count = 0; loops <= strlen(topD(&baralhoDinamico).texto); loops++, count++){
						texto[1][count] = topD(&baralhoDinamico).texto[loops];
					}
					al_draw_textf(fontHalf, COLOR_WHITE, WIDTH * 0.5, HEIGHT * 0.42, ALLEGRO_ALIGN_CENTER, "%s", texto[0]);
					al_draw_textf(fontHalf, COLOR_WHITE, WIDTH * 0.5, HEIGHT * 0.49, ALLEGRO_ALIGN_CENTER, "%s", texto[1]);
				}

				al_flip_display();
				al_rest(3);
				al_flip_display();
				al_wait_for_event(eventQueue, event);
				readCard = false;
				//if(top(&baralho).mov != 0){
				if(topD(&baralhoDinamico).mov != 0){
					//Mover(&players[atual.ID], top(&baralho).mov);
					Mover(&players[atual.ID], topD(&baralhoDinamico).mov);
					if(players[atual.ID].pos >= TAM){
						players[atual.ID].pos = 38;		//Ultima casa do Jogo
						TheEnd(display, timer, eventQueue, event, players[atual.ID].ID + 1);
						al_destroy_font(font);
						al_destroy_bitmap(spritePlayers);
						al_destroy_bitmap(gameBackground);
						return ;
					}
					//Retornar o máximo pra primeira casa do jogo
					if(players[atual.ID].pos < 0){
						players[atual.ID].pos = 0;
					}
				} else {
					Paralisar(&players[atual.ID]);
				}
				//popStack(&baralho);
				popDStack(&baralhoDinamico);
			}
		}else{
			al_draw_textf(font, COLOR_WHITE, WIDTH * 0.45, HEIGHT * 0.85, 0, "Agora é a vez do Jogador %d", ((atual.ID + 1) % numberPlayers) +1);
		}

		al_flip_display();
	}
}

void TheEnd(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer,
		ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_EVENT *event, int ID){

	bool exit = false;

	ALLEGRO_FONT *font = al_load_ttf_font("media/fonts/EliteDanger.ttf", (HEIGHT * 0.15), 0);
	ALLEGRO_BITMAP *background = al_load_bitmap("media/img/PUBG_menu.png");
	ALLEGRO_BITMAP *victory = al_load_bitmap("media/img/victory_players.png");

	while(!exit){
		al_wait_for_event(eventQueue, event);

		if(event->type == ALLEGRO_EVENT_KEY_DOWN){
			//ESC para SAIR
			if(event->keyboard.keycode == ALLEGRO_KEY_ESCAPE){
				exit = true;
			}
			//ENTER para SAIR também
			if(event->keyboard.keycode == ALLEGRO_KEY_ENTER){
				exit = true;
			}
		}
		//Clicar no X para SAIR
		if(event->type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			exit = true;
		}

		al_draw_tinted_bitmap(background, al_map_rgba(75, 75, 75, 255), 0, 0, 0);
		al_draw_bitmap_region(victory, (ID - 1) * 600, 0, 600, 600, WIDTH * 0.5 - 300, HEIGHT - 600, 0);
		al_draw_textf(font, COLOR_WHITE, WIDTH * 0.5, HEIGHT * 0.05, ALLEGRO_ALIGN_CENTER, "O JOGADOR %d VENCEU!!", ID);
		al_flip_display();
	}

	al_destroy_font(font);
	al_destroy_bitmap(background);
	al_destroy_bitmap(victory);
	return ;
}
