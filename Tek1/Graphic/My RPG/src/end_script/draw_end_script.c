/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_end_script
*/

#include "rpg.h"

void draw_end_script(rpg_t *rpg, sfRenderWindow *win)
{
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, rpg->end.bg, NULL);
    sfRenderWindow_drawSprite(win, rpg->end.gf, NULL);
    sfRenderWindow_drawSprite(win, rpg->player.sprite, NULL);
    sfRenderWindow_drawSprite(win, rpg->end.bg2, NULL);
    if (rpg->end.tmp == 1)
        sfRenderWindow_drawSprite(win, rpg->end.msg, NULL);
    sfRenderWindow_drawCircleShape(win, rpg->end.cinematic, NULL);
    if (rpg->end.tmp == 2)
        sfRenderWindow_drawText(win, rpg->end.text->text, NULL);
    sfRenderWindow_display(win);
}