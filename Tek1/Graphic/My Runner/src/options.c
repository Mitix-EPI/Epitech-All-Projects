/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** options
*/

#include "../include/my.h"

void destroy_options_end(game_t *game)
{
    destroy_parallax(game);
    destroy_barriers(game);
    free(game->bars);
    destroy_music(game);
    destroy_options_butts(game);
    destroy_end_flag(game);
    destroy_hero(game);
    sfSprite_destroy(game->scoreboard);
    sfTexture_destroy(game->board_t);
    for (int i = 0; i < 9; i++)
        sfText_destroy(game->txt[i].text);
}

int pls_or_mns(int x)
{
    if (x >= 1099 && x <= 1151)
        return (-1);
    if (x >= 1201 && x <= 1251)
        return (1);
    return (0);
}

int event_options(game_t *game)
{
    if (game->win.event.type == sfEvtClosed ||
    ((game->win.event.type == sfEvtKeyPressed) &&
    sfKeyboard_isKeyPressed(sfKeyEscape))) {
        return (1);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft))
        return (choose_butt_optns(game, game->win.m_pos.x, game->win.m_pos.y));
    return (0);
}

void update_options(game_t *game)
{
    game->win.m_pos = sfMouse_getPositionRenderWindow(game->win.w);
    for (int i = 0; i < 8; i++)
        update_per_bg(&game->parallax[i], game->win.w);
    interactive_button_options(game, game->win.m_pos.x, game->win.m_pos.y);
    sound_button_options(game, game->win.m_pos.x, game->win.m_pos.y);
}

int options(game_t *game)
{
    int choice = 0;

    while (sfRenderWindow_isOpen(game->win.w)) {
        update_options(game);
        while (sfRenderWindow_pollEvent(game->win.w, &game->win.event)) {
            choice = event_options(game);
            if (choice == 1) {
                destroy_options_end(game);
                return (1);
            }
            if (choice == 2) {
                game->nav = 0;
                return (0);
            }
        }
        display_options(game);
    }
    destroy_options_end(game);
    return (0);
}