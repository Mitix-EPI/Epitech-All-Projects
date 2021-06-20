/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exerice 01
*/

#ifndef CLASS_H
# define CLASS_H

# include <sys/types.h>
# include <stdarg.h>
# include <stdbool.h>
# include <string.h>
# include "raise.h"

typedef void Object;
typedef void (*ctor_t)(Object *this, va_list *args);
typedef void (*dtor_t)(Object *this);
typedef char *(*to_string_t)(Object *this);
typedef Object *(*binary_operator_t)(const Object *this, const Object *other);
typedef bool (*binary_comparator_t)(const Object *this, const Object *other);

typedef struct {
    const size_t        __size__;   // ex01
    const char          *__name__;  // ex01
    ctor_t              __ctor__;   // ex01
    dtor_t              __dtor__;   // ex01
    to_string_t         __str__;    // ex02
    binary_operator_t   __add__;    // ex03
    binary_operator_t   __sub__;    // ex03
    binary_operator_t   __mul__;    // ex04
    binary_operator_t   __div__;    // ex04
    binary_comparator_t __eq__;     // ex04
    binary_comparator_t __gt__;     // ex04
    binary_comparator_t __lt__;     // ex04
}   Class;

# define str(o)                 (((Class *)o)->__str__ != NULL ? ((Class *)o)->__str__(o) : strdup(((Class *)o)->__name__))
# define addition(a, b)         ((Class *)a)->__add__(a, b)
# define subtraction(a, b)      ((Class *)a)->__sub__(a, b)
# define multiplication(a, b)   ((Class *)a)->__mul__(a, b)
# define division(a, b)         ((Class *)a)->__div__(a, b)
# define eq(a, b)               ((Class *)a)->__eq__(a, b)
# define gt(a, b)               ((Class *)a)->__gt__(a, b)
# define lt(a, b)               ((Class *)a)->__lt__(a, b)

#endif
