#include "../include/includes.h"

void Game(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer,
	 ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_EVENT *event,
	 int numberPlayers){
	//Variáveis
	int loops;
	bool exit = false;

	ALLEGRO_BITMAP *spritePlayers = al_load_bitmap("media/img/players.png");

	srand(time(NULL));

	//jogadores
	player players[4];
	//fila de turnos
	queue playersQueue;
	//pilha de cartas 										<--
	stack baralho;
	//cartas 												<--
	carta monte[MAX];
	//tabuleiro
	tabuleiro gameArena;

	//'construtor' de jogadores
	IniciarPlayers(players);
	//construtor da fila de turnos, limitando tamanho
	initQueue(&playersQueue, numberPlayers);
	//construtor da pilha de cartas 						<--
	initStack(&baralho);
	//inicia tabuleiro, limpa e randomiza efeitos
	Inicia(&gameArena);
	//ler cartas disponiveis e colocar na pilha				<--
	preencherBaralho(monte, &baralho);

	//insere jogadores na fila de turnos
	for(loops = 0; loops < numberPlayers; loops++){
		push(&playersQueue, players[loops]);
	}


	while(!exit){
		al_clear_to_color(COLOR_BLACK);
		//al_draw_bitmap_region(spritePlayers, front(&playersQueue).ID * 64, 0, 64, 64, WIDTH * 0.5, HEIGHT * 0.5, 0);
		//PRINT ALL 4 Players
		int i;
		for(i = 0; i < numberPlayers; i++)
			al_draw_bitmap_region(spritePlayers, players[i].ID * 64, 0, 64, 64, getPosicao(&players[i]) + players[i].ID * 30, getPosicao(&players[i]) + 30, 0);

		//
		//printf("Vez do jogador %d !\nRole sua sorte\n", front(&playersQueue).ID+1);
		//



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
				//printf("%d\n", atual.ID); //Debugging purposes
				//player andando
				if(IsAFK(&atual)){}
					//Exibir mensagem de apertar enter para passar a vez
					//Funcao mover trata isso
				Mover(&players[atual.ID]);
				if(!IsAFK(&atual) && getEfeito(&gameArena, getPosicao(&players[atual.ID]))){
					Dormir(&players[atual.ID]);
				}
				if(players[atual.ID].pos > TAM){}
					//printf("Jogador %d ganhou o jogo!!", atual.ID + 1);
					//Exibir mensagem que jogador ganhou e terminar o jogo

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
	}
}
