/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** creates_two
*/

#include "rpg.h"

void create_window(rpg_t *rpg)
{
    sfImage *icon = sfImage_createFromFile("assets/sprites/menu/logo.png");
    sfVideoMode mode = {1920, 1080, 32};
    rpg->win = sfRenderWindow_create(mode, "SIDONA RPG (0fps)", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(rpg->win, 60);
    sfRenderWindow_setIcon(rpg->win, 200, 200, sfImage_getPixelsPtr(icon));
}
