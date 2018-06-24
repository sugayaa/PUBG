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
	float logoVariation = 0, logoDimension = 1.5;
	bool start = false;
	bool exit = false;
	ALLEGRO_EVENT event;

	//Leitura de Arquivos
	ALLEGRO_FONT *font = al_load_ttf_font("media/fonts/EliteDanger.ttf", (HEIGHT * 0.1), 0);
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
	ALLEGRO_DISPLAY *display = al_create_display(WIDTH, HEIGHT);
	ALLEGRO_EVENT_QUEUE *eventQueue = al_create_event_queue();

	//Caminho dos arquivos deve ser relativo ao executável (No momento, em /PUBG/PUBG.run)
	ALLEGRO_BITMAP *introOne = al_load_bitmap("media/img/intro_one.png");
	ALLEGRO_BITMAP *logo = al_load_bitmap("media/img/logo.png");
	ALLEGRO_BITMAP *menuBackground = al_load_bitmap("media/img/");

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
		al_draw_bitmap(menuBackground, 0, 0, 0);
		al_draw_scaled_bitmap(logo, 0, 0, logoWidth, logoHeight, (WIDTH * 0.5) - (logoWidth * 0.5 * logoDimension), (HEIGHT * 0.5) - (logoHeight * 0.5 * logoDimension) - logoVariation, logoWidth * logoDimension, logoHeight * logoDimension, 0);
		if(!logoVariation){
			al_draw_text(font, COLOR_BLACK, WIDTH * 0.5, HEIGHT * 0.8, ALLEGRO_ALIGN_CENTER, "Press ENTER to Play");
		}
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
			logoDimension -= 0.007;
			if(logoVariation >= (float)HEIGHT * 0.35){
				start = false;
				SecondMenu(display, font, timer, eventQueue, &event, logo, menuBackground);
				exit = true;
			}
		}
	}

	//Destruturoes
	al_destroy_font(font);
	al_destroy_bitmap(logo);
	al_destroy_display(display);
	al_destroy_event_queue(eventQueue);
}

void SecondMenu(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font, ALLEGRO_TIMER *timer,
				ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_EVENT *event, ALLEGRO_BITMAP *logo,
				ALLEGRO_BITMAP *menuBackground){

	bool exit = false;
	int option = 0;
	int logoWidth = al_get_bitmap_width(logo);
	int logoHeight = al_get_bitmap_height(logo);

	ALLEGRO_BITMAP *astronauts = al_load_bitmap("media/img/astronauts.png");
	ALLEGRO_BITMAP *light = al_load_bitmap("media/img/light.png");

	while(!exit){
		al_draw_bitmap(menuBackground, 0, 0, 0);
		al_draw_scaled_bitmap(logo, 0, 0, logoWidth, logoHeight, (WIDTH * 0.5) - (logoWidth * 0.5), (HEIGHT * 0.08) - (logoHeight * 0.15), logoWidth, logoHeight, 0);
		
		//Menu - Opções
		al_draw_text(font, COLOR_BLACK, WIDTH * 0.2, HEIGHT * 0.5, ALLEGRO_ALIGN_CENTER, "2 Players");
		al_draw_bitmap_region(astronauts, 0 * 128, 0, 128, 128, WIDTH * 0.2 - 61, HEIGHT * 0.4 - 64, 0);
		al_draw_text(font, COLOR_BLACK, WIDTH * 0.5, HEIGHT * 0.6, ALLEGRO_ALIGN_CENTER, "3 Players");
		al_draw_bitmap_region(astronauts, 1 * 128, 0, 128, 128, WIDTH * 0.5 - 61, HEIGHT * 0.5 - 64, 0);
		al_draw_text(font, COLOR_BLACK, WIDTH * 0.8, HEIGHT * 0.5, ALLEGRO_ALIGN_CENTER, "4 Players");
		al_draw_bitmap_region(astronauts, 2 * 128, 0, 128, 128, WIDTH * 0.8 - 61, HEIGHT * 0.4 - 64, 0);
		al_draw_text(font, COLOR_BLACK, WIDTH * 0.5, HEIGHT * 0.8, ALLEGRO_ALIGN_CENTER, "Options");
		al_draw_text(font, COLOR_BLACK, WIDTH * 0.5, HEIGHT * 0.9, ALLEGRO_ALIGN_CENTER, "Exit");

		switch(option){
			case 0:
				al_draw_tinted_bitmap(light, al_map_rgba(100, 100, 100, 100), WIDTH * 0.2 - 64, HEIGHT * 0.4 - 186, 0);
				break;
			case 1:
				al_draw_tinted_bitmap(light, al_map_rgba(100, 100, 100, 100), WIDTH * 0.5 - 64, HEIGHT * 0.5 - 186, 0);
				break;
			case 2:
				al_draw_tinted_bitmap(light, al_map_rgba(100, 100, 100, 100), WIDTH * 0.8 - 64, HEIGHT * 0.4 - 186, 0);
				break;
			case 3: break;
			case 4: break;
		}

		al_flip_display();
		al_wait_for_event(eventQueue, event);


		if(event->type == ALLEGRO_EVENT_KEY_DOWN){
			//ESC para SAIR
			if(event->keyboard.keycode == ALLEGRO_KEY_ESCAPE){
				exit = true;
			}

			switch(event->keyboard.keycode){
				case ALLEGRO_KEY_LEFT:
					option--; break;
				case ALLEGRO_KEY_RIGHT:
					option++; break;
			}
		}
		//Clicar no X para SAIR
		if(event->type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			exit = true;
		}
	}
};