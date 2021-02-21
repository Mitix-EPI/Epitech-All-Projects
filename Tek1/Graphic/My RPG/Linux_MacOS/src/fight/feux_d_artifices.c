/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** feux_d_artifices
*/

#include "rpg.h"

void feux_d_artifices(rpg_t *rpg)
{
    static sfVector2f pos = {300, 540};

    if (pos.x < 1920) {
        add_particle(&rpg->screen->particle_environment, rpg->screen->particle,
        60, pos);
        pos.x += 640;
    } else {
        pos = (sfVector2f) {300, 540};
    }
}

void set_particules_for_feux_d_artifices(particle_environment_t *particle)
{
    particle->angle_min = -1;
    particle->angle_max = M_PI * 4;
    particle->speed = 12.00;
}

void set_particules_default(particle_environment_t *particle)
{
    particle->angle_min = PARICULE_ANGLE_MIN;
    particle->angle_max = PARICULE_ANGLE_MAX;
    particle->speed = SPEED;
}
