#ifndef __PAJARO_H_
#define __PAJARO_H_

#include <allegro5/allegro.h>

 class Pajaro
{
    private:
	double x;
	double y;
	double vx;
	double vy;

	ALLEGRO_BITMAP *dibujo;

    public:
	Pajaro();
	double get_x ();
	double get_y ();
	
	void actualizate ();
	ALLEGRO_BITMAP *get_dibujo ();
	void set_dibujo (ALLEGRO_BITMAP *sprite);
};
#endif

