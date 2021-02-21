/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void free_tow_enn(sprite_t *sprite)
{
    for (int i = 0; i < 10000; i++) {
        sfTexture_destroy(sprite->enn[i].txtre);
        sfClock_destroy(sprite->enn[i].clock);
    }
    for (int i = 0; i < 100; i++) {
        sfTexture_destroy(sprite->tow[i].txtre);
        sfClock_destroy(sprite->tow[i].clock);
    }
    for (int a = 0; sprite->map_[a]; a++)
        free(sprite->map_[a]);
    free(sprite->map_);
}