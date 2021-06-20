/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush1-alexandre.juan
** File description:
** vertex
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
    int z;
} VertexClass;

static int count_digits(int nb)
{
    int i = 0;

    for (; nb != 0; i++)
        nb /= 10;
    return (i);
}

static int Vertex_calc_len(const char *name, int x, int y, int z)
{
    int len_x = count_digits(x);
    int len_y = count_digits(y);
    int len_z = count_digits(z);
    int len_name = strlen(name);

    return (len_x + len_y + len_z + len_name + 12);
}

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
}

static char *Vertex_info(VertexClass *this)
{
    int len = 0;
    char *str = NULL;
    int check = 0;

    if (!this)
        raise("No class attributed");
    len = Vertex_calc_len(this->base.__name__, this->x, this->y, this->z);
    str = (char *)calloc(len + 1, sizeof(char));
    if (!str)
        raise("Out of memory");
    check = snprintf(str, len, "<%s (%d, %d, %d)>", \
    this->base.__name__, this->x, this->y, this->z);
    if (check < 0)
        raise("Error displaying output");
    return (str);
}

static const VertexClass *Vertex_add(VertexClass *this1, VertexClass *this2)
{
    int x_add = 0;
    int y_add = 0;
    int z_add = 0;
    VertexClass *res = NULL;

    if (!this1 || !this2)
        raise("No class attributed");
    x_add = this1->x + this2->x;
    y_add = this1->y + this2->y;
    z_add = this1->z + this2->z;
    res = new(Vertex, x_add, y_add, z_add);
    return (res);
}

static const VertexClass *Vertex_sub(VertexClass *this1, VertexClass *this2)
{
    int x_sub = 0;
    int y_sub = 0;
    int z_sub = 0;
    VertexClass *res = NULL;

    if (!this1 || !this2)
        raise("No class attributed");
    x_sub = this1->x - this2->x;
    y_sub = this1->y - this2->y;
    z_sub = this1->z - this2->z;
    res = new(Vertex, x_sub, y_sub, z_sub);
    return (res);
}

static const VertexClass     _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_info,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;
