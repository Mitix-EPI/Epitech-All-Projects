/*
** EPITECH PROJECT, 2019
** sauvegarde_my_hunter
** File description:
** my_try_again
*/

/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** my_window
*/

#include "../include/my.h"

void destroy_t_a(window_t *w)
{
    sfSprite_destroy(w->squit);
    sfSprite_destroy(w->splay);
    sfTexture_destroy(w->tplay);
    sfTexture_destroy(w->tquit);
}

int t_a_or_q(sfRenderWindow *window, window_t *w, int x, int y)
{
    if (x >= 1210 && x <= 1440 && y >= 310 && y <= 362) {
        w->try_again = 1;
        w->not_close_t_a = 1;
        return (1);
    }
    if (x >= 1210 && x <= 1440 && y >= 410 && y <= 462) {
        w->not_close_t_a = 1;
        return (exit_menu(window, w));
    }
    w->not_close_t_a = 0;
}

void display_t_a(sfRenderWindow *window, window_t *w)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, w->sbg0, NULL);
    sfRenderWindow_drawSprite(window, w->splay, NULL);
    sfRenderWindow_drawSprite(window, w->squit, NULL);
    sfRenderWindow_drawText(window, w->text_score, NULL);
    sfRenderWindow_display(window);
}

void interactive_button2(window_t *w, int x, int y)
{
    if (x >= 1210 && x <= 1440 && y >= 310 && y <= 362) {
        w->button.left = 250;
        sfSprite_setTextureRect(w->splay, w->button);
    } else {
        w->button.left = 0;
        sfSprite_setTextureRect(w->splay, w->button);
    }
    if (x >= 1210 && x <= 1440 && y >= 410 && y <= 462) {
        w->button.left = 250;
        sfSprite_setTextureRect(w->squit, w->button);
    } else {
        w->button.left = 0;
        sfSprite_setTextureRect(w->squit, w->button);
    }
}

int my_try_again(sfRenderWindow *window, window_t *w)
{
    w->not_close_t_a = 0;

    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    w->sbg0 = sfSprite_create();
    set_text_t_a(w);
    while (w->not_close_t_a == 0) {
        w->mouse_pos = sfMouse_getPositionRenderWindow(window);
        interactive_button2(w, w->mouse_pos.x, w->mouse_pos.y);
        while (sfRenderWindow_pollEvent(window, &w->evt)) {
            if (w->evt.type == sfEvtClosed)
                return (exit_menu(window, w));
            if (sfKeyboard_isKeyPressed(sfKeyEscape))
                return (exit_menu(window, w));
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                if (t_a_or_q(window, w, w->mouse_pos.x, w->mouse_pos.y) == 0)
                    return (0);
            }
        }
        display_t_a(window, w);
    }
    destroy_t_a(w);
}