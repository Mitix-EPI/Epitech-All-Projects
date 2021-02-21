/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void click_statue_zero(sfMouseButtonEvent event, \
sfRenderWindow *window, sprite_t *sprite, sfVector2i mouse)
{
    if (mouse.x <= croix(1217, 'l', sprite) && mouse.x >= croix\
    (720, 'l', sprite) && mouse.y <= croix(876, 'h', sprite) \
    && mouse.y >= croix(620, 'h', sprite))
        sprite->statue = 1;
    if (mouse.x <= croix(1802, 'l', sprite) && mouse.x >= croix\
    (1305, 'l', sprite) && mouse.y <= croix(881, 'h', sprite) \
    && mouse.y >= croix(618, 'h', sprite))
        close_windows(window, sprite);
    if (mouse.x <= croix(611, 'l', sprite) && mouse.x >= croix\
    (146, 'l', sprite) && mouse.y <= croix(876, 'h', sprite) \
    && mouse.y >= croix(618, 'h', sprite)) {
        sprite->statue = 2;
        sprite->vague = 1;
        sprite->pause = 0;
        sprite->tow->nb_tow = 0;
        sprite->nb_tow = 0;
        sprite->enn_alive = sprite->nb_enn;
        sprite->life = 100;
        sprite->gold = 500;
        sprite->tow_alive = 0;
    }
}