/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clics_handlings
*/

#include "rpg.h"
#include "rafik.h"
#include "my.h"

void click_menu_zero(rpg_t *rpg, sfVector2i mouse)
{
    if (mouse.x > 152 && mouse.x < 584 &&
    mouse.y > 200 && mouse.y < 309.2)
        rpg->menu_status = 4;
    if (mouse.x > 152 && mouse.x < 584 &&
    mouse.y > 400 && mouse.y < 509.2)
        rpg->menu_status = 5;
    if (mouse.x > 152 && mouse.x < 584 &&
    mouse.y > 600 && mouse.y < 709.2)
        rpg->menu_status = 1;
    if (mouse.x > 152 && mouse.x < 584 &&
    mouse.y > 800 && mouse.y < 909.2)
        sfRenderWindow_close(rpg->win);
}

void click_save_two(rpg_t *rpg, sfVector2i mouse, game_obj_t *obj)
{
    if (mouse.x > 743 && mouse.x < 1177 &&
    mouse.y > 475 && mouse.y < 584.2) {
        rpg->save = 3;
        stop_all_music(rpg);
        sfSound_play(rpg->snd_main_music);
        rpg->status = 3;
        if (rpg->menu_status == 5)
            init_save(rpg, obj);
        if (rpg->menu_status == 4)
            rpg->tuto.executed = 0;
        if (rpg->tuto.executed == 0) {
            stop_all_music(rpg);
            sfSound_play(rpg->snd_tuto);
            rpg->status = 7;
            rpg->tuto.executed = 1;
        }
    }
}

void click_save_three(rpg_t *rpg, sfVector2i mouse, game_obj_t *obj)
{
    if (mouse.x > 743 && mouse.x < 1177 &&
    mouse.y > 700 && mouse.y < 809.2) {
        rpg->save = 1;
        stop_all_music(rpg);
        sfSound_play(rpg->snd_main_music);
        rpg->status = 3;
        if (rpg->menu_status == 5)
            init_save(rpg, obj);
        if (rpg->menu_status == 4)
            rpg->tuto.executed = 0;
        if (rpg->tuto.executed == 0) {
            stop_all_music(rpg);
            sfSound_play(rpg->snd_tuto);
            rpg->status = 7;
            rpg->tuto.executed = 1;
        }
    }
    if (mouse.x > 1510 && mouse.x < 1920 &&
    mouse.y > 910 && mouse.y < 1080)
        rpg->menu_status = 0;
}

void click_start_menu(rpg_t *rpg, sfVector2i mouse, game_obj_t *obj,
int nb __attribute__((unused)))
{
    if (mouse.x > 743 && mouse.x < 1177 &&
    mouse.y > 250 && mouse.y < 359.2) {
        rpg->save = 2;
        stop_all_music(rpg);
        sfSound_play(rpg->snd_main_music);
        rpg->status = 3;
        if (rpg->menu_status == 5)
            init_save(rpg, obj);
        if (rpg->menu_status == 4)
            rpg->tuto.executed = 0;
        if (rpg->tuto.executed == 0) {
            stop_all_music(rpg);
            sfSound_play(rpg->snd_tuto);
            rpg->status = 7;
            rpg->tuto.executed = 1;
        }
    }
    click_save_two(rpg, mouse, obj);
    click_save_three(rpg, mouse, obj);
}

void check_plus_minus(rpg_t *rpg, sfVector2i mouse __attribute__((unused)))
{
    if (rpg->music_volume > 100)
        rpg->music_volume = 100;
    if (rpg->music_volume < 0)
        rpg->music_volume = 0;
    if (rpg->sound_volume > 100)
        rpg->sound_volume = 100;
    if (rpg->sound_volume < 0)
        rpg->sound_volume = 0;
    if (rpg->fps < 60)
        rpg->fps = 60;
    if (rpg->fps > 120)
        rpg->fps = 120;
    sfRenderWindow_setFramerateLimit(rpg->win, rpg->fps);
    sfText_setString(rpg->text[8].text, int_to_char(rpg->fps));
    sfText_setString(rpg->text[11].text, int_to_char(rpg->music_volume));
    sfText_setString(rpg->text[13].text, int_to_char(rpg->sound_volume));
}