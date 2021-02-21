/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void click_pause(sfMouseButtonEvent event, sfRenderWindow *window, \
sprite_t *sprite, sfVector2i mouse)
{
    if (mouse.x >= croix(11, 'l', sprite) && mouse.x <= croix(54, 'l', sprite)
    && mouse.y >= croix(12, 'h', sprite) &&
    mouse.y <= croix(49, 'h', sprite)) {
        sprite->pause = 1;
    }
}

void click_menu_pause(sfMouseButtonEvent event, sfRenderWindow *window, \
sprite_t *sprite, sfVector2i mouse)
{
    if (mouse.x <= croix(1077, 'l', sprite) && mouse.x >= croix\
    (792, 'l', sprite) && mouse.y <= croix(450, 'h', sprite) \
    && mouse.y >= croix(285, 'h', sprite))
            sprite->pause = 0;
    if (mouse.x <= croix(1077, 'l', sprite) && mouse.x >= croix\
    (792, 'l', sprite) && mouse.y <= croix(651, 'h', sprite) \
    && mouse.y >= croix(487, 'h', sprite)) {
        sprite->cursor = 0;
        sprite->statue = 0;
    }
    if (mouse.x <= croix(1077, 'l', sprite) && mouse.x >= croix\
    (792, 'l', sprite) && mouse.y <= croix(865, 'h', sprite) \
    && mouse.y >= croix(691, 'h', sprite))
        close_windows(window, sprite);
}