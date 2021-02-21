/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** my_window
*/

#include "../include/my.h"

void destroy_menu(window_t *w)
{
    sfSprite_destroy(w->squit);
    sfSprite_destroy(w->splay);
    sfTexture_destroy(w->tplay);
    sfTexture_destroy(w->tquit);
    sfText_destroy(w->text1);
    sfSprite_destroy(w->sbg0);
}

int coor_p_q(sfRenderWindow *window, window_t *w, int x, int y)
{
    if (x >= 1211 && x <= 1443 && y >= 313 && y <= 361) {
        w->try_again = 1;
        return (0);
    }
    if (x >= 1211 && x <= 1443 && y >= 410 && y <= 470) {
        return (exit_menu(window, w));
    }
    return (1);
}

void display_menu(sfRenderWindow *window, window_t *w)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, w->sbg0, NULL);
    sfRenderWindow_drawSprite(window, w->splay, NULL);
    sfRenderWindow_drawSprite(window, w->squit, NULL);
    sfRenderWindow_display(window);
}

void interactive_button(window_t *w, int x, int y)
{
    if (x >= 1211 && x <= 1443 && y >= 313 && y <= 361) {
        w->button.left = 250;
        sfSprite_setTextureRect(w->splay, w->button);
    } else {
        w->button.left = 0;
        sfSprite_setTextureRect(w->splay, w->button);
    }
    if (x >= 1211 && x <= 1443 && y >= 410 && y <= 470) {
        w->button.left = 250;
        sfSprite_setTextureRect(w->squit, w->button);
    } else {
        w->button.left = 0;
        sfSprite_setTextureRect(w->squit, w->button);
    }
}

int run_menu(sfRenderWindow *window, window_t *w)
{
    int w_open = 1;

    set_text(w);
    while (w_open) {
        sfRenderWindow_clear(window, sfBlack);
        w->mouse_pos = sfMouse_getPositionRenderWindow(window);
        while (sfRenderWindow_pollEvent(window, &w->evt)) {
            if (w->evt.type == sfEvtClosed)
                return (exit_menu(window, w));
            if (sfKeyboard_isKeyPressed(sfKeyEscape))
                return (exit_menu(window, w));
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                w_open = coor_p_q(window, w, w->mouse_pos.x, w->mouse_pos.y);
            }
        }
        interactive_button(w, w->mouse_pos.x, w->mouse_pos.y);
        display_menu(window, w);
    }
    destroy_menu(w);
    return (0);
}