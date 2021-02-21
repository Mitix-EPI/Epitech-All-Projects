/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** options_buttons
*/

#include "../include/my.h"

void interactive_button_options(game_t *game, int x, int y)
{
    if (x >= 60 && x <= 294 && y >= 59 && y <= 115)
        game->buts[3].rct.left = 250;
    else
        game->buts[3].rct.left = 0;
    sfSprite_setTextureRect(game->buts[3].sprt, game->buts[3].rct);
}

void sound_button_options(game_t *game, int x, int y)
{
    static int effect = 0;

    if (x >= 60 && x <= 294 && y >= 59 && y <= 115 && effect == 0) {
        sfSound_play(game->music[5].sound);
        effect = 1;
    }
    if ((x < 60 || x > 284) && effect == 1)
        effect = 0;
    if ((y < 59 || y > 115) && effect == 1)
        effect = 0;
}

int choose_butt_optns(game_t *game, int x, int y)
{
    if (x >= 60 && x <= 294 && y >= 59 && y <= 115)
        return (2);
    if (y >= 223 && y <= 275)
        ips_change(game, pls_or_mns(x));
    if (y >= 326 && y <= 375)
        music_volum(game, pls_or_mns(x));
    if (y >= 423 && y <= 475)
        effect_volum(game, pls_or_mns(x));
    if (y >= 523 && y <= 575)
        difficulty_change(game, pls_or_mns(x));
    if (x >= 1150 && x <= 1200 && y >= 625 && y <= 675) {
        endless_change(game);
    }
    return (0);
}