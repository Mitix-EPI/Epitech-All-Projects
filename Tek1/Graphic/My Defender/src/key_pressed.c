/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void key_press(sfRenderWindow *window, sfEvent event, sprite_t *sprite)
{
    if (sprite->statue == 2) {
        name(sprite, event);
        return;
    }
    if ((int)event.key.code == 104) {
        sfRenderWindow_setMouseCursorVisible(window, sfTrue);
        if (sprite->statue == 3) {
            free_tow_enn(sprite);
            sprite->statue = 0;
            return;
        }
        sprite->statue = 0;
        sprite->cursor = 0;
    }
    if ((int)event.key.code == 120 && sprite->rep <= 6) {
        sprite->rep += 1;
        sprite->volume -= 6.5;
    }
    if ((int)event.key.code == 99 && sprite->rep >= 1) {
        sprite->rep -= 1;
        sprite->volume += 6.5;
    }
}