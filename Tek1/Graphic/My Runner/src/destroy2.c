/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** destroy2
*/

#include "../include/my.h"

void destroy_music(game_t *game)
{
    for (int i = 0; i < 6; i++) {
        sfSound_destroy(game->music[i].sound);
        sfSoundBuffer_destroy(game->music[i].buff);
    }
}

void destroy_menu_buttons(game_t *game)
{
    for (int i = 0; i < 4; i++) {
        sfTexture_destroy(game->buts[i].texture);
        sfSprite_destroy(game->buts[i].sprt);
    }
}

int destroy_menu(game_t *game)
{
    for (int i = 0; i < 3; i++) {
        sfTexture_destroy(game->buts[i].texture);
        sfSprite_destroy(game->buts[i].sprt);
    }
    return (0);
}