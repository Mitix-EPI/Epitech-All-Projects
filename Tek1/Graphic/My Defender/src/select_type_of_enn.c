/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** select_type_of_enn
*/

#include "../my_tower.h"

void loop_for_type_two(sprite_t *sprite)
{
    for (int i = 0; i < 10000; i++) {
        if (i % 2 == 0)
            sprite->enn[i].type = 2;
        else
            sprite->enn[i].type = 1;
    }
}

void loop_for_type_three(sprite_t *sprite)
{
    for (int i = 0; i < 10000; i++) {
        if (i - 3 < 10000) {
            sprite->enn[i].type = 1;
            i++;
            sprite->enn[i].type = 2;
            i++;
            sprite->enn[i].type = 3;
        } else {
            sprite->enn[i].type = 1;
        }
    }
}

void select_type_of_ennemies(sprite_t *sprite)
{
    if (sprite->level == 1) {
        for (int i = 0; i < 10000; i++)
            sprite->enn[i].type = 1;
    }
    if (sprite->level == 2) {
        loop_for_type_two(sprite);
    }
    if (sprite->level == 3) {
        loop_for_type_three(sprite);
    }
}