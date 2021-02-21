/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void move_rect(int offset, sprite_t *sprite, int jsp)
{
    sfIntRect rect;

    rect.top = offset;
    rect.left = jsp;
    rect.width = 947;
    rect.height = 173;
    sfSprite_setTextureRect(sprite->menu_btn, rect);
}

void clock_event(sfRenderWindow *window, sprite_t *sprite, clock_s clock)
{
    float seconde;

    clock.time = sfClock_getElapsedTime(clock.clock);
    seconde = clock.time.microseconds / 1000000.0;
    if (seconde > 0.07) {
        move_rect(sprite->vert, sprite, sprite->hori);
        sprite->hori += 947;
        if (sprite->hori > 947 * 4 - 1) {
            sprite->hori = 0;
            sprite->vert += 173;
        }
        if (sprite->vert > 173 * 8 - 1)
            sprite->vert = 0;
        sfClock_restart(clock.clock);
    }
}