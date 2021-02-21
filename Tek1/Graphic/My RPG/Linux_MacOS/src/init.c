/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** init_particules
*/

#include "rpg.h"

game_obj_R_t create_object_fight(char *filepath, sfVector2f pos, sfIntRect rect,
enum BACK_R_s type);

fight_t *init_two(fight_t *fight)
{
    fight->buttons[4] = create_object_fight("assets/sprites/arena/arenas.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080}, BACK);
    fight->buttons[5] = create_object_fight("assets/sprites/menu/pause.png",
    (sfVector2f){20, 20}, (sfIntRect){0, 0, 100, 100}, BACK);
    fight->buttons[6] = create_object_fight("assets/sprites/fire.png",
    (sfVector2f){630, 957}, (sfIntRect){0, 0, 47, 28}, BACK);
    fight->buttons[7] = create_object_fight("assets/sprites/shield.png",
    (sfVector2f){738, 952}, (sfIntRect){0, 0, 60, 60}, EFECT);
    fight->buttons[8] = create_object_fight("assets/sprites/black_hole.png",
    (sfVector2f){850, 948}, (sfIntRect){0, 0, 49, 49}, BACK);
    fight->buttons[9] = create_object_fight("assets/sprites/arrow_fight.png",
    (sfVector2f){1570, 370}, (sfIntRect){0, 0, 330, 340}, BACK);
    return (init_three(fight));
}

fight_t *init_one_second(fight_t *fight)
{
    sfSprite_setTextureRect(fight->background, (sfIntRect){0, 0, 1920, 1080});
    fight->buttons = malloc(sizeof(game_obj_t) * 14);
    fight->buttons[0] = create_object_fight("assets/sprites/life_fight.png",
    (sfVector2f){20, 20}, (sfIntRect){0, 0, 168, 28}, BACK);
    fight->buttons[1] = create_object_fight("assets/sprites/you_are_dead.png",
    (sfVector2f){530, 485}, (sfIntRect){0, 0, 870, 120}, BACK);
    fight->buttons[2] = create_object_fight("assets/sprites/red_life.png",
    (sfVector2f){1676, 40}, (sfIntRect){0, 0, 204, 28}, BACK);
    fight->buttons[3] = create_object_fight("assets/sprites/green_life.png",
    (sfVector2f){1676, 40}, (sfIntRect){0, 0, 204, 28}, BACK);
    return (init_two(fight));
}

fight_t *init_one(fight_t *fight)
{
    fight->spell = malloc(sizeof(spell_t) * (5));
    fight->spell[0] = init_spell("assets/sprites/spells/fireball_sprite.png",
    FIREBALL, (sfIntRect) {0, 0, 48, 28});
    fight->spell[1] = init_spell("assets/sprites/spells/shield_sprite.png",
    SHIELD, (sfIntRect) {0, 0, 60, 60});
    fight->spell[2] = init_spell("assets/sprites/spells/spell3.png", BLACK_HOLE,
    (sfIntRect) {0, 0, 250, 250});
    fight->spell[3] = init_spell("assets/sprites/spells/health.png", HEALTH,
    (sfIntRect) {0, 0, 60, 60});
    fight->spell[4] = init_spell("assets/sprites/spells/speed.png", SPEEDS,
    (sfIntRect) {0, 0, 60, 60});
    create_and_set_background(fight);
    return (init_one_second(fight));
}

fight_t *init_variables_for_fights_two(fight_t *fight)
{
    sfRectangleShape_setOutlineThickness(fight->inventory.show, 6);
    sfRectangleShape_setFillColor(fight->inventory.show,
    sfColor_fromRGBA(0, 0, 0, 0));
    sfRectangleShape_setOutlineColor(fight->inventory.show,
    sfColor_fromRGBA(50, 50, 50, 255));
    sfSprite_setTexture(fight->inventory.sprite,
    fight->inventory.texture, sfTrue);
    sfSprite_setPosition(fight->inventory.sprite, (sfVector2f) {577, 926});
    sfSprite_setPosition(fight->background, (sfVector2f) {0, 0});
    return (init_one(fight));
}

fight_t *init_variables_for_fights(fight_t *fight)
{
    fight = malloc(sizeof(fight_t));
    fight->enns = malloc(sizeof(ennemies_t) * 10);
    fight->clock = malloc(sizeof(clock_R_t));
    fight->clock->clock = sfClock_create();
    fight->background = sfSprite_create();
    fight->inventory.sprite = sfSprite_create();
    fight->inventory.texture =
    sfTexture_createFromFile("assets/sprites/inventory.png", NULL);
    fight->inventory.show = sfRectangleShape_create();
    sfRectangleShape_setSize(fight->inventory.show,
    (sfVector2f) {110 - 12, 90 - 22});
    return (init_variables_for_fights_two(fight));
}