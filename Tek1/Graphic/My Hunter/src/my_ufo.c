/*
** EPITECH PROJECT, 2019
** realwork
** File description:
** my_ufo
*/

#include "../include/my.h"

void move_rect_ufo(sfIntRect *rect, int offset, int max_value)
{
    if (rect->top >= max_value) {
        rect->top = 0;
    } else {
        rect->top += offset;
    }
}

void my_display_ufo(sfRenderWindow *window, window_t *w)
{
    sfVector2f ufo_pos = {w->ufo_pos_x, w->ufo_pos_y};

    if (w->second_ufo >= 0.2) {
        move_rect_ufo(&w->rect_ufo, 160, 1120);
        sfClock_restart(w->clock);
    }
    w->time = sfClock_getElapsedTime(w->clock);
    sfSprite_setTextureRect(w->sufo, w->rect_ufo);
    sfSprite_setPosition(w->sufo, ufo_pos);
    w->second_ufo = w->time.microseconds / 1000000.0;
    sfRenderWindow_drawSprite(window, w->sufo, NULL);
    w->ufo_pos_x += w->speed_mob;
    if (w-> ufo_pos_x >= 1635) {
        w->ufo_pos_x = printrandoms(-1000, -450);
        w->ufo_pos_y = printrandoms(-10, 300);
        w->speed_mob = 2;
        set_rect_life(w);
    }
}