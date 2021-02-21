/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** close
*/

#include "../include/my.h"

int close_window_menu(sfRenderWindow *window, window_t *w)
{
    sfSound_destroy(w->ibiza);
    sfSoundBuffer_destroy(w->buffer);
    sfTexture_destroy(w->tbg0);
    sfText_destroy(w->text);
    sfFont_destroy(w->font);
    sfRenderWindow_destroy(window);
    return (0);
}

int exit_menu(sfRenderWindow *window, window_t *w)
{
    w->try_again = 0;
    sfSound_destroy(w->ibiza);
    sfSoundBuffer_destroy(w->buffer);
    sfTexture_destroy(w->tbg0);
    sfText_destroy(w->text);
    sfFont_destroy(w->font);
    sfRenderWindow_destroy(window);
    return (0);
}