/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_deplacements
*/

#include "rpg.h"

float set_speed(__attribute__((unused)) player_fight_t *player, spell_t *spell)
{
    if (spell[4].activated == 1)
        return (6);
    if (spell[3].activated == 1)
        return (0.5);
    return (2);
}

int return_move(player_fight_t *player, spell_t *spell)
{
    float speed = set_speed(player, spell);

    if (sfKeyboard_isKeyPressed(sfKeyQ) && player->pos.x > 10) {
        player->pos.x -= speed;
        return (move_left_fight(player));
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) && player->pos.x < 1910) {
        player->pos.x += speed;
        return (move_right_fight(player));
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ) && player->pos.y > 10) {
        player->pos.y -= speed;
        return (move_up_fight(player));
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && player->pos.y < 1040) {
        player->pos.y += speed;
        return (move_down_fight(player));
    }
    return (0);
}

int keys(player_fight_t *player, spell_t *spell)
{
    player->clocks.time = sfClock_getElapsedTime(player->clocks.clock);
    player->clocks.second = player->clocks.time.microseconds / 1000000.0;
    if (player->clocks.second > 0.01) {
        sfClock_restart(player->clocks.clock);
        return (return_move(player, spell));
    }
    return (1);
}

void animation_player_fight(player_fight_t *player, clock_s *clock,
fight_t *fight)
{
    if (keys(player, fight->spell) == 0) {
        player->rect.left = 0;
        sfSprite_setTextureRect(player->player, player->rect);
        return;
    }
    int direct = player->direct;
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->second = clock->time.microseconds / 1000000.0;
    if (clock->second > 0.06) {
        if (direct == 1 || direct == 3 || direct == 5 || direct == 7)
            (player->rect.left < 64 * 7 + 32) ? (player->rect.left += 64) :
            (player->rect.left = 64);
        sfSprite_setTextureRect(player->player, player->rect);
        sfClock_restart(clock->clock);
    }
}

void player_deplacements(player_fight_t *player, fight_t *fight)
{
    animation_player_fight(player, &player->clock, fight);
    sfSprite_setPosition(player->player, player->pos);
}