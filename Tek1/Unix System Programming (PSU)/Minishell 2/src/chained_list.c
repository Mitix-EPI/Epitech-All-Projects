/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** chained_list
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void display(objt_struct_t *head)
{
    objt_struct_t *tmp = head;

    while (tmp) {
        my_putstr(1, tmp->name);
        my_putstr(1, "=");
        my_putstr(1, tmp->txt);
        my_putstr(1, "\n");
        tmp = tmp->next;
    }
}

void remove_node(char *name, objt_struct_t *head)
{
    objt_struct_t *tmp = head;
    objt_struct_t *freen = head;

    for (; tmp; tmp = tmp->next, freen = freen->next) {
        if (my_strcmp(tmp->next->name, name) == 0) {
            tmp->next = tmp->next->next;
            break;
        }
    }
}

char *return_str(char *name, objt_struct_t *head)
{
    objt_struct_t *tmp = head;

    for (; tmp; tmp = tmp->next) {
        if (my_strcmp(tmp->name, name) == 0) {
            return (tmp->txt);
        }
    }
    return (NULL);
}

void modify_node(char *name, objt_struct_t *head, char *txt)
{
    objt_struct_t *tmp = head;
    objt_struct_t *freen = head;

    for (; tmp; tmp = tmp->next, freen = freen->next) {
        if (my_strcmp(tmp->next->name, name) == 0) {
            tmp->next->txt = txt;
            break;
        }
    }
}

int exist_node(char *name, objt_struct_t *head)
{
    objt_struct_t *tmp = head;

    for (; tmp; tmp = tmp->next) {
        if (my_strcmp(tmp->name, name) == 0) {
            return (1);
        }
    }
    return (0);
}