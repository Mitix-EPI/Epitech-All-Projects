/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 01
*/

#ifndef NEW_H
# define NEW_H

# include <stdarg.h>
# include "object.h"

Object  *new(const Class *class, ...);
Object  *va_new(const Class *class, va_list* ap);
void    delete(Object *ptr);

#endif
