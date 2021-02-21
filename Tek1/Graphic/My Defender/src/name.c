/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void name(sprite_t *sprite, sfEvent event)
{
    char *nb = malloc(sizeof(char) * 2);
    int key = 0;

    nb[1] = '\0';
    if (event.key.code == 8) {
        if (my_strlen(sprite->name) != 0)
            sprite->name[my_strlen(sprite->name) - 1] = '\0';
    }
    if ((int)event.key.code >= 97 && (int)event.key.code <= 122 && \
    my_strlen(sprite->name) <= 16 || (int)event.key.code == 32 && my_strlen\
    (sprite->name) <= 16 || (int)event.key.code >= 48 && (int)event.key.code \
    <= 57 && my_strlen(sprite->name) <= 16 || (int)event.key.code >= 65 && \
    (int)event.key.code <= 90 && my_strlen(sprite->name) <= 16) {
        nb[0] = (char)event.key.code;
        sprite->name = cat(sprite->name, nb);
    }
    if ((int)event.key.code == 13)
        sprite->statue = 6;
}