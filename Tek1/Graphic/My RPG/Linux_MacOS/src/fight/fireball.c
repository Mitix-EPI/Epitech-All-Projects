/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fireball
*/

#include "rpg.h"

void pos_rotat(sfVector2f *pos, sfVector2f player_pos, int rad, sfSprite *sprt)
{
    if (rad == 90) {
        pos->y = player_pos.y + 300;
        pos->x = player_pos.x;
        sfSprite_setRotation(sprt, rad);
    }
    if (rad == 270) {
        pos->y = player_pos.y - 300;
        pos->x = player_pos.x;
        sfSprite_setRotation(sprt, rad);
    }
    if (rad == 0) {
        pos->y = player_pos.y;
        pos->x = player_pos.x + 300;
        sfSprite_setRotation(sprt, rad);
    }
    if (rad == 180) {
        pos->y = player_pos.y;
        pos->x = player_pos.x - 300;
        sfSprite_setRotation(sprt, rad);
    }
}

void launch_first_fireball(fight_t *fight, sfVector2f player_pos)
{
    sfVector2f final_pos = {0, 0};

    if (fight->player.direct == 0 || fight->player.direct == 5)
        pos_rotat(&final_pos, player_pos, 90, fight->spell[0].sprite);
    if (fight->player.direct == 1)
        pos_rotat(&final_pos, player_pos, 270, fight->spell[0].sprite);
    if (fight->player.direct == 3)
        pos_rotat(&final_pos, player_pos, 0, fight->spell[0].sprite);
    if (fight->player.direct == 7)
        pos_rotat(&final_pos, player_pos, 180, fight->spell[0].sprite);
    fight->spell[0].pos = player_pos;
    fight->spell[0].direction = fight->player.direct;
    sfSprite_setPosition(fight->spell[0].sprite, fight->spell[0].pos);
    fight->spell[0].final_pos = final_pos;
    fight->spell[0].activated = 1;
}

void fireball_damage_player(fight_t *fight, rpg_t *rpg, spell_t *spell)
{
    if (fight->boss->in_live == 1)
        if (spell->pos.x > fight->boss->pos.x - 200 &&
        spell->pos.x < fight->boss->pos.x + 200 &&
        spell->pos.y > fight->boss->pos.y - 150 &&
        spell->pos.y < fight->boss->pos.y + 150) {
            fight->boss->life -= spell->damage;
            (fight->boss->life <= 0) ? (rpg->quest.scd_quest.nb_kills += 100) :
            (rpg->quest.scd_quest.nb_kills = rpg->quest.scd_quest.nb_kills);
        }
    fight->buttons[13].rect.width = (int){(fight->boss->life) / 40} + 2;
    sfSprite_setTextureRect(fight->buttons[13].sprite, fight->buttons[13].rect);
}

int update_fireballs(spell_t *spell, sfVector2f pos, fight_t *fight, rpg_t *rpg)
{
    if (spell->activated == 1) {
        change_position_fireball(spell, pos);
        check_touch_ennemie_fireball(fight, rpg, spell);
        return (cooldown_fireball(spell));
    }
    return (1);
}

void launch_fireball(fight_t *fight, rpg_t *rpg)
{
    if (fight->spell[0].activated == 0 && fight->spell[0].tmp == 0 &&
    sfKeyboard_isKeyPressed(sfKeySpace)) {
        launch_first_fireball(fight, fight->player.pos);
        fight->spell[0].tmp += 1;
        sfSound_play(rpg->snd_fireball);
    }
}
