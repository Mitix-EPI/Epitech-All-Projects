/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush1-alexandre.juan
** File description:
** new
*/

#include "new.h"
#include "player.h"
#include "object.h"

Object  *new(const Class *class, ...)
{
    Object *ret = NULL;
    va_list ap;

    if (!class)
        raise("No class attributed");
    va_start(ap, class);
    ret = va_new(class, &ap);
    va_end(ap);
    return (ret);
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *ret = malloc(class->__size__);

    if (!ret)
        raise("Out of memory");
    if (!class->__size__)
        raise("Class size not correct");
    memcpy(ret, class, class->__size__);
    if (class->__ctor__) {
        class->__ctor__(ret, ap);
    }
    return (ret);
}

void delete(Object *ptr)
{
    const Class *tmp = ptr;

    if (!ptr) {
        raise("No Object to delete");
    }
    if (tmp->__dtor__) {
        tmp->__dtor__(ptr);
    }
    free(ptr);
}
