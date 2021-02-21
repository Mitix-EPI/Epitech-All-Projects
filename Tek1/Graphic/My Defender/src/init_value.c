/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void init_name(sprite_t *sprite)
{
    sprite->name = malloc(sizeof(char) * 18);
    for (int i = 0; i != 18; i++)
        sprite->name[i] = 0;
    sprite->name[0] = 'e';
    sprite->name[1] = 'n';
    sprite->name[2] = 't';
    sprite->name[3] = 'e';
    sprite->name[4] = 'r';
    sprite->name[5] = ' ';
    sprite->name[6] = 'y';
    sprite->name[7] = 'o';
    sprite->name[8] = 'u';
    sprite->name[9] = 'r';
    sprite->name[10] = ' ';
    sprite->name[11] = 'p';
    sprite->name[12] = 's';
    sprite->name[13] = 'e';
    sprite->name[14] = 'u';
    sprite->name[15] = 'd';
    sprite->name[16] = 'o';
    sprite->name[17] = '\0';
}

void int_value_two(sprite_t *sprite, clock_s *clock)
{
    sfMusic_play(sprite->music_hard);
    sfMusic_play(sprite->music_chill);
    sfMusic_stop(sprite->music_hard);
    sfMusic_setVolume(sprite->music_chill, sprite->volume);
    sfMusic_setLoop(sprite->music_chill, sfTrue);
}

void int_value(sprite_t *sprite, clock_s *clock)
{
    init_name(sprite);
    sprite->life = 1;
    sprite->last_angle = 0;
    sprite->tow_alive = 0;
    sprite->vague = 1;
    sprite->statue = 0;
    sprite->score = 0;
    sprite->rep = 0;
    sprite->volume = 50;
    sprite->hight = 1920;
    sprite->weidth = 1080;
    clock->second = 0;
    sprite->hori = 0;
    sprite->vert = 0;
    sprite->cursor = 0;
    sprite->nb_tow = 0;
    sprite->all_score = my_str_to_word_array(map_reader\
    ("score.txt", 990));
    int_value_two(sprite, clock);
}