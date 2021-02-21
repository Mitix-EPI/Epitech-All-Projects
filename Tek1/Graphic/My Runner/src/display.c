/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** display
*/

#include "../include/my.h"

void display(game_t *game)
{
    sfSprite_setPosition(game->character.hero, game->character.pos_hero);
    sfRenderWindow_clear(game->win.w, sfBlack);
    for (int i = 0; i < 8; i++)
        sfRenderWindow_drawSprite(game->win.w, game->parallax[i].sprite, NULL);
    if (game->endless == 0)
        sfRenderWindow_drawSprite(game->win.w, game->end.sprite, NULL);
    sfRenderWindow_drawSprite(game->win.w, game->character.hero, NULL);
    for (int i = 0; i < game->limit_bar; i++)
        sfRenderWindow_drawSprite(game->win.w, game->bars[i].sprite, NULL);
    sfText_setPosition(game->text, (sfVector2f) {50, 50});
    sfRenderWindow_drawText(game->win.w, game->text, NULL);
    if (game->res == -1 || game->res == 1) {
        sfRenderWindow_drawSprite(game->win.w, game->scoreboard, NULL);
        sfText_setPosition(game->text, (sfVector2f) {720, 350});
        sfRenderWindow_drawText(game->win.w, game->text, NULL);
    }
    sfRenderWindow_display(game->win.w);
}

void display_menu(game_t *game)
{
    sfRenderWindow_clear(game->win.w, sfBlack);
    for (int i = 0; i < 8; i++)
        sfRenderWindow_drawSprite(game->win.w, game->parallax[i].sprite, NULL);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(game->win.w, game->buts[i].sprt, NULL);
    sfRenderWindow_display(game->win.w);
}

void display_options(game_t *game)
{
    sfRenderWindow_clear(game->win.w, sfBlack);
    for (int i = 0; i < 8; i++)
        sfRenderWindow_drawSprite(game->win.w, game->parallax[i].sprite, NULL);
    for (int i = 3; i < 4; i++)
        sfRenderWindow_drawSprite(game->win.w, game->buts[i].sprt, NULL);
    for (int i = 0; i < 9; i++)
        sfRenderWindow_drawText(game->win.w, game->txt[i].text, NULL);
    for (int i = 0; i < 5; i++)
        sfRenderWindow_drawSprite(game->win.w, game->opts_but[i].sprt, NULL);
    sfRenderWindow_display(game->win.w);
}