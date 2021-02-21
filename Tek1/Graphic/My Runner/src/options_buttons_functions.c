/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** options_buttons_functions
*/

#include "../include/my.h"

void ips_change(game_t *game, int i)
{
    if (i == 1) {
        sfSound_play(game->music[5].sound);
        if (game->ips < 120) {
            game->ips += 5;
            sfRenderWindow_setFramerateLimit(game->win.w, game->ips);
            sfText_setString(game->txt[1].text, my_itc(game->ips));
        }
    }
    if (i == -1) {
        sfSound_play(game->music[5].sound);
        if (game->ips > 60) {
            game->ips -= 5;
            sfRenderWindow_setFramerateLimit(game->win.w, game->ips);
            sfText_setString(game->txt[1].text, my_itc(game->ips));
        }
    }
}

void music_volum(game_t *game, int i)
{
    if (i == 1) {
        sfSound_play(game->music[5].sound);
        if (game->vol_music < 100) {
            game->vol_music += 5;
            sfSound_setVolume(game->music[0].sound, game->vol_music);
            sfText_setString(game->txt[3].text, my_itc(game->vol_music));
        }
    }
    if (i == -1) {
        sfSound_play(game->music[5].sound);
        if (game->vol_music > 0) {
            game->vol_music -= 5;
            sfSound_setVolume(game->music[0].sound, game->vol_music);
            sfText_setString(game->txt[3].text, my_itc(game->vol_music));
        }
    }
}

void effect_volum(game_t *game, int i)
{
    if (i == 1) {
        sfSound_play(game->music[5].sound);
        if (game->vol_effect < 100) {
            game->vol_effect += 5;
            for (int i = 1; i < 6; i++)
                sfSound_setVolume(game->music[i].sound, game->vol_effect);
            sfText_setString(game->txt[5].text, my_itc(game->vol_effect));
        }
    }
    if (i == -1) {
        sfSound_play(game->music[5].sound);
        if (game->vol_effect > 0) {
            game->vol_effect -= 5;
            for (int i = 1; i < 6; i++)
                sfSound_setVolume(game->music[i].sound, game->vol_effect);
            sfText_setString(game->txt[5].text, my_itc(game->vol_effect));
        }
    }
}

void difficulty_change(game_t *game, int i)
{
    if (i == 1) {
        sfSound_play(game->music[5].sound);
        if (game->difficulty < 3) {
            game->difficulty += 1;
            sfText_setString(game->txt[7].text, my_itc(game->difficulty));
        }
    }
    if (i == -1) {
        sfSound_play(game->music[5].sound);
        if (game->difficulty > 1) {
            game->difficulty -= 1;
            sfText_setString(game->txt[7].text, my_itc(game->difficulty));
        }
    }
}

void endless_change(game_t *game)
{
    if (game->endless == 0) {
        sfSound_play(game->music[5].sound);
        game->opts_but[4].rct.left = 100;
        sfSprite_setTextureRect(game->opts_but[4].sprt, game->opts_but[4].rct);
        game->endless = 1;
        return;
    }
    if (game->endless == 1) {
        sfSound_play(game->music[5].sound);
        game->opts_but[4].rct.left = 0;
        sfSprite_setTextureRect(game->opts_but[4].sprt, game->opts_but[4].rct);
        game->endless = 0;
        return;
    }
}