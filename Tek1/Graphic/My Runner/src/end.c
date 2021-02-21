/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** end
*/

#include "../include/my.h"

void update_end(end_t *end, sfRenderWindow *win)
{
    if (end->seconds > 0.01f) {
        end->pos.x -= 20;
        sfSprite_setPosition(end->sprite, end->pos);
        sfClock_restart(end->clck);
    }
    end->time = sfClock_getElapsedTime(end->clck);
    end->seconds = end->time.microseconds / 1000000.0;
    sfRenderWindow_drawSprite(win, end->sprite, NULL);
}

int finisher(game_t *game)
{
    if (game->endless == 1)
        return (0);
    if (game->end.pos.x < 150) {
        game->nav = 0;
        game->res = 1;
        return (1);
    }
    return (0);
}