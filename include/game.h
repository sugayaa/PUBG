#ifndef GAME_H
#define GAME_H

void Game(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer,
	 	  ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_EVENT *event,
	 	  int numberPlayers);
void TheEnd(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer,
	 		ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_EVENT *event, int ID);

#endif	//GAME_H