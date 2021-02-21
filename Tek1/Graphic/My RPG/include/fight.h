/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** fight
*/

#ifndef FIGHT_H_
#define FIGHT_H_

#include "rpg.h"


typedef struct clock_c clock_s;
typedef struct ennemies ennemies_t;

typedef enum WEAPONS
{
    SHOVEL,
    SPELL_ONE,
    SPELL_TWO,
    SPELL_THREE,
    SPELL_FOUR,
    SPELL_FIVE,
    SPELL_SIX
} WEAPONS;

typedef enum spells_names_s {
    FIREBALL,
    SHIELD,
    BLACK_HOLE,
    HEALTH,
    SPEEDS
} spells_names_t;

typedef struct player_fight_s
{
    sfSprite *player;
    sfTexture *player_texture;
    clock_s clock;
    clock_s clock2;
    clock_s clocks;
    sfIntRect rect;
    sfVector2f pos;
    int direct;
    int life;
    WEAPONS weapon;
} player_fight_t;


typedef struct spell_s {
    int tmp;
    int tmp2;
    text_R_t text;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    int damage;
    int velocity;
    int protection;
    int activated;
    int direction;
    sfVector2f final_pos;
    sfClock *clock;
    sfClock *health;
    clock_R_t clock_cd;
    spells_names_t type;
    float sec;
    int calc;
}  spell_t;

typedef struct inventory_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfRectangleShape *show;
    sfVector2f pos;
} inventory_t;

typedef struct fight_s
{
    game_obj_R_t *buttons;
    sfSprite *background;
    sfTexture *defaultt;
    sfIntRect rect;
    player_fight_t player;
    spell_t *spell;
    ennemies_t *enns;
    ennemies_t *boss;
    spell_t *boss_spell;
    inventory_t inventory;
    clock_R_t *clock;
    int max_enn;
    int nb_enn;
}fight_t;

typedef struct attack_s
{
    void (*attack)(fight_t *, float *);
} attack_t;

void fireball(fight_t *fight, sfVector2f player_pos);

#endif /* !FIGHT_H_ */
