/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** my_game
*/

#include "../include/my.h"

void create_sprite_game(window_t *w)
{
    w->sbg0 = sfSprite_create();
    w->sbg1 = sfSprite_create();
    w->sbg2 = sfSprite_create();
    w->sscope = sfSprite_create();
    w->stmax = sfSprite_create();
    w->sufo = sfSprite_create();
    w->slife = sfSprite_create();
}

void create_texture_and_sprite(window_t *w)
{
    sfVector2f size = {0.25f, 0.25f};
    sfVector2f size1 = {2.3f, 2.3f};
    create_sprite_game(w);
    w->tbg1 = sfTexture_createFromFile("assets/boxes.png", NULL);
    w->tbg2 = sfTexture_createFromFile("assets/wheel.png", NULL);
    w->tscope = sfTexture_createFromFile("assets/scope_sheet.png", NULL);
    w->ttmax = sfTexture_createFromFile("assets/tmax_sheet.png", NULL);
    w->tufo = sfTexture_createFromFile("assets/ovni.png", NULL);
    w->tlife = sfTexture_createFromFile("assets/life_sprite_sheet.png", NULL);
    sfSprite_setTexture(w->sbg0, w->tbg0, sfTrue);
    sfSprite_setTexture(w->sbg1, w->tbg1, sfTrue);
    sfSprite_setTexture(w->sbg2, w->tbg2, sfTrue);
    sfSprite_setTexture(w->sscope, w->tscope, sfTrue);
    sfSprite_setScale(w->sscope, size);
    sfSprite_setTexture(w->stmax, w->ttmax, sfTrue);
    sfSprite_setScale(w->stmax, size1);
    sfSprite_setTexture(w->sufo, w->tufo, sfTrue);
    w->str_score = "0";
}

void my_draw_game(sfRenderWindow *window, window_t *w)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, w->sbg0, NULL);
    sfRenderWindow_drawSprite(window, w->sbg1, NULL);
    my_display_jul(window, w);
    my_display_ufo(window, w);
    sfRenderWindow_drawSprite(window, w->sbg2, NULL);
    my_display_life(window, w);
    my_pointer(window, w);
    sfRenderWindow_display(window);
}

void destroy_texture_and_sprite(window_t *w)
{
    sfSprite_destroy(w->sbg1);
    sfSprite_destroy(w->sbg2);
    sfSprite_destroy(w->sscope);
    sfSprite_destroy(w->stmax);
    sfSprite_destroy(w->sufo);
    sfSprite_destroy(w->slife);
    sfTexture_destroy(w->tbg1);
    sfTexture_destroy(w->tbg2);
    sfTexture_destroy(w->tscope);
    sfTexture_destroy(w->ttmax);
    sfTexture_destroy(w->tufo);
    sfTexture_destroy(w->tlife);
    sfClock_destroy(w->clock);
}

int run_window(sfRenderWindow *window, window_t *w)
{
    create_texture_and_sprite(w);
    set_animations_variables(window, w);
    while (sfRenderWindow_isOpen(window) && w->life > 0) {
        while (sfRenderWindow_pollEvent(window, &w->evt)) {
            if (game_event(window, w) == 0)
                return (0);
        }
        my_draw_game(window, w);
    }
    destroy_texture_and_sprite(w);
    my_try_again(window, w);
    return (0);
}