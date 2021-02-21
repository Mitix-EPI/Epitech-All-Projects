/*
** EPITECH PROJECT, 2019
** realwork
** File description:
** my_event_game
*/

#include "../include/my.h"

int printrandoms(int lower, int upper)
{
    return ((rand() % (upper - lower + 1)) + lower);
}

void touch_tmax(sfRenderWindow *window , window_t *w)
{
    if (w->cursor_x >= w->tmax_pos_x && w->cursor_x <= w->tmax_pos_x + 330)
        if (w->cursor_y >= 500 && w->cursor_y <= 750) {
            w->tmax_pos_x = printrandoms(-2000, -450);
            w->speed_mob += 0.7;
            w->score += 1;
            w->str_score = my_itc(w->score);
        }
}

void touch_ufo(sfRenderWindow *window , window_t *w)
{
    if (w->cursor_x >= w->ufo_pos_x && w->cursor_x <= w->ufo_pos_x + 330)
        if (w->cursor_y >= w->ufo_pos_y && w->cursor_y <= w->ufo_pos_y + 160) {
            w->ufo_pos_x = printrandoms(-2000, -450);
            w->ufo_pos_y = printrandoms(-10, 300);
            w->speed_mob += 0.7;
            w->score += 1;
            w->str_score = my_itc(w->score);
        }
}

int game_event(sfRenderWindow *window, window_t *w)
{
    if (w->evt.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        return (exit_menu(window, w));
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        move_rect(&w->rect_scope, 930, 930);
        sfSprite_setTextureRect(w->sscope, w->rect_scope);
    }
    if (w->evt.type == sfEvtMouseButtonPressed) {
        touch_ufo(window, w);
        touch_tmax(window, w);
    } else
        default_rect(w);
    return (1);
}