/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** ending_game
*/

#include "../include/my.h"

int skip_game_over(game_t *game)
{
    sfSound_play(game->music[5].sound);
    game->nav = 0;
    if (game->res == 1)
        sfSound_stop(game->music[1].sound);
    if (game->res == -1)
        sfSound_stop(game->music[2].sound);
    sfSound_play(game->music[0].sound);
    game->res = 0;
    return (2);
}

int ending(game_t *game, int first_time)
{
    reset_barriers(game);
    if (game->res == -1 && first_time) {
        sfSound_pause(game->music[0].sound);
        sfSound_play(game->music[2].sound);
    }
    if (game->res == 1 && first_time) {
        sfSound_pause(game->music[0].sound);
        sfSound_play(game->music[1].sound);
    }
    return (0);
}