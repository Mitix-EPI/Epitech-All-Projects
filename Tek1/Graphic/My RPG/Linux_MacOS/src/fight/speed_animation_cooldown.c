/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** speed_animation_cooldown
*/

#include "rpg.h"

void animation_speed(spell_t *spell)
{
    sfTime time = sfClock_getElapsedTime(spell->clock);
    float second = time.microseconds / 1000000.0;
    if (second > 0.09) {
        if (spell->rect.left < 240 - 60) {
            spell->rect.left += 60;
        } else {
            spell->rect.left = 0;
            (spell->rect.top < 300 - 60) ? (spell->rect.top += 60) :
            (spell->rect.top = 0);
        }
        sfClock_restart(spell->clock);
    }
    sfSprite_setTextureRect(spell->sprite, spell->rect);
}

void set_cooldown_speed(float res, spell_t *spell)
{
    char *str = ftoa(res, 2);

    sfText_setString(spell->text.text, str);
    spell->text.str = "activate";
}

void display_cooldown_speed(float second, spell_t *spell)
{
    if (second < spell->sec)
        set_cooldown_speed(spell->sec - second, spell);
    else
        spell->text.str = NULL;
}

int cooldown_speed(spell_t *spell)
{
    spell->clock_cd.time = sfClock_getElapsedTime(spell->clock_cd.clock);
    spell->clock_cd.seconds = spell->clock_cd.time.microseconds / 1000000.0;
    if (spell->activated == 1 && spell->clock_cd.seconds
    > 3.5 && spell->tmp2 == 0) {
        spell->activated = 2;
        spell->tmp2 = 1;
        return (1);
    }
    if (spell->activated == 2)
        display_cooldown_speed(spell->clock_cd.seconds, spell);
    if (spell->activated == 2 && spell->clock_cd.seconds >= spell->sec) {
        spell->activated = 0;
        spell->tmp2 = 0;
        sfClock_restart(spell->clock_cd.clock);
        return (0);
    }
    return (1);
}