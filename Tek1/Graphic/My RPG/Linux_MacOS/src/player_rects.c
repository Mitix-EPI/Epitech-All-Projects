/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_rects
*/

#include "rpg.h"
#include "my.h"

void dont_move(player_t *player)
{
    player->rect.top = 10 * 64;
    if (player->direct != 0)
        player->rect.left = 0;
    player->direct = 0;
    sfSprite_setTextureRect(player->sprite, player->rect);
}

void move_down(player_t *player)
{
    player->rect.top = 10 * 64;
    if (player->direct != 5)
        player->rect.left = 0;
    player->direct = 5;
    sfSprite_setTextureRect(player->sprite, player->rect);
}

void move_up(player_t *player)
{
    player->rect.top = 8 * 64;
    if (player->direct != 1)
        player->rect.left = 0;
    player->direct = 1;
    sfSprite_setTextureRect(player->sprite, player->rect);
}

void move_left(player_t *player)
{
    player->rect.top = 9 * 64;
    if (player->direct != 7)
        player->rect.left = 0;
    player->direct = 7;
    sfSprite_setTextureRect(player->sprite, player->rect);
}

void move_right(player_t *player)
{
    player->rect.top = 11 * 64;
    if (player->direct != 3)
        player->rect.left = 0;
    player->direct = 3;
    sfSprite_setTextureRect(player->sprite, player->rect);
}