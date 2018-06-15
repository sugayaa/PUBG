#include "../include/includes.h"

void Initializers(){
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();
	al_init_acodec_addon();
	al_init_primitives_addon();
	al_install_audio();
	al_install_keyboard();
}

void FirstMenu(){
	//Variaveis
	bool exit = false;
	ALLEGRO_EVENT event;

	//Leitura de Arquivos
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
	ALLEGRO_DISPLAY *display = al_create_display(WIDTH, HEIGHT);
	ALLEGRO_EVENT_QUEUE *eventQueue = al_create_event_queue();


	al_set_window_title(display, GAME_TITLE);
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));

	al_start_timer(timer);

	while(!exit){
		al_flip_display();
		al_wait_for_event(eventQueue, &event);

		if(event.type == ALLEGRO_EVENT_KEY_DOWN){
			//ESC para SAIR
			if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
				exit = true;
			}
		}
		//Clicar no X para SAIR
		if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			exit = true;
		}
	}

	//Destruturoes
	al_destroy_display(display);
	al_destroy_event_queue(eventQueue);
}