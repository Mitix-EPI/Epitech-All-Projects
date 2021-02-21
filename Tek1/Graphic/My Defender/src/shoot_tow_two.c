/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void diff_tow(sprite_t *sprite, int i)
{
    sprite->tow[i].tow == 1 ? shoot_tow_one(sprite, i) : 0;
    sprite->tow[i].tow == 2 ? shoot_tow_two(sprite, i) : 0;
    sprite->tow[i].tow == 3 ? shoot_tow_tree(sprite, i) : 0;
    sprite->tow[i].tow == 4 ? shoot_tow_four(sprite, i) : 0;
}

void shot_tow(sprite_t *sprite, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (sprite->nb_tow == 0)
        return;
    for (int i = 0; i < sprite->nb_tow; i++) {
        sprite->tow[i].time = sfClock_getElapsedTime(sprite->tow[i].clock);
        sprite->tow[i].second = sprite->tow[i].time.microseconds / 1000000.0;
        diff_tow(sprite, i);
    }
}
