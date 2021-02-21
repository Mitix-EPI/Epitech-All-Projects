/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

char *remplace_score(char *temp, char *tempa)
{
    temp = malloc(sizeof(char) * (my_strlen(tempa) + 1));

    temp[my_strlen(tempa)] = '\0';
    for (int a = 0; tempa[a]; a++)
        temp[a] = tempa[a];
    return (temp);
}

void save_score(sprite_t *sprite)
{
    sprite->score = (sprite->gold \
    - (sprite->tow_alive * 50) + sprite->life * 1.5) * sprite->vague;
    if (sprite->level == 1)
        save_mode_one(sprite);
    if (sprite->level == 2)
        save_mode_two(sprite);
    if (sprite->level == 3)
        save_mode_tree(sprite);
}

void save_mode_one(sprite_t *sprite)
{
    if (sprite->score > my_atoi(sprite->all_score[1])) {
        sprite->all_score[1] = remplace_score\
        (sprite->all_score[1], int_to_string(sprite->score));
        sprite->all_score[0] = remplace_score\
        (sprite->all_score[0], sprite->name);
        return;
    }
    if (sprite->score > my_atoi(sprite->all_score[3])) {
        sprite->all_score[3] = remplace_score\
        (sprite->all_score[3], int_to_string(sprite->score));
        sprite->all_score[2] = remplace_score\
        (sprite->all_score[2], sprite->name);
        return;
    }
    if (sprite->score > my_atoi(sprite->all_score[5])) {
        sprite->all_score[5] = remplace_score\
        (sprite->all_score[5], int_to_string(sprite->score));
        sprite->all_score[4] = remplace_score\
        (sprite->all_score[4], sprite->name);
        return;
    }
}

void save_mode_two(sprite_t *sprite)
{
    if (sprite->score > my_atoi(sprite->all_score[7])) {
        sprite->all_score[7] = remplace_score(sprite->\
        all_score[7], int_to_string(sprite->score));
        sprite->all_score[6] = remplace_score(sprite->\
        all_score[6], sprite->name);
        return;
    }
    if (sprite->score > my_atoi(sprite->all_score[9])) {
        sprite->all_score[9] = remplace_score(sprite->\
        all_score[9], int_to_string(sprite->score));
        sprite->all_score[8] = remplace_score(sprite->\
        all_score[8], sprite->name);
        return;
    }
    if (sprite->score > my_atoi(sprite->all_score[11])) {
        sprite->all_score[11] = remplace_score(sprite->\
        all_score[11], int_to_string(sprite->score));
        sprite->all_score[10] = remplace_score(sprite->\
        all_score[10], sprite->name);
        return;
    }
}

void save_mode_tree(sprite_t *sprite)
{
    if (sprite->score > my_atoi(sprite->all_score[13])) {
        sprite->all_score[13] = remplace_score(sprite->\
        all_score[13], int_to_string(sprite->score));
        sprite->all_score[12] = remplace_score(sprite->\
        all_score[12], sprite->name);
        return;
    }
    if (sprite->score > my_atoi(sprite->all_score[15])) {
        sprite->all_score[15] = remplace_score(sprite->\
        all_score[15], int_to_string(sprite->score));
        sprite->all_score[14] = remplace_score(sprite->\
        all_score[14], sprite->name);
        return;
    }
        if (sprite->score > my_atoi(sprite->all_score[17])) {
        sprite->all_score[17] = remplace_score(sprite->\
        all_score[17], int_to_string(sprite->score));
        sprite->all_score[16] = remplace_score(sprite->\
        all_score[16], sprite->name);
        return;
    }
}