/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** shield.c
*/

#include "rpg.h"

void launch_first_shield(fight_t *fight, sfVector2f player_pos)
{
    sfVector2f final_pos = {0, 0};

    fight->spell[1].pos.x = player_pos.x + 50;
    fight->spell[1].pos.x = player_pos.y + 50;
    sfSprite_setPosition(fight->spell[1].sprite, fight->spell[1].pos);
    fight->spell[1].final_pos = final_pos;
    fight->spell[1].activated = 1;
    sfClock_restart(fight->spell[1].clock_cd.clock);
}

void shield_damage_enn(fight_t *fight, rpg_t *rpg, spell_t *spell)
{
    if (rpg->status == 11) {
        if (fight->boss->in_live == 1 &&
        (spell->pos.x > fight->boss->pos.x - 200 &&
        spell->pos.x < fight->boss->pos.x + 200 &&
        spell->pos.y > fight->boss->pos.y - 150 &&
        spell->pos.y < fight->boss->pos.y + 150)) {
            fight->boss->life -= spell->damage;
            (fight->boss->life <= 0) ? (rpg->quest.scd_quest.nb_kills
            += 100) : (rpg->quest.scd_quest.nb_kills =
            rpg->quest.scd_quest.nb_kills);
        }
        fight->buttons[13].rect.width = (int){(fight->boss->life) / 40} + 2;
        sfSprite_setTextureRect(fight->buttons[13].sprite,
        fight->buttons[13].rect);
    }
}

void change_position_shield(spell_t *spell, sfVector2f pos)
{
    static int test = 0;
    sfTime time;

    if (spell->protection != 0 && spell->activated == 1 && test == 0) {
        test = 1;
        sfClock_restart(spell->clock);
    }
    if (test == 1) {
        time = sfClock_getElapsedTime(spell->clock);
        if (time.microseconds / 1000000 > 1) {
            spell->activated = 2;
            test = 0;
        }
    }
    spell->pos = (sfVector2f) {pos.x - 5, pos.y + 10};
    sfSprite_setPosition(spell->sprite, spell->pos);
}

int update_shield(spell_t *spell, sfVector2f pos, fight_t *fight, rpg_t *rpg)
{
    animation_shield(spell);
    change_position_shield(spell, pos);
    if (spell->activated == 1)
        check_touch_ennemie_shield(fight, rpg, spell);
    return (cooldown_shield(spell));
}

void launch_shield(fight_t *fight, rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) && fight->spell[1].activated == 0
    && fight->spell[1].tmp == 0) {
        launch_first_shield(fight, fight->player.pos);
        fight->spell[1].tmp += 1;
        sfSound_play(rpg->snd_shield);
    }
}
