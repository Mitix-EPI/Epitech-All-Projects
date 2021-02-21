/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** starting_level
*/

#include "../my_tower.h"

void display_loading(sprite_t *sprite, sfRenderWindow *window)
{
    sfVector2f pos;
    sfTexture *texture = sfTexture_createFromFile("sprite/loading.png", \
    NULL);

    pos.x = croix(1, 'l', sprite);
    pos.y = croix(1, 'h', sprite);
    sprite->loading = sfSprite_create();
    sfSprite_setTexture(sprite->loading, texture, sfTrue);
    sfSprite_setPosition(sprite->loading, (sfVector2f) {0, 0});
    sfSprite_setScale(sprite->loading, pos);
    sfRenderWindow_drawSprite(window, sprite->loading, NULL);
    sfRenderWindow_display(window);
}

void initialise_level(sprite_t *sprite, sfRenderWindow *window)
{
    display_loading(sprite, window);
    update_map(sprite);
    update_map_(sprite);
    update_nb_enn(sprite);
    set_ennemies(sprite);
    select_type_of_ennemies(sprite);
    update_type_enn(sprite);
    set_towers(sprite);
    sfCircleShape_setFillColor(sprite->circle, sfTransparent);
    sfCircleShape_setOutlineThickness(sprite->circle, 2);
    sfCircleShape_setOutlineColor(sprite->circle, sfBlack);
    sfCircleShape_setRadius(sprite->circle, croix(200, 'l', sprite));
    sfCircleShape_setOrigin(sprite->circle, (sfVector2f){croix\
    (200, 'l', sprite), croix(200, 'l', sprite)});
}