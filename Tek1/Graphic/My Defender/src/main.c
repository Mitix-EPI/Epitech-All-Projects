/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

int main_game(void)
{
    sfRenderWindow *window = windows(1920, 1080);
    sfEvent event;
    sprite_t *sprite = malloc(sizeof(struct sprite_c));
    clock_s clock;

    my_set_sprites(sprite, window, &clock);
    int_value(sprite, &clock);
    while (sfRenderWindow_isOpen(window)) {
        global_event(window, event, sprite);
        clock_event(window, sprite, clock);
        draw_statue(window, sprite);
    }
    destroy_sprite(window, sprite);
    return (0);
}

int main(int ac, char **av)
{
    if (ac > 2)
        return (84);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        man();
        return (0);
    }
    main_game();
}