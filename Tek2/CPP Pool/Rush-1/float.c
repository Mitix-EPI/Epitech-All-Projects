/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush1-alexandre.juan
** File description:
** float
*/

#include "float.h"
#include "new.h"

typedef struct
{
    Class base;
    float value;
} FloatClass;

static int count_digits(float nb)
{
    int i = 0;

    if (nb < 0.f)
        nb *= -1;
    for (; nb > 0.f; ++i) {
        nb /= 10.f;
    }
    return (i);
}

static int Float_calc_len(const char *name, float value)
{
    int len_value = count_digits(value);
    int len_name = strlen(name);

    return (len_value + len_name + 20);
}

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->value = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
}

static char *Float_info(FloatClass *this)
{
    int len = 0;
    char *str = NULL;
    int check = 0;

    if (!this)
        raise("No class attributed");
    len = Float_calc_len(this->base.__name__, this->value);
    str = (char *)calloc(len + 1, sizeof(char));
    if (!str)
        raise("Out of memory");
    check = snprintf(str, len, "<%s (%06f)>", this->base.__name__, this->value);
    if (check < 0)
        raise("Error displaying output");
    return (str);
}

static const FloatClass *Float_add(FloatClass *this1, FloatClass *this2)
{
    float new_value = 0;
    FloatClass *res = NULL;

    if (!this1 || !this2)
        raise("No class attributed");
    new_value = this1->value + this2->value;
    res = new(Float, new_value);
    return (res);
}

static const FloatClass *Float_sub(FloatClass *this1, FloatClass *this2)
{
    float new_value = 0;
    FloatClass *res = NULL;

    if (!this1 || !this2)
        raise("No class attributed");
    new_value = this1->value - this2->value;
    res = new(Float, new_value);
    return (res);
}

static const FloatClass *Float_div(FloatClass *a, FloatClass *b)
{
    float new_value = 0;
    FloatClass *res = NULL;

    if (!a || !b)
        raise("No class attributed");
    if (b->value == 0)
        new_value = 0;
    else
        new_value = a->value / b->value;
    res = new(Float, new_value);
    return (res);
}

static const FloatClass *Float_mul(FloatClass *a, FloatClass *b)
{
    float new_value = 0;
    FloatClass *res = NULL;

    if (!a || !b)
        raise("No class attributed");
    new_value = a->value * b->value;
    res = new(Float, new_value);
    return (res);
}

static bool Float_equal(FloatClass *a, FloatClass *b)
{
    if (!a || !b)
        raise("No class attributed");
    return (a->value == b->value);
}

static bool Float_greater(FloatClass *a, FloatClass *b)
{
    if (!a || !b)
        raise("No class attributed");
    return (a->value > b->value);
}

static bool Float_less(FloatClass *a, FloatClass *b)
{
    if (!a || !b)
        raise("No class attributed");
    return (a->value < b->value);
}

static const FloatClass     _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_info,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_equal,
        .__gt__ = (binary_comparator_t)&Float_greater,
        .__lt__ = (binary_comparator_t)&Float_less
    },
    .value = 0.f
};

const Class *Float = (const Class *)&_description;