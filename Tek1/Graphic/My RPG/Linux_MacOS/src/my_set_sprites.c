/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_rpg
*/

#include "my.h"
#include "rpg.h"

void my_set_sprites_two(game_obj_t *obj, rpg_t *rpg)
{
    obj->texture =
    sfTexture_createFromFile("assets/maps/map_with_spawns.png", NULL);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setScale(obj->sprite, (sfVector2f) {2, 2});
    obj->pos = (sfVector2f) {0, 0};
    obj->rect = (sfIntRect) {200, 100, 1920, 1080};
    rpg->quest.x = obj->rect.left;
    rpg->quest.y = obj->rect.top;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    set_seconds_quests(&rpg->quest.scd_quest);
}

void my_set_sprites(game_obj_t *obj, rpg_t *rpg)
{
    rpg->screen = malloc(sizeof(screen_t));
    init_particle_environment(&rpg->screen->particle_environment, \
    (sfVector2f){PARICULE_ANGLE_MIN, PARICULE_ANGLE_MAX}, \
    (sfVector2f){GRAVITY_X, GRAVITY_Y}, ALPHA);
    set_menu_sprites(rpg);
    create_perspec(&rpg->perspec);
    init_variables_for_particules(rpg);
    rpg->fight = init_variables_for_fights(rpg->fight);
    set_menu_sprites(rpg);
    rpg->delete_me_too =
    sfTexture_createFromFile("assets/sprites/tilemap.png", NULL);
    rpg->delete_me_too =
    sfTexture_createFromFile("assets/maps/map_with_spawns.png", NULL);
    rpg->delete_me = sfSprite_create();
    sfSprite_setTexture(rpg->delete_me, rpg->delete_me_too, sfTrue);
    sfSprite_setScale(rpg->delete_me, (sfVector2f) {2, 2});
    my_set_sprites_two(obj, rpg);
}