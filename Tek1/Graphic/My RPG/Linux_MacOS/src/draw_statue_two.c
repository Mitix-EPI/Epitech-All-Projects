/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_statue
*/

#include "my.h"
#include "rpg.h"
#include "rafik.h"

void display_item(sfRenderWindow *win, rpg_t *rpg,
game_obj_t *obj __attribute__((unused)))
{
    if (rpg->quest.act != 0) {
        sfVector2f pos;
        pos.x = (rpg->quest.pos.x - rpg->quest.x) * 2;
        pos.y = (rpg->quest.pos.y - rpg->quest.y) * 2;
        sfSprite_setPosition(rpg->quest.sprite, pos);
        sfRenderWindow_drawSprite(win, rpg->quest.sprite, NULL);
    }
}

void display_inventory(sfRenderWindow *win, rpg_t *rpg)
{
    if (rpg->quest.act == 1)
        rpg->quest.invent_rect.left = 0;
    if (rpg->quest.act == 2)
        rpg->quest.invent_rect.left = 1920;
    if (rpg->quest.act == 3)
        rpg->quest.invent_rect.left = 3840;
    if (rpg->quest.act == 0)
        rpg->quest.invent_rect.left = 5760;
    sfSprite_setTextureRect(rpg->quest.invent_s, rpg->quest.invent_rect);
    sfRenderWindow_drawSprite(win, rpg->quest.invent_s, NULL);
}

void draw_statues(rpg_t *rpg, sfRenderWindow *win, game_obj_t *obj)
{
    if (rpg->status == 7)
        draw_tuto(win, rpg, obj);
    if (rpg->status == 8)
        draw_death(win, rpg, obj);
    if (rpg->status == 4 || rpg->status == 10 || rpg->status == 11)
        display_fights(rpg->fight, win, rpg);
    if (rpg->status == 9) {
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_drawSprite(win, rpg->fight->buttons[1].sprite, NULL);
        sfRenderWindow_display(win);
    }
    if (rpg->status == 5) {
        end_script(rpg, &rpg->end);
        draw_end_script(rpg, win);
    }
}