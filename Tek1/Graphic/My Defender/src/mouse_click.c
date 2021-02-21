/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void manage_mouse_click(sfMouseButtonEvent event, \
sfRenderWindow *window, sprite_t *sprite)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (sprite->statue == 6)
        click_statue_six(event, window, sprite, mouse);
    if (sprite->statue == 0)
        click_statue_zero(event, window, sprite, mouse);
    if (sprite->statue == 1)
        click_statue_un(event, window, sprite, mouse);
    if (sprite->statue == 3)
        click_statue_trois(event, window, sprite, mouse);
    if (event.button == sfMouseRight)
        sprite->cursor = 0;
}