/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void if_click_statue_trois(sfMouseButtonEvent event, \
sfRenderWindow *window, sprite_t *sprite, sfVector2i mouse)
{
    if (mouse.x <= croix(724, 'l', sprite) && mouse.x >= croix\
    (664, 'l', sprite) && mouse.y <= croix(870, 'h', sprite) \
    && mouse.y >= croix(800, 'h', sprite))
        sprite->cursor = 1;
    if (mouse.x <= croix(831, 'l', sprite) && mouse.x >= croix\
    (763, 'l', sprite) && mouse.y <= croix(870, 'h', sprite) \
    && mouse.y >= croix(800, 'h', sprite))
        sprite->cursor = 2;
    if (mouse.x <= croix(922, 'l', sprite) && mouse.x >= croix\
    (865, 'l', sprite) && mouse.y <= croix(870, 'h', sprite) \
    && mouse.y >= croix(800, 'h', sprite))
        sprite->cursor = 3;
    if_click_statue_tree(event, window, sprite, mouse);
    if (mouse.x < croix(624, 'l', sprite) || mouse.x > croix\
    (1061, 'l', sprite) || mouse.y < croix(1015, 'h', sprite)) {
        if (sprite->cursor != 0)
            pos_tower(sprite, mouse);
    }
}

void if_click_statue_tree(sfMouseButtonEvent event, \
sfRenderWindow *window, sprite_t *sprite, sfVector2i mouse)
{
    if (mouse.x <= croix(1013, 'l', sprite) && mouse.x >= croix\
    (951, 'l', sprite) && mouse.y <= croix(870, 'h', sprite) \
    && mouse.y >= croix(800, 'h', sprite))
        sprite->cursor = 4;
    if (mouse.x <= croix(1013, 'l', sprite) && mouse.x >= croix\
    (951, 'l', sprite) && mouse.y <= croix(870, 'h', sprite) \
    && mouse.y >= croix(800, 'h', sprite))
        sprite->cursor = 4;
    if (mouse.x <= croix(765, 'l', sprite) && mouse.x >= croix\
    (717, 'l', sprite) && mouse.y <= croix(958, 'h', sprite) \
    && mouse.y >= croix(916, 'h', sprite))
        sprite->cursor = 5;
    if (mouse.x <= croix(954, 'l', sprite) && mouse.x >= croix\
    (910, 'l', sprite) && mouse.y <= croix(955, 'h', sprite) \
    && mouse.y >= croix(906, 'h', sprite))
        sprite->cursor = 6;
}

void click_statue_trois(sfMouseButtonEvent event, \
sfRenderWindow *window, sprite_t *sprite, sfVector2i mouse)
{
    if (sprite->pause == 0 && event.button != sfMouseRight) {
        if_click_statue_trois(event, window, sprite, mouse);
        click_pause(event, window, sprite, mouse);
    }
    else if (sprite->pause != 0) {
        click_menu_pause(event, window, sprite, mouse);
    }
    if (event.button == sfMouseRight) {
        delete_tow(sprite, mouse);
    }
}

void click_statue_six(sfMouseButtonEvent event, \
sfRenderWindow *window, sprite_t *sprite, sfVector2i mouse)
{
    if (mouse.x <= croix(630, 'l', sprite) && mouse.x >= croix\
    (350, 'l', sprite) && mouse.y <= croix(885, 'h', sprite) \
    && mouse.y >= croix(740, 'h', sprite)) {
        sprite->level = 1;
        sprite->statue = 3;
        initialise_level(sprite, window);
    }
    if (mouse.x <= croix(1084, 'l', sprite) && mouse.x >= croix\
    (841, 'l', sprite) && mouse.y <= croix(885, 'h', sprite) \
    && mouse.y >= croix(740, 'h', sprite)) {
        sprite->level = 2;
        sprite->statue = 3;
        initialise_level(sprite, window);
    }
    if (mouse.x <= croix(1558, 'l', sprite) && mouse.x >= croix\
    (1315, 'l', sprite) && mouse.y <= croix(885, 'h', sprite) \
    && mouse.y >= croix(740, 'h', sprite)) {
        sprite->level = 3;
        sprite->statue = 3;
        initialise_level(sprite, window);
    }
}