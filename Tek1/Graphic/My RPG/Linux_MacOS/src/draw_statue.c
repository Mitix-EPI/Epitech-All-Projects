/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_statue
*/

#include "my.h"
#include "rpg.h"
#include "rafik.h"

void update_count(scd_quest_t *quest)
{
    if (quest->nb_win < 3) {
        sfText_setString(quest->text[0].text, my_strcat(quest->text[0].str, \
        int_to_string(quest->nb_win)));
    }
    if (quest->nb_kills < 15) {
        sfText_setString(quest->text[1].text, my_strcat(quest->text[1].str, \
        int_to_string(quest->nb_kills)));
    } else if (quest->nb_kills < 30) {
        sfText_setString(quest->text[2].text, my_strcat(quest->text[2].str, \
        int_to_string(quest->nb_kills)));
    }
}

void display_seconds_quests(sfRenderWindow *win, scd_quest_t *quest)
{
    if (!sfKeyboard_isKeyPressed(sfKeyZ) && !sfKeyboard_isKeyPressed(sfKeyS) &&
    !sfKeyboard_isKeyPressed(sfKeyQ) && !sfKeyboard_isKeyPressed(sfKeyD)) {
        update_count(quest);
        if (quest->nb_win < 3) {
            sfSprite_setPosition(quest->sprite, quest->pos1);
            sfRenderWindow_drawSprite(win, quest->sprite, NULL);
            sfRenderWindow_drawText(win, quest->text[0].text, NULL);
        }
        if (quest->nb_kills < 15) {
            sfSprite_setPosition(quest->sprite, quest->pos2);
            sfRenderWindow_drawSprite(win, quest->sprite, NULL);
            sfRenderWindow_drawText(win, quest->text[1].text, NULL);
        } else if (quest->nb_kills < 30) {
            sfSprite_setPosition(quest->sprite, quest->pos3);
            sfRenderWindow_drawSprite(win, quest->sprite, NULL);
            sfRenderWindow_drawText(win, quest->text[2].text, NULL);
        }
    }
}

void display_message(rpg_t *rpg, sfRenderWindow *win)
{
    sfIntRect rect = {0, 0, 1920, 1080};
    if (rpg->quest.message > 0) {
        if (rpg->quest.message == 2)
            rect.top = 1080;
        sfSprite_setTextureRect(rpg->quest.msg, rect);
        sfRenderWindow_drawSprite(win, rpg->quest.msg, NULL);
    }
}

void draw_third_status(rpg_t *rpg, sfRenderWindow *win, game_obj_t *obj)
{
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, obj->sprite, NULL);
    display_item(win, rpg, obj);
    sfRenderWindow_drawSprite(win, rpg->player.sprite, NULL);
    sfRenderWindow_drawSprite(win, rpg->perspec.sprite, NULL);
    sfRenderWindow_drawSprite(win, rpg->menu[18].sprite, NULL);
    if (rpg->level == 22)
        sfRenderWindow_drawSprite(win, rpg->quest.arrow, NULL);
    display_inventory(win, rpg);
    display_seconds_quests(win, &rpg->quest.scd_quest);
    display_message(rpg, win);
    for (size_t index = 0; index < PARICULE_MAX; index++)
        display_particle(win, &rpg->screen->particle[index], \
        rpg->screen->particle_environment.circle_shape);
    sfRenderWindow_display(win);
}

void draw_statue(rpg_t *rpg, sfRenderWindow *win, game_obj_t *obj)
{
    if (rpg->status == 0)
        draw_menu(rpg, win);
    if (rpg->status == 3) {
        draw_third_status(rpg, win, obj);
    }
    draw_statues(rpg, win, obj);
}