/*
** EPITECH PROJECT, 2018
** cpp_d02a
** File description:
** ex01
*/

#ifndef GENERIC_LIST_H_
# define GENERIC_LIST_H_

/*
** Types
*/

#include <stdbool.h>

typedef struct node
{
    void        *value;
    struct node *next;
}   node_t;

typedef node_t *list_t;

/*
** Functions
*/

/* Informations */

unsigned int    list_get_size(list_t list);
bool            list_is_empty(list_t list);

typedef void    (*value_displayer_t)(void *value);

void            list_dump(list_t list, value_displayer_t val_disp);

/* Modification */

bool    list_add_elem_at_front(list_t *front_ptr, void *elem);
bool    list_add_elem_at_back(list_t *front_ptr, void *elem);
bool    list_add_elem_at_position(list_t *front_ptr, void *elem, unsigned int position);

bool    list_del_elem_at_front(list_t *front_ptr);
bool    list_del_elem_at_back(list_t *front_ptr);
bool    list_del_elem_at_position(list_t *front_ptr, unsigned int position);
bool    list_del_node(list_t *front_ptr, node_t *node_ptr);

void    list_clear(list_t *front_ptr);

/* Value Access */

void    *list_get_elem_at_front(list_t list);
void    *list_get_elem_at_back(list_t list);
void    *list_get_elem_at_position(list_t list, unsigned int position);

/* Node Access */

typedef int (*value_comparator_t)(void *first, void *second);

node_t  *list_get_first_node_with_value(list_t list, void *value, value_comparator_t val_comp);


#endif /* !GENERIC_LIST_H_ */
