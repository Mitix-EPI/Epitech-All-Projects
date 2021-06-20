/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 05
*/

#ifndef ITERATOR_H
# define ITERATOR_H

# include "object.h"
# include "raise.h"

typedef struct Iterator_s Iterator;

typedef void (*incr_t)(Iterator *this);
typedef Object *(*getval_t)(Iterator *this);
typedef void (*setval_t)(Iterator *this, ...);

struct Iterator_s
{
    Class       base;
    incr_t      __incr__;
    getval_t    __getval__;
    setval_t    __setval__;
};

# define incr(it)           ((Iterator *)it)->__incr__(it)
# define getval(it)         ((Iterator *)it)->__getval__(it)
# define setval(it, ...)    ((Iterator *)it)->__setval__(it, __VA_ARGS__)

#endif

