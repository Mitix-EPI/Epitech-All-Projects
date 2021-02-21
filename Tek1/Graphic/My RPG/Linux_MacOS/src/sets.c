/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** sets
*/

#include "rpg.h"

void my_set_ints(rpg_t *rpg, clock_s *clock)
{
    clock->clock = sfClock_create();
    rpg->clock_rect.clock = sfClock_create();
    rpg->status = 0;
    rpg->menu_status = 0;
    rpg->fps = 90;
    sfRenderWindow_setFramerateLimit(rpg->win, rpg->fps);
    rpg->player.direct = 0;
    rpg->sound_volume = 20;
    rpg->music_volume = 20;
    rpg->map = get_map();
    rpg->save = 0;
    rpg->level = 22;
    set_rpg_tuto(&rpg->tuto);
    init_end_script(&rpg->end);
    set_quest(&rpg->quest);
    set_musics(rpg);
}

void set_rpg_tuto(tuto_t *tuto)
{
    char path[] = "assets/sprites/friend.png";
    char path2[] = "assets/sprites/tuto.png";

    tuto->action = 0;
    tuto->executed = 0;
    tuto->friend = sfSprite_create();
    tuto->friend_t = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(tuto->friend, tuto->friend_t, sfTrue);
    tuto->clock = sfClock_create();
    tuto->sprite = sfSprite_create();
    tuto->texture = sfTexture_createFromFile(path2, NULL);
    sfSprite_setTexture(tuto->sprite, tuto->texture, sfTrue);
    tuto->rect.top = 0;
    tuto->rect.height = 0;
    tuto->rect.left = 0;
    tuto->rect.width = 0;
    sfSprite_setTextureRect(tuto->sprite, tuto->rect);
}

void set_quest_data(quest_t *quest)
{
    quest->pos.x = 195;
    quest->pos.y = 84;
    quest->rect.height = 30;
    quest->rect.width = 30;
    quest->rect.left = 0;
    quest->rect.top = 0;
    quest->act = 1;
    quest->tmp = 0;
    quest->message = 0;
}

void set_quest(quest_t *quest)
{
    char path[] = "assets/sprites/items.png";
    char path2[] = "assets/sprites/msg.png";
    char path3[] = "assets/sprites/inventory_sheet.png";

    quest->sprite = sfSprite_create();
    quest->items = sfTexture_createFromFile(path, NULL);
    quest->msg = sfSprite_create();
    quest->msg_t = sfTexture_createFromFile(path2, NULL);
    sfSprite_setTexture(quest->msg, quest->msg_t, sfTrue);
    set_quest_data(quest);
    sfSprite_setTexture(quest->sprite, quest->items, sfTrue);
    sfSprite_setTextureRect(quest->sprite, quest->rect);
    create_arrow(quest);
    quest->invent_s = sfSprite_create();
    quest->invent_t = sfTexture_createFromFile(path3, NULL);
    quest->invent_rect = (sfIntRect) {0, 0, 1920, 1080};
    sfSprite_setTexture(quest->invent_s, quest->invent_t, sfTrue);
    sfSprite_setScale(quest->invent_s, (sfVector2f) {0.5, 0.5});
    sfSprite_setPosition(quest->invent_s, (sfVector2f) {950, 10});
}
