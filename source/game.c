#include "../include/includes.h"

void Game(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer,
	 ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_EVENT *event,
	 int numberPlayers){
	//Variáveis
	int loops;
	bool exit = false;

	ALLEGRO_FONT *font = al_load_ttf_font("media/fonts/EliteDanger.ttf", (HEIGHT * 0.1), 0);
	ALLEGRO_BITMAP *spritePlayers = al_load_bitmap("media/img/players.png");
  	ALLEGRO_BITMAP *gameBackground = al_load_bitmap("media/img/game_background.png");

	srand(time(NULL));

	//jogadores
	player players[4];
	//fila de turnos
	queue playersQueue;
	//pilha de cartas 										
	stack baralho;
	//cartas 												
	carta monte[MAX];
	//tabuleiro
	tabuleiro gameArena;
  	//lista de posições
  	pair playersPositions[39];

	//'construtor' de jogadores
	IniciarPlayers(players);
	//construtor da fila de turnos, limitando tamanho
	initQueue(&playersQueue, numberPlayers);
	//construtor da pilha de cartas 
	initStack(&baralho);
	//inicia tabuleiro, limpa e randomiza efeitos
	Inicia(&gameArena);
	//ler cartas disponiveis e colocar na pilha	
	preencherBaralho(monte, &baralho);

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

				player atual = pop(&playersQueue);

				if(IsAFK(&atual)){}
					//Exibir mensagem de apertar enter para passar a vez
					//Funcao mover trata isso
				Mover(&players[atual.ID]);
				if(!IsAFK(&atual) && getEfeito(&gameArena, getPosicao(&players[atual.ID]))){
					Dormir(&players[atual.ID]);
				}
				//Condição de Vitória
				if(players[atual.ID].pos > TAM){
					players[atual.ID].pos = 38;		//Ultima casa do Jogo
				}
				//joga jogador novamente no final da fila de turnos
				push(&playersQueue, players[atual.ID]);
			}

			if(event->keyboard.keycode == ALLEGRO_KEY_ENTER){
				printf("codigo da carta: %d\n", top(&baralho).id);
				popStack(&baralho);
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

		al_flip_display();
	}
}
