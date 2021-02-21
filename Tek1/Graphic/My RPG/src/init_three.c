/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** init_particules
*/

#include "rpg.h"

game_obj_R_t create_object_fight(char *filepath, sfVector2f pos, sfIntRect rect,
enum BACK_R_s type);

ennemies_t set_enn(int i)
{
    ennemies_t enn;
    char path[] = "assets/sprites/ennemies.png";

    enn.enn_texture = sfTexture_createFromFile(path, NULL);
    enn.enn = sfSprite_create();
    sfSprite_setTexture(enn.enn, enn.enn_texture, sfTrue);
    set_enn2(&enn);
    if (i % 2 == 0) {
        enn.rect.left = 0;
    } else
        enn.rect.left = 150;
    sfSprite_setTextureRect(enn.enn, enn.rect);
    enn.pos.x = generate_random(100, 1820);
    enn.pos.y = generate_random(100, 980);
    enn.clock.clock = sfClock_create();
    enn.enn_clock.clock = sfClock_create();
    sfSprite_setPosition(enn.enn, enn.pos);
    sfSprite_setOrigin(enn.enn, (sfVector2f) {25, 35});
    return (enn);
}

void init_variables_for_particules(rpg_t *rpg)
{
    rpg->screen = malloc(sizeof(screen_t));
    init_particle_environment(&rpg->screen->particle_environment, \
    (sfVector2f){PARICULE_ANGLE_MIN, PARICULE_ANGLE_MAX}, \
    (sfVector2f){GRAVITY_X, GRAVITY_Y}, ALPHA);
}

void create_and_set_background(fight_t *fight)
{
    fight->rect.top = 0;
    fight->rect.left = 0;
    fight->rect.width = 1920;
    fight->rect.height = 1080;
}

game_obj_R_t create_object_fight(char *filepath, sfVector2f pos, sfIntRect rect,
enum BACK_R_s type)
{
    game_obj_R_t object;

    object.texture = sfTexture_createFromFile(filepath, NULL);
    object.sprite = sfSprite_create();
    sfSprite_setPosition(object.sprite, pos);
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    sfSprite_setTextureRect(object.sprite, rect);
    object.rect = rect;
    object.pos = pos;
    object.type = type;
    if (type == EFECT)
        sfSprite_setScale(object.sprite, (sfVector2f){0.7, 0.7});
    if (type == MUSIC) {
        sfSprite_setScale(object.sprite, (sfVector2f){4, 2});
    }
    return (object);
}

fight_t *init_three(fight_t *fight)
{
    fight->buttons[10] = create_object_fight("assets/sprites/health.png",
    (sfVector2f){960, 952}, (sfIntRect){0, 0, 60, 60}, EFECT);
    fight->buttons[11] = create_object_fight("assets/sprites/shoes.png",
    (sfVector2f){1070, 952}, (sfIntRect){0, 0, 60, 32}, BACK);
    set_basics_for_fight(fight, "assets/sprites/character.png",
    (sfIntRect) {0, 0, 64, 64}, (sfVector2f) {(1920 / 2) - (64 / 2),
    (1080 / 2) - (64 / 2)});
    fight->buttons[12] = create_object_fight("assets/sprites/red_life.png",
    (sfVector2f){550, 40}, (sfIntRect){0, 0, 204, 28}, MUSIC);
    fight->buttons[13] = create_object_fight("assets/sprites/green_life.png",
    (sfVector2f){550, 40}, (sfIntRect){0, 0, 204, 28}, MUSIC);
    srand(time(0));
    fight->player.clocks.clock = sfClock_create();
    for (int i = 0; i < 10; i++)
        fight->enns[i] = set_enn(i);
    return (fight);
}
