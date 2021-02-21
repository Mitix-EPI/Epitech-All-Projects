/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** move_and_anim_boss
*/

#include "rpg.h"

void boss_anim(fight_t *fight)
{
    sfTime time = sfClock_getElapsedTime(fight->boss->clock.clock);

    if (time.microseconds > 85000) {
        fight->boss->rect.left += 800;
        if (fight->boss->rect.left > (7 * 800)) {
            fight->boss->rect.left = 0;
            (fight->boss->rect.top == 0) ? (fight->boss->rect.top = 600) :
            (fight->boss->rect.top = 0);
        }
        sfClock_restart(fight->boss->clock.clock);
    }
    sfSprite_setTextureRect(fight->boss->enn, fight->boss->rect);
}

void move_boss_two(fight_t *fight, float truc1, float truc2)
{
    static float max = 0;
    static int tmp = 0;

    sfSprite_setPosition(fight->boss->enn, fight->boss->pos);
    if (fight->boss->pos.x - 200 <= fight->player.pos.x - 25 &&
    fight->boss->pos.x + 200 >= fight->player.pos.x + 25 &&
    fight->boss->pos.y - 150 <= fight->player.pos.y - 35 &&
    fight->boss->pos.y + 150 >= fight->player.pos.y + 35)
        if ((fight->spell[fight->player.weapon - 1].protection == 0
        || fight->spell[fight->player.weapon - 1].activated != 1)) {
            knock_back(&fight->player, &fight->player.clock,
            (sfVector2f){truc1, truc2}, tmp);
            fight->player.life -= 1;
            fight->buttons[3].rect.width = fight->player.life * 2 + 4;
            sfSprite_setTextureRect(fight->buttons[3].sprite,
            fight->buttons[3].rect);
        }
    boss_attack(fight, &max);
    boss_anim(fight);
}

void move_boss(fight_t *fight)
{
    float truc1 = 0;
    float truc2 = 0;
    float x = fight->boss->pos.x - fight->player.pos.x;
    float y = fight->boss->pos.y - fight->player.pos.y;
    float distance = sqrtf(x * x + y * y);

    if (distance > 400) {
        truc1 = (x / distance) * fight->boss->velocity;
        truc2 = (y / distance) * fight->boss->velocity;
        fight->boss->pos.x -= truc1;
        fight->boss->pos.y -= truc2;
    }
    move_boss_two(fight, truc1, truc2);
}
