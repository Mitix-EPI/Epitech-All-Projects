/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** init_healt_speed_black_hole
*/

#include "rpg.h"

void init_health_speeds(spell_t *spell, spells_names_t type,  sfIntRect rect)
{
    if (type == HEALTH) {
        spell->protection = 0;
        spell->damage = 0;
        sfSprite_setOrigin(spell->sprite, (sfVector2f) {27, rect.height / 2});
        sfSprite_setScale(spell->sprite, (sfVector2f) {1.7, 1.7});
        spell->sec = 20;
        spell->health = sfClock_create();
    }
    if (type == SPEEDS) {
        spell->protection = 0;
        spell->damage = 0;
        sfSprite_setOrigin(spell->sprite, (sfVector2f) {27, rect.height / 2});
        sfSprite_setScale(spell->sprite, (sfVector2f) {1.7, 1.7});
        spell->sec = 15;
    }
}

void init_black_hole(spell_t *spell, spells_names_t type,  sfIntRect rect)
{
    if (type == BLACK_HOLE) {
        spell->damage = 15;
        spell->protection = 0;
        spell->sec = 20;
        sfSprite_setOrigin(spell->sprite, (sfVector2f) {27, rect.height / 2});
        sfSprite_setScale(spell->sprite, (sfVector2f) {0.2, 0.2});
    }
}
