/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** spikes
*/

#include "../include/my.h"

void update_per_bar(barriers_t *bars, sfRenderWindow *win)
{
    if (bars->seconds > 0.01f) {
        bars->rect.left += 200;
        if (bars->rect.left > 1003)
            bars->rect.left = 0;
        bars->pos.x -= 20;
        sfSprite_setTextureRect(bars->sprite, bars->rect);
        sfSprite_setPosition(bars->sprite, bars->pos);
        sfClock_restart(bars->clck);
    }
    bars->time = sfClock_getElapsedTime(bars->clck);
    bars->seconds = bars->time.microseconds / 1000000.0;
    sfRenderWindow_drawSprite(win, bars->sprite, NULL);
}

void reset_barriers(game_t *game)
{
    for (int i = 0; i < game->limit_bar; i++) {
        game->bars[i].pos.x = game->bars[i].x_origin;
        sfSprite_setPosition(game->bars[i].sprite, game->bars[i].pos);
    }
    game->end.pos.x = game->end.x_origin;
    sfSprite_setPosition(game->end.sprite, game->end.pos);
}