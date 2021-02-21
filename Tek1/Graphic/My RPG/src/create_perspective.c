/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_perspective
*/

#include "rpg.h"

void create_perspec(game_obj_t *perspec)
{
    perspec->sprite = sfSprite_create();
    perspec->texture = sfTexture_createFromFile("map/perspective.png", NULL);
    sfSprite_setTexture(perspec->sprite, perspec->texture, sfTrue);
    sfSprite_setScale(perspec->sprite, (sfVector2f) {2, 2});
    perspec->pos.x = 0;
    perspec->pos.y = 0;
    sfSprite_setPosition(perspec->sprite, perspec->pos);
    perspec->rect = (sfIntRect) {200, 100, 1920, 1080};
    sfSprite_setTextureRect(perspec->sprite, perspec->rect);
}