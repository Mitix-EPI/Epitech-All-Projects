/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_player
*/

#include "rpg.h"

void init_player(player_t *obj)
{
    sfVector2f pos;
    pos.x = (1920 / 2) - (64 / 2);
    pos.y = (1080 / 2) - (64 / 2);
    obj->pos = pos;
    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile("assets/sprites/character.png",
    NULL);
    obj->clock.clock = sfClock_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    obj->rect = (sfIntRect) {0, 0, 64, 64};
    sfSprite_setOrigin(obj->sprite, (sfVector2f) {32, 32});
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setPosition(obj->sprite, pos);
}