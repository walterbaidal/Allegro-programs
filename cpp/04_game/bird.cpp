#include "mi_allegro.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>


#define SPRITESHEET "sprites/KTGicPH.png"


    int
main (int argc, char *argv[])
{

    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *title = NULL;
    ALLEGRO_BITMAP *terrain = NULL;
    ALLEGRO_BITMAP *play = NULL;
    ALLEGRO_BITMAP *ranking = NULL;
    ALLEGRO_BITMAP *footer = NULL;
    ALLEGRO_BITMAP *playstart = NULL;
    int pos_x;
    int pos_y;
   

    srand (time (NULL));
    iniciar_allegro ();
    al_install_mouse ();

    background = al_load_bitmap (SPRITESHEET);
    title = al_load_bitmap (SPRITESHEET);
    terrain = al_load_bitmap (SPRITESHEET);
    play = al_load_bitmap (SPRITESHEET);
    ranking = al_load_bitmap (SPRITESHEET);
    footer = al_load_bitmap (SPRITESHEET);
    playstart = al_load_bitmap (SPRITESHEET);




    if (!playstart)
    {
	al_show_native_message_box (display, "Error", "Error", "No se ha podido crear el bitmap del play start nigga", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	al_destroy_timer (timer);
	al_destroy_display (display);
	exit (EXIT_FAILURE);
    }

    if (!background)
    {
	al_show_native_message_box (display, "Error", "Error", "No se ha podido crear el bitmap del background", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	al_destroy_timer (timer);
	al_destroy_display (display);
	exit (EXIT_FAILURE);
    }


    if (!title)
    {
	al_show_native_message_box (display, "Error", "Error", "No se ha podido crear el bitmap del titulo", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	al_destroy_timer (timer);
	al_destroy_display (display);
	exit (EXIT_FAILURE);
    }

    if (!terrain)
    {
	al_show_native_message_box (display, "Error", "Error", "No se ha podido crear el bitmap del terreno", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	al_destroy_timer (timer);
	al_destroy_display (display);
	exit (EXIT_FAILURE);
    }
  
    if (!play)
    {
	al_show_native_message_box (display, "Error", "Error", "No se ha podido crear el bitmap del play", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	al_destroy_timer (timer);
	al_destroy_display (display);
	exit (EXIT_FAILURE);
    }

   if (!ranking)
    {
	al_show_native_message_box (display, "Error", "Error", "No se ha podido crear el bitmap del ranking", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	al_destroy_timer (timer);
	al_destroy_display (display);
	exit (EXIT_FAILURE);
    }

   if (!footer)
    {
	al_show_native_message_box (display, "Error", "Error", "No se ha podido crear el bitmap del footer", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	al_destroy_timer (timer);
	al_destroy_display (display);
	exit (EXIT_FAILURE);
    }



    while(1){
	ALLEGRO_EVENT ev;
	ALLEGRO_TIMEOUT timeout;
	al_init_timeout (&timeout, 0.00);

	bool get_event = al_wait_for_event_until (event_queue, &ev, &timeout);

	if (get_event){
	     if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		 break;
	     else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES){
	     pos_x = ev.mouse.x;
	     pos_y = ev.mouse.y;
	     }

	     if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
		 if(ev.mouse.button & 1)
                     break;
	     } 
	}
	if(redraw && al_is_event_queue_empty (event_queue))
	{
	    al_clear_to_color (al_map_rgb (0, 0, 0));
	    al_draw_bitmap_region(background, 0, 0, 288, 512, 0, 0, 0); 
	    al_draw_bitmap_region(title, 702, 182, 178, 48, 50, 110, 0);            
	    al_draw_bitmap_region(terrain, 584, 0 , 288, 112 , 0, 400, 0);

	 
		al_draw_bitmap_region(playstart, 709, 314, 104, 56, 30, 344, 0); 	    
	    
	    
                al_draw_bitmap_region(play, 708, 235, 104, 56, 30, 344, 0);
	  
    
	    al_draw_bitmap_region(ranking, 829, 235, 104, 56,  150, 344, 0);
	    al_draw_bitmap_region(footer, 885, 182, 140, 20, 80, 418, 0);

	    al_flip_display();
	    redraw = false;
	}

    }

    
    al_destroy_bitmap (background);
    al_destroy_bitmap (title);
    al_destroy_bitmap (terrain);
    al_destroy_bitmap (play);
    al_destroy_bitmap (playstart);
    al_destroy_bitmap (ranking);
    al_destroy_bitmap (footer);
    destruir_allegro ();

    return 0;
}    
