/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** destroy
*/

#include "../include/my.h"

void destroy_parallax(game_t *game)
{
    for (int i = 0; i < 8; i++) {
        sfTexture_destroy(game->parallax[i].texture);
        sfSprite_destroy(game->parallax[i].sprite);
        sfClock_destroy(game->parallax[i].clck);
    }
}

void destroy_barriers(game_t *game)
{
    for (int i = 0; i < game->limit_bar; i++) {
        sfTexture_destroy(game->bars[i].texture);
        sfSprite_destroy(game->bars[i].sprite);
        sfClock_destroy(game->bars[i].clck);
    }
}

void destroy_end_flag(game_t *game)
{
    sfTexture_destroy(game->end.texture);
    sfSprite_destroy(game->end.sprite);
    sfClock_destroy(game->end.clck);
}

void destroy_hero(game_t *game)
{
    sfTexture_destroy(game->character.t_hero);
    sfSprite_destroy(game->character.hero);
    sfClock_destroy(game->character.clck);
}

void destroy_options_butts(game_t *game)
{
    for (int i = 0; i < 5; i++) {
        sfSprite_destroy(game->opts_but[i].sprt);
        sfTexture_destroy(game->opts_but[i].texture);
    }
}