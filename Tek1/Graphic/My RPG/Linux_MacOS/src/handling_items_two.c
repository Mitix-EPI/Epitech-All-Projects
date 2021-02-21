/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** handling_items
*/

#include "rpg.h"

float angle(__attribute__((unused)) rpg_t *rpg, sfVector2f pos)
{
    double diff_x = (960 - pos.x);
    double diff_y =  (540 - pos.y);
    float angle = atan2f(diff_y, diff_x) * (180.0 / M_PI) - 90;

    return (angle);
}

void generic_function_bg_quest_part_two(rpg_t *rpg)
{
    if (rpg->quest.act == 3) {
        rpg->quest.rect.left = 60;
        sfSprite_setTextureRect(rpg->quest.sprite, rpg->quest.rect);
        rpg->quest.pos.x = 232;
        rpg->quest.pos.y = 717;
    }
    if (rpg->quest.act == 0) {
        rpg->quest.rect.width = 0;
        rpg->quest.pos = (sfVector2f) {522, 1883};
        sfSprite_setTextureRect(rpg->quest.sprite, rpg->quest.rect);
    }
}

void generic_function_bg_quest(rpg_t *rpg)
{
    if (rpg->quest.act == 1) {
        rpg->quest.rect.left = 0;
        sfSprite_setTextureRect(rpg->quest.sprite, rpg->quest.rect);
        rpg->quest.pos.x = 195;
        rpg->quest.pos.y = 84;
    }
    if (rpg->quest.act == 2) {
        rpg->quest.rect.left = 30;
        sfSprite_setTextureRect(rpg->quest.sprite, rpg->quest.rect);
        rpg->quest.pos.x = 2080;
        rpg->quest.pos.y = 1706;
    }
    generic_function_bg_quest_part_two(rpg);
}

void change_item_part_two(rpg_t *rpg)
{
    if (rpg->quest.act == 3) {
        rpg->quest.rect.width = 0;
        rpg->quest.act = 0;
        rpg->quest.pos = (sfVector2f) {527, 1887};
        sfSprite_setTextureRect(rpg->quest.sprite, rpg->quest.rect);
        sfSprite_setPosition(rpg->quest.sprite, rpg->quest.pos);
    }
}

void change_item(rpg_t *rpg)
{
    if (rpg->quest.act == 1) {
        rpg->quest.act = 2;
        rpg->quest.rect.left = 30;
        sfSprite_setTextureRect(rpg->quest.sprite, rpg->quest.rect);
        rpg->quest.pos.x = 2080;
        rpg->quest.pos.y = 1706;
        sfSprite_setPosition(rpg->quest.sprite, rpg->quest.pos);
        return;
    }
    if (rpg->quest.act == 2) {
        rpg->quest.act = 3;
        rpg->quest.rect.left = 60;
        sfSprite_setTextureRect(rpg->quest.sprite, rpg->quest.rect);
        rpg->quest.pos.x = 232;
        rpg->quest.pos.y = 717;
        sfSprite_setPosition(rpg->quest.sprite, rpg->quest.pos);
        return;
    }
    change_item_part_two(rpg);
}