/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** keys_handlings
*/

#include "rpg.h"

void keys_handlings_fight(sfEvent event, rpg_t *rpg,
__attribute__((unused)) game_obj_t *obj)
{
    if (rpg->status == 5 && rpg->end.act == 4) {
        if ((int) event.key.code == 57 || (int) event.key.code == 58)
            rpg->end.msg_rect.top += 1080;
        if (rpg->end.msg_rect.top > 2 * 1080) {
            rpg->end.act = 5;
            rpg->end.tmp = 0;
        }
        sfSprite_setTextureRect(rpg->end.msg, rpg->end.msg_rect);
    }
}

void keys_handlings(sfEvent event, rpg_t *rpg, game_obj_t *obj)
{
    if (rpg->status == 7 && rpg->tuto.action == 2) {
        if ((int) event.key.code == 57 || (int) event.key.code == 58) {
            rpg->tuto.rect.top += 1080;
            sfSprite_setTextureRect(rpg->tuto.sprite, rpg->tuto.rect);
        }
        if (rpg->tuto.rect.top > 4320)
            rpg->tuto.action = 3;
        if ((int) event.key.code == 60) {
            if (rpg->tuto.rect.top > 0)
                rpg->tuto.rect.top -= 1080;
            sfSprite_setTextureRect(rpg->tuto.sprite, rpg->tuto.rect);
        }
    }
    keys_handlings_fight(event, rpg, obj);
}