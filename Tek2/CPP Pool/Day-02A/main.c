/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD02A-alexandre.juan
** File description:
** main
*/

#include "double_list.h"
#include "generic_list.h"
#include "queue.h"
#include "stack.h"
#include <stdio.h>

static void int_displayer ( void * data )
{
    double value = *(( double *) data ) ;

    printf("%f\n", value);
}

static void populate_list(list_t *list_head)
{
    double tmp = 5.2;
    list_add_elem_at_front(list_head, &tmp);
    double tmp2 = 72.1;
    list_add_elem_at_back(list_head, &tmp2);
    double tmp3 = 42.5;
    list_add_elem_at_front(list_head, &tmp3);
    double tmp4 = 2;
    list_add_elem_at_back(list_head, &tmp4);
    double tmp5 = 9;
    list_add_elem_at_back(list_head, &tmp5);
    list_dump(*list_head, &int_displayer);
    printf("\n\n");
    double tmp6 = 3.3;
    list_add_elem_at_back(list_head, &tmp6);
    list_dump(*list_head, &int_displayer);
    printf("\n\n");
    double tmp7 = 10;
    list_add_elem_at_position(list_head, &tmp7, 2);
    double tmp8 = 12;
    list_add_elem_at_position(list_head, &tmp8, 27);
    list_dump(*list_head, &int_displayer);
    printf("\n\n");
    list_del_elem_at_position(list_head, 3);
    list_dump(*list_head, &int_displayer);
    printf("\n\n");
    list_del_elem_at_front(list_head);
    list_dump(*list_head, &int_displayer);
    printf("\n\n");
    list_del_elem_at_back(list_head);
    list_dump(*list_head, &int_displayer);
    printf("\n\n");
}
static void test_size(list_t list_head)
{
    printf("There are %u elements in the list \n", list_get_size(list_head));
    list_dump(list_head, &int_displayer);
}
static void test_del(list_t *list_head)
{
    list_del_elem_at_back(list_head);
    printf("There are %u elements in the list \n", list_get_size(*list_head));
    list_dump(*list_head, &int_displayer);
}

int main(void)
{
    list_t list_head = NULL;

    populate_list(&list_head);
    test_size(list_head);
    test_del(&list_head);
    return 0;
}