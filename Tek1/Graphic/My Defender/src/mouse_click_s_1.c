/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void two_firsts_screen_size_click_statue_un(sfMouseButtonEvent event, \
sfRenderWindow *window, sprite_t *sprite, sfVector2i mouse)
{
    if (mouse.x <= croix(449, 'l', sprite) && mouse.x >= croix\
    (196, 'l', sprite) && mouse.y <= croix(324, 'h', sprite) \
    && mouse.y >= croix(210, 'h', sprite)) {
        sprite->hight = 1920;
        sprite->weidth = 1080;
        sfRenderWindow_destroy(window);
        window = windows(1920, 1080);
    }
    if (mouse.x <= croix(772, 'l', sprite) && mouse.x >= croix\
    (510, 'l', sprite) && mouse.y <= croix(332, 'h', sprite) \
    && mouse.y >= croix(212, 'h', sprite)) {
        sprite->hight = 1856;
        sprite->weidth = 1392;
        sfRenderWindow_destroy(window);
        window = windows(1856, 1392);
    }
}

void two_next_screen_size_click_statue_un(sfMouseButtonEvent event, \
sfRenderWindow *window, sprite_t *sprite, sfVector2i mouse)
{
    if (mouse.x <= croix(1081, 'l', sprite) && mouse.x >= croix\
    (822, 'l', sprite) && mouse.y <= croix(332, 'h', sprite) \
    && mouse.y >= croix(212, 'h', sprite)) {
        sprite->hight = 1400;
        sprite->weidth = 1050;
        sfRenderWindow_destroy(window);
        window = windows(1400, 1050);
    }
    if (mouse.x <= croix(1421, 'l', sprite) && mouse.x >= croix\
    (1154, 'l', sprite) && mouse.y <= croix(332, 'h', sprite) \
    && mouse.y >= croix(212, 'h', sprite)) {
        sprite->hight = 1280;
        sprite->weidth = 1024;
        sfRenderWindow_destroy(window);
        window = windows(1280, 1024);
    }
}

void last_screen_size_click_statue_un(sfMouseButtonEvent event, \
sfRenderWindow *window, sprite_t *sprite, sfVector2i mouse)
{
    if (mouse.x <= croix(1756, 'l', sprite) && mouse.x >= croix\
    (1486, 'l', sprite) && mouse.y <= croix(332, 'h', sprite) \
    && mouse.y >= croix(212, 'h', sprite)) {
        sprite->hight = 800;
        sprite->weidth = 600;
        sfRenderWindow_destroy(window);
        window = windows(800, 600);
    }
}

void music_click_statue_un(sfMouseButtonEvent event, \
sfRenderWindow *window, sprite_t *sprite, sfVector2i mouse)
{
    if (mouse.x <= croix(814, 'l', sprite) && mouse.x >= croix\
    (508, 'l', sprite) && mouse.y <= croix(570, 'h', sprite) \
    && mouse.y >= croix(452, 'h', sprite)) {
        sfMusic_stop(sprite->music_hard);
        sfMusic_play(sprite->music_chill);
        sfMusic_setVolume(sprite->music_chill, 50);
        sfMusic_setLoop(sprite->music_chill, sfTrue);
    }
    if (mouse.x <= croix(1301, 'l', sprite) && mouse.x >= croix\
    (994, 'l', sprite) && mouse.y <= croix(578, 'h', sprite) \
    && mouse.y >= croix(448, 'h', sprite)) {
        sfMusic_stop(sprite->music_chill);
        sfMusic_play(sprite->music_hard);
        sfMusic_setVolume(sprite->music_hard, 50);
        sfMusic_setLoop(sprite->music_hard, sfTrue);
    }
}

void click_statue_un(sfMouseButtonEvent event, \
sfRenderWindow *window, sprite_t *sprite, sfVector2i mouse)
{
    two_firsts_screen_size_click_statue_un(event, window, sprite, mouse);
    two_next_screen_size_click_statue_un(event, window, sprite, mouse);
    last_screen_size_click_statue_un(event, window, sprite, mouse);
    music_click_statue_un(event, window, sprite, mouse);
}