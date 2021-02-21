/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void analyse_events(sfRenderWindow *window, sfEvent event, sprite_t *sprite)
{
    if (event.type == sfEvtClosed || event.type == sfEvtKeyPressed \
    && event.key.code == sfKeyEscape) {
        close_windows(window, sprite);
    }
    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event.mouseButton, window, sprite);
    if (event.type == sfEvtTextEntered) {
        key_press(window, event, sprite);
    }
    if (sprite->statue == 3)
        if (event.key.code == sfKeyP && event.type == sfEvtKeyPressed) {
            sprite->cursor = 0;
            sprite->pause = 1;
        }
    sfMusic_setVolume(sprite->music_chill, sprite->volume);
    sfMusic_setVolume(sprite->music_hard, sprite->volume);
}

void global_event(sfRenderWindow *window, sfEvent event, sprite_t *sprite)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        analyse_events(window, event, sprite);
    }
}