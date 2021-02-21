/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** black_hole
*/

#include "rpg.h"

void set_cooldown_(float res, spell_t *spell)
{
    char *str = ftoa(res, 2);
    spell->text.str = "activate";
    sfText_setString(spell->text.text, str);
}

int cooldown_black_holes(spell_t *spell)
{
    static int tmp = 0;

    spell->clock_cd.time = sfClock_getElapsedTime(spell->clock_cd.clock);
    spell->clock_cd.seconds = spell->clock_cd.time.microseconds / 1000000.0;
    if (spell->activated == 1 && tmp == 0) {
        sfClock_restart(spell->clock_cd.clock);
        tmp = 1;
        return (1);
    } else if (spell->activated == 1 && tmp == 1 &&
    spell->clock_cd.seconds > 1.5) {
        spell->activated = 2;
        sfClock_restart(spell->clock_cd.clock);
    }
    return (displays_cooldown_black(spell, &tmp));
}

int update_black_holes(spell_t *spell, sfVector2f pos,
fight_t *fight, rpg_t *rpg)
{
    if (spell->activated == 1 || spell->activated == 2) {
        if (spell->activated == 1) {
            change_position_black_hole(spell, pos);
            check_touch_ennemie_black_hole(fight, rpg, spell);
        }
        return (cooldown_black_holes(spell));
    }
    return (1);
}

void launch_black_hole(fight_t *fight, rpg_t *rpg)
{

    if (fight->spell[2].activated == 0 && fight->spell[2].tmp == 0 &&
    sfKeyboard_isKeyPressed(sfKeySpace)) {
        launch_first_black_hole(fight, fight->player.pos);
        fight->spell[2].tmp += 1;
        sfSound_play(rpg->snd_black_hole);
    }
}