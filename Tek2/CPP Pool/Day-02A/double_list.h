/*
** EPITECH PROJECT, 2018
** cpp_d02a
** File description:
** ex00
*/

#ifndef DOUBLE_LIST_H_
# define DOUBLE_LIST_H_

/*
** Types
*/

#include <stdbool.h>

typedef struct doublelist_node
{
    double                  value;
    struct doublelist_node  *next;
}   doublelist_node_t;

typedef doublelist_node_t *double_list_t;

/*
** Functions
*/

/* Informations */

unsigned int    double_list_get_size(double_list_t list);
bool            double_list_is_empty(double_list_t list);
void            double_list_dump(double_list_t list);

/* Modification */

bool    double_list_add_elem_at_front(double_list_t *front_ptr, double elem);
bool    double_list_add_elem_at_back(double_list_t *front_ptr, double elem);
bool    double_list_add_elem_at_position(double_list_t *front_ptr, double elem,
                                        unsigned int position);

bool    double_list_del_elem_at_front(double_list_t *front_ptr);
bool    double_list_del_elem_at_back(double_list_t *front_ptr);
bool    double_list_del_elem_at_position(double_list_t *front_ptr,
                                        unsigned int position);

/* Value Access */

double   double_list_get_elem_at_front(double_list_t list);
double   double_list_get_elem_at_back(double_list_t list);
double   double_list_get_elem_at_position(double_list_t list,
                                        unsigned int position);

/* Node Access */

doublelist_node_t  *double_list_get_first_node_with_value(double_list_t list,
                                                        double value);

#endif /* !DOUBLE_LIST_H_ */
