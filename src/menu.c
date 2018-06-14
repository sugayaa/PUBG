#include "../include/includes.h"

void Initializers(){
	al_init();
	al_init_ttf_addon();
	al_init_font_addon();
	al_init_image_addon();
	al_init_acodec_addon();
	al_init_primitives_addon();
	al_install_audio();
	al_install_keyboard();
}