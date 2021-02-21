/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** particule
*/

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define PARICULE_ANGLE_MIN (0)
#define PARICULE_ANGLE_MAX (M_PI * 4)
#define GRAVITY_X (1.0f * 0)
#define GRAVITY_Y (1.0f * 0)
#define ALPHA (1)

#define PARICULE_MAX (1000)
#define SPEED (2.0f)

typedef struct particle_environment_s particle_environment_t;
typedef struct particle_s particle_t;
typedef struct screen_s screen_t;

struct particle_s
{
    sfVector2f pos;
    sfVector2f vel;
    sfColor color;
    size_t radius;
    bool living;
    sfVector2f scale;
};

struct particle_environment_s
{
    float angle_min;
    float angle_max;
    float speed;
    sfVector2f gravity;
    sfUint8 alpha;
    sfClock *clock;
    sfCircleShape *circle_shape;
};

struct screen_s {
    sfRenderWindow *window;
    sfEvent event;
    sfKeyCode key;
    particle_t particle[PARICULE_MAX];
    particle_environment_t particle_environment;
};

void init_particle_environment(particle_environment_t *particle_environment,
const sfVector2f angle, const sfVector2f gravity, const sfUint8 alpha);

void init_particule(const particle_environment_t *particle_environment,
particle_t *particule, const sfVector2f pos);

void display_particle(sfRenderWindow *window, const particle_t *particule,
sfCircleShape *circle_shape);

void update_particle(const particle_environment_t *particle_environment,
particle_t *particule);

void add_particle(const particle_environment_t *particle_environment,
particle_t *particule, const size_t particle_num, const sfVector2f pos);

#endif
