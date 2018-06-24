#include"../include/includes.h"

void Limpa(tabuleiro* t){
	int i;
	for(i = 0; i < TAM; i++){
		t->corpo[i].nJogadores = 0;
		t->corpo[i].efeito = 0;
	}
}

void RandomizaTabuleiro(tabuleiro* t){
	int i;
	srand(time(NULL));
	for(i = 0; i < TAM; i++){
		if(rand()%3 == 0){
			//t->corpo[i].efeito = 65 + (rand()%3);
		t->corpo[i].efeito = 1;
		}
	}
}

void Randomiza(tabuleiro* t, int daOnde, int ateOnde){
	int i;
	srand(time(NULL));
	for(i = daOnde; i != ateOnde + 1; i = (i+1)%TAM){
		if(rand()%3 == 0){
			//t->corpo[i].efeito = 65 + (rand()%3);
			t->corpo[i].efeito = 1;
		}
	}
}

void Inicia(tabuleiro* t){
	Limpa(t);
	RandomizaTabuleiro(t);
}

char getEfeito(tabuleiro* t, int pos){
	return t->corpo[pos].efeito;
}

void Armageddon(tabuleiro* t){
	srand(time(NULL));
	int intensidade = (rand()%5) + 1;

	//verificar a partir dos players e n de todos as peças do tabuleiro
	//for i in players
	//if(player in inicio + intensidade
	//player dead
	
	t->_final = (t->_final+ intensidade) % 100;
}
