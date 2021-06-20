/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush1-alexandre.juan
** File description:
** int
*/

#include "int.h"
#include "new.h"

typedef struct
{
    Class base;
    int value;
} IntClass;

static int count_digits(int nb)
{
    int i = 0;

    for (; nb != 0; i++)
        nb /= 10;
    return (i);
}

static int Int_calc_len(const char *name, int value)
{
    int len_value = count_digits(value);
    int len_name = strlen(name);

    return (len_value + len_name + 10);
}

static void Int_ctor(IntClass *this, va_list *args)
{
    this->value = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
}

static char *Int_info(IntClass *this)
{
    int len = 0;
    char *str = NULL;
    int check = 0;

    if (!this)
        raise("No class attributed");
    len = Int_calc_len(this->base.__name__, this->value);
    str = (char *)calloc(len + 1, sizeof(char));
    if (!str)
        raise("Out of memory");
    check = snprintf(str, len, "<%s (%d)>", this->base.__name__, this->value);
    if (check < 0)
        raise("Error displaying output");
    return (str);
}

static const IntClass *Int_add(IntClass *a, IntClass *b)
{
    int new_value = 0;
    IntClass *res = NULL;

    if (!a || !b)
        raise("No class attributed");
    new_value = a->value + b->value;
    res = new(Int, new_value);
    return (res);
}

static const IntClass *Int_sub(IntClass *a, IntClass *b)
{
    int new_value = 0;
    IntClass *res = NULL;

    if (!a || !b)
        raise("No class attributed");
    new_value = a->value - b->value;
    res = new(Int, new_value);
    return (res);
}

static const IntClass *Int_div(IntClass *a, IntClass *b)
{
    int new_value = 0;
    IntClass *res = NULL;

    if (!a || !b)
        raise("No class attributed");
    if (b->value == 0)
        new_value = 0;
    else
        new_value = a->value / b->value;
    res = new(Int, new_value);
    return (res);
}

static const IntClass *Int_mul(IntClass *a, IntClass *b)
{
    int new_value = 0;
    IntClass *res = NULL;

    if (!a || !b)
        raise("No class attributed");
    new_value = a->value * b->value;
    res = new(Int, new_value);
    return (res);
}

static bool Int_equal(IntClass *a, IntClass *b)
{
    if (!a || !b)
        raise("No class attributed");
    return (a->value == b->value);
}

static bool Int_greater(IntClass *a, IntClass *b)
{
    if (!a || !b)
        raise("No class attributed");
    return (a->value > b->value);
}

static bool Int_less(IntClass *a, IntClass *b)
{
    if (!a || !b)
        raise("No class attributed");
    return (a->value < b->value);
}

static const IntClass     _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_info,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_equal,
        .__gt__ = (binary_comparator_t)&Int_greater,
        .__lt__ = (binary_comparator_t)&Int_less
    },
    .value = 0
};

const Class *Int = (const Class *)&_description;