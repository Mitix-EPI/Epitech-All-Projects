/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** global_event
*/

#include "my.h"
#include "rpg.h"
#include "rafik.h"

void enns_loop(float speed, ennemies_t *enns)
{
    for (int i = 0; i < 10; i++) {
        enns[i].velocity = generate_random(speed, speed + 50) / 10;
        enns[i].velocity /= 10;
    }
}

void upgrade_ennemies(ennemies_t *enns, int act, fight_t *fight)
{
    if (act == 1) {
        enns_loop(50, enns);
        fight->max_enn = 5;
        return;
    }
    if (act == 2) {
        enns_loop(65, enns);
        fight->max_enn = 7;
    } else if (act == 3) {
        enns_loop(80, enns);
        fight->max_enn = 8;
    } else {
        enns_loop(90, enns);
        fight->max_enn = 10;
    }
}

void choice_deplacement(game_obj_t *background, rpg_t *rpg)
{
    rpg->clock_rect.time = sfClock_getElapsedTime(rpg->clock_rect.clock);
    rpg->clock_rect.seconds = rpg->clock_rect.time.microseconds / 1000000.0;
    if (rpg->clock_rect.seconds > 0.01) {
        if (sfKeyboard_isKeyPressed(sfKeyQ)) {
            move_rect(background, (sfVector2f) {-speed(), 0}, rpg);
        } if (sfKeyboard_isKeyPressed(sfKeyD)) {
            move_rect(background, (sfVector2f) {speed(), 0}, rpg);
        } if (sfKeyboard_isKeyPressed(sfKeyZ)) {
            move_rect(background, (sfVector2f) {0, -speed()}, rpg);
        } if (sfKeyboard_isKeyPressed(sfKeyS)) {
            move_rect(background, (sfVector2f) {0, speed()}, rpg);
        }
        sfClock_restart(rpg->clock_rect.clock);
    }
}

void global_event_statue_three(rpg_t *rpg, game_obj_t *background)
{
    if (rpg->status == 3) {
        choice_deplacement(background, rpg);
        player_deplacement(rpg);
        fights_spawns(rpg, background);
        handling_items(rpg);
        upgrade_ennemies(rpg->fight->enns, rpg->quest.act, rpg->fight);
        generic_function_bg_quest(rpg);
    }
}

void display_fps(rpg_t *rpg)
{
    static int first = 1;
    static sfClock *clock;
    static int fps = 0;
    static char *str = NULL;

    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    sfTime elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1) {
        str = my_strcat("SIDONA RPG (", int_to_char(fps));
        str = my_strcat(str, "fps)");
        sfRenderWindow_setTitle(rpg->win, str);
        fps = 0;
        sfClock_restart(clock);
    } else
        fps++;
}