/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu
*/

#include "rpg.h"
#include "my.h"

void set_menu_sprites(rpg_t *rpg)
{
    malloc_everything(rpg);
    char *name[] = {"PLAY\0", "CONTINUE\0", "OPTIONS\0", "QUIT\0", "FPS",
    "SOUND", "BACK", "FPS", "NULL", "BACK", "MUSIC", "NULL", "SOUND", "PAUSE",
    "HOME", "RESUME", "QUIT", "PAUSE", "EASY", "HARD", NULL};
    initialize_text(rpg, name);
    for (int i = 1; i < 5; i += 1)
        rpg->menu[i] = create_object("assets/sprites/menu/button.png",
        (sfVector2f){150, 200 + ((i - 1) * 200)},
        (sfIntRect){0, 0, 310, 78}, SIDONIA + i);
    for (int i = 5; i < 8; i += 1)
        rpg->menu[i] = create_object("assets/sprites/menu/button.png",
        (sfVector2f){743, 250 + ((i - 5) * 225)},
        (sfIntRect){0, 0, 310, 78}, SIDONIA + i);
    for (int i = 19; i < 22; i += 1)
        rpg->menu[i] = create_object("assets/sprites/menu/button.png",
        (sfVector2f){743, 250 + (((i - 14) - 5) * 225)},
        (sfIntRect){0, 0, 310, 78}, SIDONIA + (i - 14));
    set2(rpg, name);
}