/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush1-alexandre.juan
** File description:
** point
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
} PointClass;

static int count_digits(int nb)
{
    int i = 0;

    for (; nb != 0; i++)
        nb /= 10;
    return (i);
}

static int Point_calc_len(const char *name, int x, int y)
{
    int len_x = count_digits(x);
    int len_y = count_digits(y);
    int len_name = strlen(name);

    return (len_x + len_y + len_name + 10);
}

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(* args, int);
    this->y = va_arg(* args, int);
}

static void Point_dtor(PointClass *this)
{
    (void)this;
}

static char *Point_info(PointClass *this)
{
    int len = 0;
    char *str = NULL;
    int check = 0;

    if (!this)
        raise("No class attributed");
    len = Point_calc_len(this->base.__name__, this->x, this->y);
    str = (char *)calloc(len + 1, sizeof(char));
    if (!str)
        raise("Out of memory");
    check = snprintf(str, len, "<%s (%d, %d)>", this->base.__name__, this->x, \
    this->y);
    if (check < 0)
        raise("Error displaying output");
    return (str);
}

static const PointClass *Point_add(PointClass *this1, PointClass *this2)
{
    int x_add = 0;
    int y_add = 0;
    PointClass *res = NULL;

    if (!this1 || !this2)
        raise("No class attributed");
    x_add = this1->x + this2->x;
    y_add = this1->y + this2->y;
    res = new(Point, x_add, y_add);
    return (res);
}

static const PointClass *Point_sub(PointClass *this1, PointClass *this2)
{
    int x_sub = 0;
    int y_sub = 0;
    PointClass *res = NULL;

    if (!this1 || !this2)
        raise("No class attributed");
    x_sub = this1->x - this2->x;
    y_sub = this1->y - this2->y;
    res = new(Point, x_sub, y_sub);
    return (res);
}

static const PointClass     _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_info,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;
