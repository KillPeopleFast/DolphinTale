#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include<iostream>
using namespace std;



class Brick {
public:
	Brick();
	void initBrick(int x, int y, int w, int h);
	void draw();
	bool isDead();
	void killBrick();
	int BrickCollision(int bouncer_x, int bouncer_y);
private:
	int xCoordinate;
	int yCoordinate;
	int width;
	int height;
	bool Dead;
};


int collision(int b1x, int b1y, int b1w, int b1h, int b2x, int b2y, int b2w, int b2h);
int main(int argc, char **argv)
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *square = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;


	//here's the bouncer's x and y coordinates on the screen, initally set to 30,30
	float bouncer_x = 250;
	float bouncer_y = 230;
	float bouncer_h = 32;
	float bouncer_w = 32;
	//here's the bouncer's x and y directions, initially set to -4, 4
	float bouncer_dx = -4.0, bouncer_dy = 4.0;



	//these two variables hold the x and y positions of the square
	//initalize these variables to where you want your square to start
	float square_x = 300;
	float square_y = 440;
	float square_h = 20;
	float square_w = 110;


	//here's our key states. they're all starting as "false" because nothing has been pressed yet.
	//the first slot represents "up", then "down", "left" and "right"
	bool key[4] = { false, false };

	//don't redraw until an event happens
	bool redraw = true;

	//this controls our game loop
	bool doexit = false;

	al_init();
	al_init_primitives_addon();

	//get the keyboard ready to use
	al_install_keyboard();

	//set the timer so it "ticks" at 2 milliseconds
	timer = al_create_timer(.02);


	//create a little 32x32 square
	bouncer = al_create_bitmap(32, 32);

	//use this to *draw* your own bitmaps (instead of loading them from a file)
	//before we used al_load_bitmap()
	al_set_target_bitmap(bouncer);

	//set the color of your bitmap
	al_clear_to_color(al_map_rgb(255, 100, 100));

	display = al_create_display(640, 480);

	square = al_create_bitmap(110, 20);

	al_set_target_bitmap(square);

	al_clear_to_color(al_map_rgb(255, 255, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	//these lines tell teh event source what to look for
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	//new! tell the event queue that it should take keyboard events, too 
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);


	Brick b1;
	b1.initBrick(2, 0, 75, 35);

	Brick b2;
	b2.initBrick(80, 0, 75, 35);

	Brick b3;
	b3.initBrick(160, 0, 75, 35);

	Brick b4;
	b4.initBrick(240, 0, 75, 35);

	Brick b5;
	b5.initBrick(320, 0, 75, 35);

	Brick b6;
	b6.initBrick(400, 0, 75, 35);

	Brick b7;
	b7.initBrick(480, 0, 75, 35);

	Brick b8;
	b8.initBrick(560, 0, 75, 35);
	//////////////////////////row 2
	Brick b9;
	b9.initBrick(5, 45, 75, 35);

	Brick b10;
	b10.initBrick(85, 45, 75, 35);

	Brick b11;
	b11.initBrick(165, 45, 75, 35);

	Brick b12;
	b12.initBrick(245, 45, 75, 35);

	Brick b13;
	b13.initBrick(325, 45, 75, 35);

	Brick b14;
	b14.initBrick(405, 45, 75, 35);

	Brick b15;
	b15.initBrick(485, 45, 75, 35);

	Brick b16;
	b16.initBrick(565, 45, 75, 35);

	//////////////////row 3
	//Brick b17;
	//b9.initBrick(5, 90, 75, 35);
/*
	Brick b18;
	b10.initBrick(85, 45, 75, 35);

	Brick b19;
	b11.initBrick(165, 45, 75, 35);

	Brick b20;
	b12.initBrick(245, 45, 75, 35);

	Brick b21;
	b13.initBrick(325, 45, 75, 35);

	Brick b22;
	b14.initBrick(405, 45, 75, 35);

	Brick b23;
	b15.initBrick(485, 45, 75, 35);

	Brick b24;
	b16.initBrick(565, 45, 75, 35);
	*/










	//so the game loop is set to act on "ticks" of the timer OR keyboard presses 
	//OR the mouse closing the display
	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		/////////////////////////square////////////////////////////////////////////////////////////////////////
		//here's the movement algorithm

		if (ev.type == ALLEGRO_EVENT_TIMER) {

			//if the left button is pressed AND we're still right of the left wall
			//move the box left by 4 pixels
			if (key[2] && square_x >= 0) {
				square_x -= 4.0;
			}

			//if the left button is pressed AND we're still left of the right wall
			//move the box right by 4 pixels
			if (key[3] && square_x <= 640 - 32) {
				square_x += 4.0;
			}

			/////////////////////bouncer here///////////////////////////
			//if the box hits the left wall OR the right wall
			if (bouncer_x < 0 || bouncer_x > 640 - 32) {
				//flip the x direction
				bouncer_dy = -bouncer_dy;
			}
			//if the box hits the top wall OR the bottom wall
			if (bouncer_y < 0 || bouncer_y > 480 - 32) {
				//flip the y direction
				bouncer_dx = -bouncer_dx;
			}

			//really important code!
			//move the box in a diagonal
			bouncer_x += bouncer_dx;
			bouncer_y += bouncer_dy;


			if (collision(square_x, square_y, square_w, square_h, bouncer_x, bouncer_y, bouncer_w, bouncer_h) == 1) {
				bouncer_dx = -bouncer_dx;

			}
			if (b1.BrickCollision(bouncer_x, bouncer_y) && b1.isDead() == false) {
				b1.killBrick();
				bouncer_dy = -bouncer_dy;
			}
				//redraw at every tick of the timer
				redraw = true;
		}

		///////////////////////////////////////////////////////////////////////////////////////////////////////
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////
		//here's the algorithm that turns key presses into events
		//a "key down" event is when a key is pushed
		//while a "key up" event is when a key is released

		//has something been pressed on the keyboard?
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {

			//"keycode" holds all the different keys on the keyboard
			switch (ev.keyboard.keycode) {

				//if the left key has been pressed
			case ALLEGRO_KEY_LEFT:
				key[2] = true;
				break;

				//if the right key has been pressed
			case ALLEGRO_KEY_RIGHT:
				key[3] = true;
				break;
			}
		}
		//has something been released on the keyboard?
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {

			case ALLEGRO_KEY_LEFT:
				key[2] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[3] = false;
				break;

				//kill the program if someone presses escape
			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}


		//RENDER SECTION
		//if the clock ticked but no other events happened, don't bother redrawing
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			//paint black over the old screen, so the old square dissapears
			al_clear_to_color(al_map_rgb(0, 0, 0));

			//Draw Bricks
			if (b1.isDead()== false)
				b1.draw();
			b2.draw();
			b3.draw();
			b4.draw();
			b5.draw();
			b6.draw();
			b7.draw();
			b8.draw();
			b9.draw();
			b10.draw();
			b11.draw();
			b12.draw();
			b13.draw();
			b14.draw();
			b15.draw();
			b16.draw();

			//b17.draw();
			/*b18.draw();
			b19.draw();
			b20.draw();
*/
//the algorithm above just changes the x and y coordinates
//here's where the bitmap is actually drawn somewhere else
			al_draw_bitmap(square, square_x, square_y, 0);
			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);
			al_flip_display();
		}
	}
	al_destroy_bitmap(bouncer);
	al_destroy_bitmap(square);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}
int collision(int b1x, int b1y, int b1w, int b1h, int b2x, int b2y, int b2w, int b2h) {

	if ((b1x > b2x + b2w) || //is box1 to the right of box2
		(b1x + b1w < b2x) || //is box1 to the LEFT of box2
		(b1y > b2y + b2h) || //is box1 below box2
		(b1y + b1h < b2y)) //is box1 above box2
		return 0;

	else {
		cout << "collision!";
		return 1;
	}

}
Brick::Brick() {
	xCoordinate = 0;
	yCoordinate = 0;
	width = 0;
	height = 0;
	Dead = 0;

}
int Brick::BrickCollision(int bouncer_x, int bouncer_y) {
	if ((xCoordinate > bouncer_x + 32) ||
		(xCoordinate + width < bouncer_x) ||
		(yCoordinate > bouncer_y + 32) ||
		(yCoordinate + height < bouncer_y))
	{
		return 0;
	}
	else
		return 1;
}
void Brick::initBrick(int x, int y, int w, int h) {
	xCoordinate = x;
	yCoordinate = y;
	width = w;
	height = h;
	Dead = 0;

}

void Brick::draw() {
	al_draw_filled_rectangle(xCoordinate, yCoordinate, xCoordinate + width, yCoordinate + height, al_map_rgb(100, 0, 0));
}

bool Brick::isDead() {
	return Dead;
}

void Brick::killBrick() {
	Dead = true;
}
