/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 05
*/

#include <stdio.h>
#include "array.h"
#include "int.h"
#include "new.h"
#include "int.h"
#include "float.h"
#include "char.h"
#include "point.h"
#include "vertex.h"

void compareAndDivide ( Object *a , Object * b )
{
    Class *tmp = NULL;
    if (gt(a, b))
        printf ("a > b \n");
    else if (lt(a, b))
        printf("a < b \n");
    else
        printf (" a == b \n");
    tmp = division(b, a);
    char *str = str(tmp);
    printf("b / a = %s \n", str);
    delete(tmp);
    free(str);
}

int first_part(void)
{
    char *p_str1 = NULL;
    char *p_str2 = NULL;
    char *p_str3 = NULL;
    char *p_str4 = NULL;
    Class *p_add = NULL;
    Class *p_sub = NULL;

    Object  *p1 = new(Point, 12, 13);
    Object  *p2 = new(Point, 2, 2);
    p_str1 = str(p1);
    p_str2 = str(p2);
    p_add = addition(p1, p2);
    p_sub = subtraction(p1, p2);
    p_str3 = str(p_add);
    p_str4 = str(p_sub);
    printf("%s + %s = %s\n", p_str1, p_str2, p_str3);
    printf("%s - %s = %s\n", p_str1, p_str2, p_str4);
    delete(p1);
    delete(p2);
    free(p_str1);
    free(p_str2);
    delete(p_add);
    delete(p_sub);
    free(p_str3);
    free(p_str4);


    Object  *v1 = new(Vertex, 1, 2, 3);
    Object  *v2 = new(Vertex, 4, 5, 6);
    char *v_str1 = str(v1);
    char *v_str2 = str(v2);
    Class *v_add = addition(v1, v2);
    Class *v_sub = subtraction(v1, v2);
    char *v_str3 = str(v_add);
    char *v_str4 = str(v_sub);
    printf("%s + %s = %s\n", v_str1, v_str2, v_str3);
    printf("%s - %s = %s\n", v_str1, v_str2, v_str4);
    delete(v1);
    delete(v2);
    free(v_str1);
    free(v_str2);
    delete(v_add);
    delete(v_sub);
    free(v_str3);
    free(v_str4);

    Object  *i1 = new(Int, 10);
    Object  *i2 = new(Int, 3);

    compareAndDivide(i1, i2);

    delete(i1);
    delete(i2);

    Object  *f1 = new(Float, (float)1.1);
    Object  *f2 = new(Float, (float)3.3);

    compareAndDivide(f1, f2);

    delete(f1);
    delete(f2);

    Object  *c1 = new(Char, 2);
    Object  *c2 = new(Char, 'z');

    compareAndDivide(c1, c2);

    delete(c1);
    delete(c2);

    return (0);
}

int         main(void)
{

    Object  *f1 = new(Float, (float)0.875821);
    Object  *f2 = new(Float, (float)2.130386);
    char *str1 = str(f1);
    char *str2 = str(f2);
    printf("%s < %s = %d\n", str1, str2, lt(f1, f2));
    free(str1);
    free(str2);
    delete(f1);
    delete(f2);
    first_part();
    Object  *array = new(Array, 10, Int, 0);
    Object  *it = begin(array);
    Object  *it_end = end(array);

    printf("array size: %zu\n", len(array));
    setitem(array, 5, 12);
    setitem(array, 6, 13);
    setval(it, 666);
    while (lt(it, it_end))
    {
        char *test = str(getval(it));
        printf("%s\n", test);
        free(test);
        incr(it);
    }
    Object *try = getitem(array, 5);
    char *str_tmp = str((try));
    printf("%s\n", str_tmp);
    delete(it);
    delete(it_end);
    delete(array);
    free(str_tmp);
    return (0);
}

