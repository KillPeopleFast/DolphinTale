#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <ctime>

//declaration
void rect();


int main() {
	srand(time(NULL));//sets up rand()
	al_init();
	al_init_primitives_addon();

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	timer = al_create_timer(.2);

	display = al_create_display(800, 800);
	event_queue = al_create_event_queue();

	//these lines tell teh event source what to look for


	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_clear_to_color(al_map_rgb(10, 50, 70));
	bool redraw = true;

	al_start_timer(timer);
	while (1)//game loop
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);


		if (ev.type == ALLEGRO_EVENT_TIMER) {


			//redraw at every tick of the timer
			redraw = true;
		}

		//if the clock ticked but no other events happened, don't bother redrawing
		if (redraw) {
			redraw = false;
			rect();

			al_flip_display();
		}
	}

	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
}

void rect() {//definition

	int x = rand() % 900 + 1;
	int y = rand() % 900 + 1;
	int z = rand() % 900 + 1;
	al_draw_rectangle(y, z, x, y, al_map_rgb(y, x, z), x);
}
