/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** menu
*/

#include "../include/my.h"

int destroy_menu_end(game_t *game)
{
    destroy_parallax(game);
    destroy_menu_buttons(game);
    destroy_music(game);
    destroy_options_butts(game);
    destroy_hero(game);
    destroy_end_flag(game);
    for (int i = 0; i < 9; i++)
        sfText_destroy(game->txt[i].text);
    free(game->bars);
    return (1);
}

void update_menu(game_t *game)
{
    game->win.m_pos = sfMouse_getPositionRenderWindow(game->win.w);
    for (int i = 0; i < 8; i++)
        update_per_bg(&game->parallax[i], game->win.w);
    interactive_button(game, game->win.m_pos.x, game->win.m_pos.y);
    song_effect_button(game, game->win.m_pos.x, game->win.m_pos.y);
}

int event_menu(game_t *game)
{
    if (game->win.event.type == sfEvtClosed ||
    ((game->win.event.type == sfEvtKeyPressed) &&
    sfKeyboard_isKeyPressed(sfKeyEscape)))
        return (1);
    if (game->win.event.type == sfEvtKeyPressed)
        if (sfKeyboard_isKeyPressed(sfKeySpace)) {
            return (2);
        }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        return (choose_button(game->win.m_pos.x, game->win.m_pos.y));
    }
    return (0);
}

int distribution(game_t *game, int choice)
{
    if (choice == 1)
        return (destroy_menu_end(game));
    if (choice == 2) {
        game->nav = 1;
        return (destroy_menu(game));
    }
    if (choice == 3) {
        game->nav = 2;
        return (destroy_menu(game));
    }
    return (0);
}

int real_menu(game_t *game)
{
    int choice = 0;

    sets_menu(game);
    while (sfRenderWindow_isOpen(game->win.w)) {
        update_menu(game);
        while (sfRenderWindow_pollEvent(game->win.w, &game->win.event)) {
            choice = event_menu(game);
            if (choice > 0)
                return (distribution(game, choice));
        }
        display_menu(game);
    }
    return (0);
}