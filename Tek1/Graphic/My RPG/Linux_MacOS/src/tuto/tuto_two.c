/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** tuto
*/

#include "rpg.h"

void begin_action_three_two(rpg_t *rpg,
__attribute__((unused)) game_obj_t *background)
{
    if (rpg->tuto.tmp >= 13 && rpg->tuto.tmp < 25) {
        rpg->tuto.rect_friend.top = 216;
        rpg->tuto.pos.y -= 5;
    }
    if (rpg->tuto.tmp >= 25){
        stop_all_music(rpg);
        sfSound_play(rpg->snd_main_music);
        rpg->status = 3;
        rpg->tuto.action = 0;
        rpg->tuto.tmp = 0;
    }
}

void begin_action_three(rpg_t *rpg, game_obj_t *background)
{
    if (rpg->tuto.tmp < 5) {
        rpg->tuto.rect_friend.top = 216;
        rpg->tuto.pos.y -= 5;
    }
    if (rpg->tuto.tmp >= 5 && rpg->tuto.tmp < 13){
        rpg->tuto.rect_friend.top = 72;
        rpg->tuto.pos.x -= 4;
    }
    begin_action_three_two(rpg, background);
}

void action_three(rpg_t *rpg, game_obj_t *background)
{
    begin_action_three(rpg, background);
    rpg->tuto.rect_friend.left += 50;
    if (rpg->tuto.rect_friend.left > 100)
        rpg->tuto.rect_friend.left = 0;
    rpg->tuto.tmp += 1;
    sfSprite_setPosition(rpg->tuto.friend, rpg->tuto.pos);
    sfSprite_setTextureRect(rpg->tuto.friend, rpg->tuto.rect_friend);
}

void action_two(rpg_t *rpg, game_obj_t *background)
{
    if (rpg->tuto.rect.top == 1080) {
        background->rect.top = 1690;
        background->rect.left = 55;
        sfSprite_setTextureRect(background->sprite, background->rect);
    } else {
        background->rect.top = 1006;
        background->rect.left = 1280;
        sfSprite_setTextureRect(background->sprite, background->rect);
    }
}