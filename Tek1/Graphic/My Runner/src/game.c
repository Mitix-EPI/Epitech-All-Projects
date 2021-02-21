/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** game
*/

#include "../include/my.h"

void destroy(game_t *game)
{
    destroy_parallax(game);
    destroy_barriers(game);
    destroy_end_flag(game);
    destroy_hero(game);
    free(game->bars);
    destroy_options_butts(game);
    destroy_music(game);
    sfSprite_destroy(game->scoreboard);
    sfTexture_destroy(game->board_t);
    for (int i = 0; i < 9; i++)
        sfText_destroy(game->txt[i].text);
}

int update(game_t *game)
{
    if (game->res == 0) {
        update_score(game);
        for (int i = 0; i < 8; i++)
            update_per_bg(&game->parallax[i], game->win.w);
        for (int i = 0; i < game->limit_bar; i++)
            update_per_bar(&game->bars[i], game->win.w);
        update_end(&game->end, game->win.w);
        move_animation(game);
        if (game->endless == 1 && game->end.pos.x < -100)
            reset_barriers(game);
        if (update_hero(game) || finisher(game))
            return (1);
        return (0);
    }
    return (0);
}

int event_game(game_t *game)
{
    if (game->win.event.type == sfEvtClosed ||
    ((game->win.event.type == sfEvtKeyPressed)
    && sfKeyboard_isKeyPressed(sfKeyEscape))) {
        destroy(game);
        return (1);
    }
    if (game->win.event.type == sfEvtKeyPressed)
        if ((game->res == 1 || game->res == -1) &&
        (sfKeyboard_isKeyPressed(sfKeySpace) ||
        sfKeyboard_isKeyPressed(sfKeyUp)))
        return (skip_game_over(game));
    if (game->win.event.type == sfEvtKeyPressed)
        if ((sfKeyboard_isKeyPressed(sfKeySpace) ||
        sfKeyboard_isKeyPressed(sfKeyUp))
        && game->character.jump == 0) {
            sfSound_play(game->music[3].sound);
            game->character.vel.y += -27;
            game->character.jump = 1;
        }
    return (0);
}

int initialisation(game_t *game)
{
    game->pts = 0;
    game->real_pts = 0;
    return (0);
}

int run_game(game_t *game)
{
    int end = initialisation(game);
    int return_to_menu = 0;
    int first_time = 1;

    while (sfRenderWindow_isOpen(game->win.w)) {
        end = update(game);
        jump(game);
        if (end)
            first_time = ending(game, first_time);
        while (sfRenderWindow_pollEvent(game->win.w, &game->win.event)) {
            return_to_menu = event_game(game);
            if (return_to_menu == 1)
                return (1);
            if (return_to_menu == 2) {
                return (0);
            }
        }
        display(game);
    }
    return (0);
}