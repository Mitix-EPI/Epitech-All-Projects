/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** character
*/

#include "../include/my.h"
#define GRAVITY 1.15

void move_rect(game_t *game)
{
    game->character.rect.top += 37;
    if (game->character.rect.top > 185)
        game->character.rect.top = 0;
    sfSprite_setTextureRect(game->character.hero, game->character.rect);
}

void move_animation(game_t *game)
{
    if (game->character.jump == 0) {
        game->character.time = sfClock_getElapsedTime(game->character.clck);
        game->character.seconds = game->character.time.microseconds / 1000000.0;
        if (game->character.seconds > 0.12) {
            move_rect(game);
            sfClock_restart(game->character.clck);
        }
    }
}

void sets_hero(game_t *game)
{
    character_t charac;
    char *path = "./assets/anims/run/runner.png";

    charac.pos_hero.x = 0.f;
    charac.pos_hero.y = 550.f;
    charac.jump = 0.f;
    charac.rect = (sfIntRect) {0, 0, 50, 37};
    charac.clck = sfClock_create();
    charac.hero = sfSprite_create();
    charac.t_hero = sfTexture_createFromFile(path, NULL);
    charac.vel.x = 0.f;
    charac.vel.y = 0.f;
    sfSprite_setTexture(charac.hero, charac.t_hero, sfTrue);
    sfSprite_setPosition(charac.hero, (sfVector2f) {0.f, 550.f});
    sfSprite_setTextureRect(charac.hero, charac.rect);
    sfSprite_setScale(charac.hero, (sfVector2f) {6.f, 6.f});
    game->character = charac;
}

void jump(game_t *game)
{
    sfIntRect default_rect = {0, 0, 50, 37};

    game->character.pos_hero.y += game->character.vel.y;
    if (game->character.jump == 1) {
        sfSprite_setTextureRect(game->character.hero, default_rect);
        game->character.vel.y += GRAVITY;
    }
    if (game->character.pos_hero.y >= 550) {
        game->character.vel.y = 0;
        game->character.jump = 0;
        game->character.pos_hero.y = 550;
    }
}