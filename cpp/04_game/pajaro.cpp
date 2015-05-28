#include <stdlib.h>
#include "pajaro.h"

#define ROZAMIENTO 0.0625

Pajaro::Pajaro ()
{
    this->x = 100;
    this->y = 100;
    this->vx = 0;
    this->vy = 0;
    this->dibujo = NULL;
}


double
Pajaro::get_x()
{
    return this->x;
}

double Pajaro::get_y()
{
    return this->y;
}

ALLEGRO_BITMAP *
Pajaro::get_dibujo ()
{
    return this->dibujo;
}

void
Pajaro::actualizate()
{
    this->vx -= ROZAMIENTO * this->vx;
    this->vy -= ROZAMIENTO * this->vy;
    this->x += this->vx;
    this->y += this->vy;
}

