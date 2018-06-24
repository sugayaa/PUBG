#ifndef MENU_H
#define MENU_H

void Initializers();
void Intro(ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *intro, int sprites);
void FirstMenu();
void SecondMenu(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font, ALLEGRO_TIMER *timer,
				ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_EVENT *event, ALLEGRO_BITMAP *logo,
				ALLEGRO_BITMAP *menuBackground);

#endif //MENU_H