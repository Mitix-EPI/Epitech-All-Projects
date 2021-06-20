/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush1-alexandre.juan
** File description:
** char
*/

#include "char.h"
#include "new.h"

typedef struct
{
    Class base;
    char value;
} CharClass;

static int Char_calc_len(const char *name)
{
    int len_value = 1;
    int len_name = strlen(name);

    return (len_value + len_name + 10);
}

static void Char_ctor(CharClass *this, va_list *args)
{
    this->value = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

static char *Char_info(CharClass *this)
{
    int len = 0;
    char *str = NULL;
    int check = 0;

    if (!this)
        raise("No class attributed");
    len = Char_calc_len(this->base.__name__);
    str = (char *)calloc(len + 1, sizeof(char));
    if (!str)
        raise("Out of memory");
    check = snprintf(str, len, "<%s (%c)>", this->base.__name__, this->value);
    if (check < 0)
        raise("Error displaying output");
    return (str);
}

static const CharClass *Char_add(CharClass *a, CharClass *b)
{
    char new_value = 0;
    CharClass *res = NULL;

    if (!a || !b)
        raise("No class attributed");
    new_value = a->value + b->value;
    res = new(Char, new_value);
    return (res);
}

static const CharClass *Char_sub(CharClass *a, CharClass *b)
{
    char new_value = 0;
    CharClass *res = NULL;

    if (!a || !b)
        raise("No class attributed");
    new_value = a->value - b->value;
    res = new(Char, new_value);
    return (res);
}

static const CharClass *Char_div(CharClass *a, CharClass *b)
{
    char new_value = 0;
    CharClass *res = NULL;

    if (!a || !b)
        raise("No class attributed");
    if (b->value == 0)
        new_value = 0;
    else
        new_value = a->value / b->value;
    res = new(Char, new_value);
    return (res);
}

static const CharClass *Char_mul(CharClass *a, CharClass *b)
{
    char new_value = 0;
    CharClass *res = NULL;

    if (!a || !b)
        raise("No class attributed");
    new_value = a->value * b->value;
    res = new(Char, new_value);
    return (res);
}

static bool Char_equal(CharClass *a, CharClass *b)
{
    if (!a || !b)
        raise("No class attributed");
    return (a->value == b->value);
}

static bool Char_greater(CharClass *a, CharClass *b)
{
    if (!a || !b)
        raise("No class attributed");
    return (a->value > b->value);
}

static bool Char_less(CharClass *a, CharClass *b)
{
    if (!a || !b)
        raise("No class attributed");
    return (a->value < b->value);
}

static const CharClass     _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_info,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_equal,
        .__gt__ = (binary_comparator_t)&Char_greater,
        .__lt__ = (binary_comparator_t)&Char_less
    },
    .value = 0
};

const Class *Char = (const Class *)&_description;