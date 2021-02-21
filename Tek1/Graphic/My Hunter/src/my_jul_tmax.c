/*
** EPITECH PROJECT, 2019
** realwork
** File description:
** my_jul_tmax
*/

#include "../include/my.h"

void set_rect_life(window_t *w)
{
    w->rect_life.top -= 240;
    w->life -= 1;
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left >= max_value) {
        rect->left = 0;
    } else {
        rect->left += offset;
    }
}

void my_display_jul(sfRenderWindow *window, window_t *w)
{
    sfVector2f jul_pos = {w->tmax_pos_x, w->tmax_pos_y};

    w->tmax_pos_y = 450;
    if (w->second >= 0.2) {
        move_rect(&w->rect_tmax, 201, 603);
        sfClock_restart(w->clock);
    }
    w->time = sfClock_getElapsedTime(w->clock);
    sfSprite_setTextureRect(w->stmax, w->rect_tmax);
    sfSprite_setPosition(w->stmax, jul_pos);
    w->second = w->time.microseconds / 1000000.0;
    sfRenderWindow_drawSprite(window, w->stmax, NULL);
    w->tmax_pos_x += w->speed_mob;
    if (w-> tmax_pos_x >= 1635) {
        w->tmax_pos_x = printrandoms(-1000, -450);
        w->speed_mob = 2;
        set_rect_life(w);
    }
}