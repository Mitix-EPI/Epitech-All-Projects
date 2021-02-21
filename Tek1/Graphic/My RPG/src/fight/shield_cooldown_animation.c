/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** shield_cooldown_animation
*/

#include "rpg.h"

void set_cooldown_shield(float res, spell_t *spell)
{
    char *str = ftoa(res, 2);

    sfText_setString(spell->text.text, str);
    spell->text.str = "activate";
}

void display_cooldown_shield(float second, spell_t *spell)
{
    if (second < spell->sec)
        set_cooldown_shield(spell->sec - second, spell);
    else
        spell->text.str = NULL;
}

int cooldown_shield(spell_t *spell)
{
    spell->clock_cd.time = sfClock_getElapsedTime(spell->clock_cd.clock);
    spell->clock_cd.seconds = spell->clock_cd.time.microseconds / 1000000.0;
    if (spell->activated == 1 && spell->clock_cd.seconds
    > 2 && spell->tmp2 == 0) {
        spell->activated = 2;
        spell->tmp2 = 1;
        return (1);
    }
    if (spell->activated == 2)
        display_cooldown_shield(spell->clock_cd.seconds, spell);
    if (spell->activated == 2 && spell->clock_cd.seconds >= spell->sec) {
        spell->activated = 0;
        spell->tmp2 = 0;
        sfClock_restart(spell->clock_cd.clock);
        return (0);
    }
    return (1);
}

void animation_shield(spell_t *spell)
{
    sfTime time = sfClock_getElapsedTime(spell->clock);
    float second = time.microseconds / 1000000.0;
    if (second > 0.09) {
        if (spell->rect.left < 180 - 60) {
            spell->rect.left += 60;
        } else {
            spell->rect.left = 0;
        }
        sfClock_restart(spell->clock);
    }
    sfSprite_setTextureRect(spell->sprite, spell->rect);
}
