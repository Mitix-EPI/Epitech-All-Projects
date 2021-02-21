/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** move_fights
*/

#include "rpg.h"

int dont_move_touch(player_fight_t *player)
{
    player->rect.top = 10 * 64;
    if (player->direct != 0)
        player->rect.left = 0;
    player->direct = 0;
    sfSprite_setTextureRect(player->player, player->rect);
    return (1);
}

int move_down_touch(player_fight_t *player)
{
    player->rect.top = 8 * 64;
    if (player->direct != 1)
        player->rect.left = 0;
    player->direct = 1;
    sfSprite_setTextureRect(player->player, player->rect);
    return (1);
}

int move_up_touch(player_fight_t *player)
{
    player->rect.top = 10 * 64;
    if (player->direct != 5)
        player->rect.left = 0;
    player->direct = 5;
    sfSprite_setTextureRect(player->player, player->rect);
    return (1);
}

int move_left_touch(player_fight_t *player)
{
    player->rect.top = 11 * 64;
    if (player->direct != 3)
        player->rect.left = 0;
    player->direct = 3;
    sfSprite_setTextureRect(player->player, player->rect);
    return (1);
}

int move_right_touch(player_fight_t *player)
{
    player->rect.top = 9 * 64;
    if (player->direct != 7)
        player->rect.left = 0;
    player->direct = 7;
    sfSprite_setTextureRect(player->player, player->rect);
    return (1);
}
