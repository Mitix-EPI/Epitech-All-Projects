/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** handling_items
*/

#include "rpg.h"

void change_background_fight(fight_t *fight, int i, quest_t quest)
{
    if (i == 0) {
        fight->rect.left = 0;
    } else {
        if (quest.act == 1)
            fight->rect.left = 1920;
        if (quest.act == 2)
            fight->rect.left = 1920 * 2;
        if (quest.act == 3)
            fight->rect.left = 1920 * 3;
        if (quest.act == 0)
            fight->rect.left = 1920 * 4;
    }
    sfSprite_setTextureRect(fight->buttons[4].sprite, fight->rect);
}

void pseudo_upgrade_ennemies(fight_t *fight)
{
    if (fight->spell[0].damage > 1)
        fight->spell[0].damage -= 1;
    if (fight->spell[1].damage > 1)
        fight->spell[1].damage -= 1;
    if (fight->spell[2].damage > 7)
        fight->spell[2].damage -= 2;
}

void maybe_took_item(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        rpg->quest.tmp = 1;
        change_background_fight(rpg->fight, rpg->quest.tmp, rpg->quest);
        init_values_before_fight(rpg->fight);
        stop_all_music(rpg);
        if (rpg->quest.act != 0) {
            sfSound_play(rpg->snd_main_music_fight);
            rpg->status = 4;
        } else {
            sfSound_play(rpg->snd_boss);
            rpg->status = 11;
        }
    }
}

void what_message(rpg_t *rpg)
{
    if (rpg->quest.act != 0)
        rpg->quest.message = 1;
    else
        rpg->quest.message = 2;
}

void handling_items(rpg_t *rpg)
{
    sfVector2f pos;
    pos.x = (rpg->quest.pos.x - rpg->quest.x) * 2;
    pos.y = (rpg->quest.pos.y - rpg->quest.y) * 2;
    if (rpg->quest.tmp == 1) {
        rpg->quest.tmp = 0;
        change_background_fight(rpg->fight, rpg->quest.tmp, rpg->quest);
        pseudo_upgrade_ennemies(rpg->fight);
        change_item(rpg);
    }
    if (rpg->player.pos.x > pos.x - 20 && rpg->player.pos.x < pos.x + 40 &&
    rpg->player.pos.y > pos.y - 20 && rpg->player.pos.y < pos.y + 40) {
        what_message(rpg);
        maybe_took_item(rpg);
    } else {
        rpg->quest.message = 0;
    }
    sfSprite_setRotation(rpg->quest.arrow, angle(rpg, pos));
}