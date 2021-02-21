/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** cooldown_fireball
*/

#include "rpg.h"

void set_cooldown(float res, spell_t *spell)
{
    char *str = ftoa(res, 2);

    sfText_setString(spell->text.text, str);
    spell->text.str = "activate";
}

void display_cooldown_fireball(float second, spell_t *spell)
{
    if (second < spell->sec)
        set_cooldown(spell->sec - second, spell);
    else
        spell->text.str = NULL;
}

int cooldown_fireball(spell_t *spell)
{
    static int tmp = 0;

    spell->clock_cd.time = sfClock_getElapsedTime(spell->clock_cd.clock);
    spell->clock_cd.seconds = spell->clock_cd.time.microseconds / 1000000.0;
    if (spell->activated == 1 && tmp == 0) {
        sfClock_restart(spell->clock_cd.clock);
        tmp = 1;
        return (1);
    }
    display_cooldown_fireball(spell->clock_cd.seconds, spell);
    if (spell->clock_cd.seconds >= spell->sec) {
        spell->activated = 0;
        tmp = 0;
        sfClock_restart(spell->clock_cd.clock);
        return (0);
    }
    return (1);
}
