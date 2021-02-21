/*
** EPITECH PROJECT, 2019
** realwork
** File description:
** my_pointer
*/

#include "../include/my.h"

void default_rect(window_t *w2)
{
    w2->rect_scope.top = 0;
    w2->rect_scope.left = 0;
    w2->rect_scope.width = 930;
    w2->rect_scope.height = 615;
}

void my_pointer(sfRenderWindow *window, window_t *w2)
{
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    w2->mouse = sfMouse_getPositionRenderWindow(window);
    w2->cursor_x = w2->mouse.x;
    w2->cursor_y = w2->mouse.y;
    w2->position_cursor.x = w2->cursor_x - 120;
    w2->position_cursor.y = w2->cursor_y - 95;
    sfSprite_setTextureRect(w2->sscope, w2->rect_scope);
    sfSprite_setPosition(w2->sscope, w2->position_cursor);
    sfRenderWindow_drawSprite(window, w2->sscope, NULL);

}