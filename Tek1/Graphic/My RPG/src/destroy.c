/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_rpg
*/

#include "my.h"
#include "rpg.h"

void destroy_four(__attribute__((unused)) game_obj_t *obj, rpg_t *rpg)
{
    sfSound_destroy(rpg->snd_win_fight);
    sfClock_destroy(rpg->end.clock.clock);
    sfSprite_destroy(rpg->end.msg);
}

void destroy_three(__attribute__((unused)) game_obj_t *obj, rpg_t *rpg)
{
    sfSprite_destroy(rpg->tuto.sprite);
    sfTexture_destroy(rpg->tuto.texture);
    sfSprite_destroy(rpg->tuto.friend);
    sfTexture_destroy(rpg->tuto.friend_t);
    sfClock_destroy(rpg->tuto.clock);
    sfSprite_destroy(rpg->player.sprite);
    sfTexture_destroy(rpg->player.texture);
    sfClock_destroy(rpg->player.clock.clock);
    sfSound_destroy(rpg->snd_win);
    sfSound_destroy(rpg->snd_loose);
    sfSound_destroy(rpg->snd_clic);
    sfSound_destroy(rpg->snd_menu);
    sfSound_destroy(rpg->snd_tuto);
    sfSound_destroy(rpg->snd_main_music);
    sfSound_destroy(rpg->snd_main_music_fight);
    sfSound_destroy(rpg->snd_fireball);
    sfSound_destroy(rpg->snd_shield);
    sfSound_destroy(rpg->snd_black_hole);
    sfSound_destroy(rpg->snd_heal);
    sfSound_destroy(rpg->snd_speed);
}

void destroy_two(game_obj_t *obj, rpg_t *rpg)
{
    sfTexture_destroy(rpg->quest.msg_t);
    sfSprite_destroy(rpg->quest.invent_s);
    sfSprite_destroy(rpg->fight->background);
    sfSprite_destroy(rpg->fight->player.player);
    sfTexture_destroy(rpg->fight->player.player_texture);
    sfClock_destroy(rpg->fight->player.clock2.clock);
    sfClock_destroy(rpg->fight->player.clock.clock);
    for (int i = 0; i < 10; i++) {
        sfClock_destroy(rpg->fight->enns[i].clock.clock);
        sfTexture_destroy(rpg->fight->enns[i].enn_texture);
        sfSprite_destroy(rpg->fight->enns[i].enn);
    }
    sfSprite_destroy(rpg->fight->inventory.sprite);
    sfTexture_destroy(rpg->fight->inventory.texture);
    for (int i = 0; i < 3; i++) {
        sfSprite_destroy(rpg->fight->spell[i].sprite);
        sfTexture_destroy(rpg->fight->spell[i].texture);
        sfClock_destroy(rpg->fight->spell[i].clock);
    }
    destroy_three(obj, rpg);
}

void destroy(game_obj_t *obj, rpg_t *rpg)
{
    sfClock_destroy(rpg->clock->clock);
    for (int i = 0; i < 140; i++)
        free(rpg->map[i]);
    free(rpg->map);
    for (int i = 0; i < 10; i += 1) {
        sfSprite_destroy(rpg->fight->buttons[i].sprite);
    sfTexture_destroy(rpg->fight->buttons[i].texture);
    }
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
    sfSprite_destroy(rpg->menu->sprite);
    sfSprite_destroy(rpg->quest.msg);
    sfSprite_destroy(rpg->quest.sprite);
    sfSprite_destroy(rpg->quest.arrow);
    sfTexture_destroy(rpg->quest.arr_t);
    sfTexture_destroy(rpg->quest.invent_t);
    destroy_two(obj, rpg);
}