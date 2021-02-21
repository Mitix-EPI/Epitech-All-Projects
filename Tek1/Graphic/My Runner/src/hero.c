/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** hero
*/

#include "../include/my.h"

int touch_hero(game_t *game, int i)
{
    if (game->character.jump == 1) {
        if (game->character.pos_hero.y - 75 < game->bars[i].pos.y - 100 &&
        game->character.pos_hero.y + 150 > game->bars[i].pos.y - 100) {
            game->nav = 0;
            game->res = - 1;
            return (1);
        }
    }
    if (game->character.jump == 0)
        if (game->bars[i].pos.y >= 620.0f && game->bars[i].pos.y <= 762) {
            game->nav = 0;
            game->res = -1;
            return (1);
        }
    return (0);
}

int update_hero(game_t *game)
{
    for (int i = 0; i < game->limit_bar; i++) {
        if (game->bars[i].pos.x >= 106 && game->bars[i].pos.x <= 190)
            if (touch_hero(game, i))
                return (1);
    }
    return (0);
}