/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** set_good_pos_enn
*/

#include "../my_tower.h"

int generate_random(int l, int r)
{
    return ((rand() % (r - l + 1)) + l);
}

sfVector2f set_good_pos_for_level_two(sprite_t *sprite, int i)
{
    sfVector2f pos;

    if (i == 1) {
        pos.x = generate_random(croix(400, 'l', sprite), croix\
        (5500, 'l', sprite)) * (-1);
        pos.y = generate_random(croix(480, 'h', sprite), croix\
        (590, 'h', sprite));
        return (pos);
    } else if (i == 2) {
        pos.x = generate_random(croix(445, 'l', sprite), croix\
        (570, 'l', sprite));
        pos.y = generate_random(croix(200, 'h', sprite), croix\
        (3500, 'h', sprite)) * (-1);
        return (pos);
    } else {
        pos.x = generate_random(croix(2500, 'l', sprite), croix\
        (3500, 'l', sprite));
        pos.y = generate_random(croix(793, 'h', sprite), croix\
        (880, 'h', sprite));
        return (pos);
    }
}

sfVector2f set_good_pos(sprite_t *sprite)
{
    sfVector2f pos = {};
    int i = 0;

    if (sprite->level == 1) {
        pos.x = generate_random(croix(200, 'l', sprite), croix\
        (280, 'l', sprite));
        pos.y = generate_random(croix(928, 'h', sprite), croix\
        (3500, 'h', sprite));
        return (pos);
    }
    if (sprite->level == 2) {
        i = generate_random(1, 3);
        return (set_good_pos_for_level_two(sprite, i));
    }
    if (sprite->level == 3) {
        pos.x = generate_random(croix(100, 'l', sprite), croix\
        (5500, 'l', sprite)) * (-1);
        pos.y = generate_random(croix(576, 'h', sprite), croix\
        (678, 'h', sprite));
        return (pos);
    }
}