/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** others_functions_black_hole
*/

#include "rpg.h"

void launch_first_black_hole(fight_t *fight, sfVector2f player_pos)
{
    sfVector2f final_pos = {0, 0};

    if (fight->player.direct == 0 || fight->player.direct == 5)
        pos_rotat_(&final_pos, player_pos, 90, fight->spell[2].sprite);
    if (fight->player.direct == 1)
        pos_rotat_(&final_pos, player_pos, 270, fight->spell[2].sprite);
    if (fight->player.direct == 3)
        pos_rotat_(&final_pos, player_pos, 0, fight->spell[2].sprite);
    if (fight->player.direct == 7)
        pos_rotat_(&final_pos, player_pos, 180, fight->spell[2].sprite);
    fight->spell[2].pos.x = player_pos.x;
    fight->spell[2].pos.y = player_pos.y - 4;
    fight->spell[2].direction = fight->player.direct;
    sfSprite_setPosition(fight->spell[2].sprite, fight->spell[2].pos);
    fight->spell[2].final_pos = final_pos;
    fight->spell[2].activated = 1;
}

void change_position_black_hole(spell_t *spell,
__attribute__((unused)) sfVector2f pos)
{
    animation_black_hole(spell);
    if (spell->direction == 0 || spell->direction == 5)
        spell->pos.y += 5;
    if (spell->direction == 1)
        spell->pos.y -= 5;
    if (spell->direction == 3)
        spell->pos.x += 5;
    if (spell->direction == 7)
        spell->pos.x -= 5;
    sfSprite_setPosition(spell->sprite, spell->pos);
}

void black_hole_damage_player(fight_t *fight, rpg_t *rpg, spell_t *spell)
{
    if (fight->boss->in_live == 1)
        if (spell->pos.x > fight->boss->pos.x - 200 &&
        spell->pos.x < fight->boss->pos.x + 200 &&
        spell->pos.y > fight->boss->pos.y - 150 &&
        spell->pos.y < fight->boss->pos.y + 150) {
            fight->boss->life -= 1;
            (fight->boss->life <= 0) ? (rpg->quest.scd_quest.nb_kills += 100) :
            (rpg->quest.scd_quest.nb_kills = rpg->quest.scd_quest.nb_kills);
        }
    fight->buttons[13].rect.width = (int){(fight->boss->life) / 40} + 2;
    sfSprite_setTextureRect(fight->buttons[13].sprite, fight->buttons[13].rect);
}
