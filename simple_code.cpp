#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "actor.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int WIDTH 			= 800;
int HEIGHT 			= 600;
const int fps		= 60;
enum 				KEYS{};
bool 				done 				= false,
					isGame 				= false,
					pause				= false;
					
ALLEGRO_DISPLAY		*display			= NULL;
ALLEGRO_EVENT_QUEUE	*event_queue		= NULL;
ALLEGRO_TIMER		*timer				= NULL;
ALLEGRO_BITMAP		*image				= NULL;

PLAYER	player;

void init()
{
	fprintf(stderr, "Init\n");
//	pause 						= true;
	
	player.x = WIDTH / 2;
	player.y = HEIGHT - 70;
	player.life = 3;
	player.tileX = 0;
	player.tileY = 0;
	player.w = 32;
	player.h = 64;
	
	al_init();
	al_init_image_addon();
	al_install_keyboard();
	al_init_primitives_addon();
	display 					= al_create_display(WIDTH, HEIGHT);
	event_queue					= al_create_event_queue();
	timer						= al_create_timer(1.0 / fps);
	
	image						= al_load_bitmap("data/image.png");
	
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	
	al_start_timer(timer);
	
	fprintf(stderr, "Game Init\n");
}

void renderGame()
{
	
}

void renderPause()
{
	
}

void gameLoop()
{
	while(!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		
		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
		/*	switch(ev.keyboard.keycode)
			{
				case ALLEGRO_KEY_ESCAPE:
					if(!pause)
						pause = true;
					else
						pause = false;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = true;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = true;
					break;
				case ALLEGRO_KEY_SPACE:
					keys[SPACE] = true;
					break;
				case ALLEGRO_KEY_LCTRL:
					keys[LCTRL] = true;
					break;
				case ALLEGRO_KEY_UP:
						keys[UP] = true;
					break;
				case ALLEGRO_KEY_DOWN:
						keys[DOWN] = true;
					break;
				case ALLEGRO_KEY_ENTER:
						keys[ENTER] = true;
					break;
				case ALLEGRO_KEY_Q:
					done = true;
			}*/
		/*	switch(ev.keyboard.keycode)
			{
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = true;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = true;
					break;
				case ALLEGRO_KEY_Q:
					done = true;
			}*/
		} else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
		/*	switch(ev.keyboard.keycode)
			{
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = false;
					break;
			}*/
		/*	switch(ev.keyboard.keycode)
			{
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = false;
					if(changeMenu && pause) changeMenu = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = false;
					if(changeMenu && pause) changeMenu = false;
					break;
				case ALLEGRO_KEY_LCTRL:
					keys[LCTRL] = false;
					break;
				case ALLEGRO_KEY_SPACE:
					keys[SPACE] = false;
					break;
				case ALLEGRO_KEY_UP:
					keys[UP] = false;
					if(changeMenu && pause) changeMenu = false;
					break;
				case ALLEGRO_KEY_DOWN:
					keys[DOWN] = false;
					if(changeMenu && pause) changeMenu = false;
					break;
				case ALLEGRO_KEY_ENTER:
					keys[ENTER] = false;
					if(changeMenu && pause) changeMenu = false;
					break;
			}*/
		} else if(ev.type == ALLEGRO_EVENT_TIMER && !pause)
		{
			
		}else if(ev.type == ALLEGRO_EVENT_TIMER && pause)
		{
		}
		renderGame();
		al_flip_display();
	}
}

void destroy()
{
	
}

int main(int argc, char *argv[])
{
	init();
	gameLoop();
	destroy();
//	system("pause");
}