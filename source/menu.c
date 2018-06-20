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

void Intro(ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *intro, int sprites){
	int currentSprite, introWidth, introHeight, alpha;

	introWidth = al_get_bitmap_width(intro) / sprites;
	introHeight = al_get_bitmap_height(intro);

	for(currentSprite = 0; currentSprite <= sprites - 1; currentSprite++){
		if(!currentSprite){
			for(alpha = 0; alpha <= 195; alpha += 15){
				al_draw_tinted_bitmap_region(intro, al_map_rgba(alpha, alpha, alpha, alpha), (currentSprite % sprites) * introWidth, 0, introWidth, introHeight, WIDTH * 0.5 - introWidth * 0.5, HEIGHT * 0.5 - introHeight * 0.5, 0);
				al_flip_display();
				al_rest(0.1);
			}
		}

		al_draw_bitmap_region(intro, (currentSprite % sprites) * introWidth, 0, introWidth, introHeight, WIDTH * 0.5 - introWidth * 0.5, HEIGHT * 0.5 - introHeight * 0.5, 0);
		al_flip_display();
		al_rest(0.25);

		if(currentSprite == sprites - 1){
			for(alpha = 195; alpha >= 0; alpha -= 15){
				al_clear_to_color(COLOR_BLACK);
				al_draw_tinted_bitmap_region(intro, al_map_rgba(alpha, alpha, alpha, alpha), (currentSprite % sprites) * introWidth, 0, introWidth, introHeight, WIDTH * 0.5 - introWidth * 0.5, HEIGHT * 0.5 - introHeight * 0.5, 0);
				al_flip_display();
				al_rest(0.1);
			}
		}
	}
	al_clear_to_color(COLOR_BLACK);
	al_destroy_bitmap(intro);
}

void FirstMenu(){

	//Variaveis
	int logoWidth, logoHeight;
	float logoVariation = 0;
	bool start = false;
	bool exit = false;
	ALLEGRO_EVENT event;

	//Leitura de Arquivos
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
	ALLEGRO_DISPLAY *display = al_create_display(WIDTH, HEIGHT);
	ALLEGRO_EVENT_QUEUE *eventQueue = al_create_event_queue();

	//Caminho dos arquivos deve ser relativo ao executável (No momento, em /PUBG/PUBG.run)
	ALLEGRO_BITMAP *introOne = al_load_bitmap("media/img/intro_one.png");
	ALLEGRO_BITMAP *logo = al_load_bitmap("media/img/logo.png");

	logoWidth = al_get_bitmap_width(logo);
	logoHeight = al_get_bitmap_height(logo);

	//Configurações Internas
	al_set_window_title(display, GAME_TITLE);
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));

	al_start_timer(timer);

	Intro(display, introOne, 12);

	while(!exit){
		al_clear_to_color(COLOR_WHITE);
		al_draw_scaled_bitmap(logo, 0, 0, logoWidth, logoHeight, (WIDTH * 0.5) - (logoWidth * RATIO * 0.5), (HEIGHT * 0.5) - (logoHeight * RATIO * 0.5) - logoVariation, logoWidth * RATIO, logoHeight * RATIO, 0);
		al_flip_display();
		al_wait_for_event(eventQueue, &event);

		if(event.type == ALLEGRO_EVENT_KEY_DOWN){
			//ESC para SAIR
			if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
				exit = true;
			}
			//ENTER para INICIAR
			if(event.keyboard.keycode == ALLEGRO_KEY_ENTER){
				start = true;
			}
		}
		//Clicar no X para SAIR
		if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			exit = true;
		}

		if(start){
			logoVariation += (float)HEIGHT * 0.005;
			if(logoVariation >= (float)HEIGHT * 0.35){
				start = false;
			}
		}
	}

	//Destruturoes
	al_destroy_display(display);
	al_destroy_event_queue(eventQueue);
}