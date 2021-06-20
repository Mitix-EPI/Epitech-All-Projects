/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 01
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "player.h"

typedef struct
{
    Class   base;
    char    *identifier;
    int     power;
}   PlayerClass;

static void Player_ctor(PlayerClass *this, va_list *args)
{
    (void)args;

    // Initialize internal resources
    this->identifier = strdup("Kreog");
    if (!(this->identifier))
        raise("Out of memory");
    this->power = rand() % 42;
    printf("Player()\n");
}

static void Player_dtor(PlayerClass *this)
{
    // Release internal resources
    free(this->identifier);

    printf("~Player()\n");
}

static const PlayerClass    _description = {
    {   /* Class struct */
        .__size__ = sizeof(PlayerClass),
        .__name__ = "Player",
        .__ctor__ = (ctor_t)&Player_ctor,
        .__dtor__ = (dtor_t)&Player_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .identifier = NULL,
    .power = -1
};

const Class *Player = (const Class *)&_description;
