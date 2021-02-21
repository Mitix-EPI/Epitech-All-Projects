/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** set_arbol
*/

#include "../include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    for (; str && str[i]; i++);
    return (i);
}

node_t *set_elem(char *sym, char *str, node_t *elem, char *tmp)
{
    int i = search_symb(str, sym);

    if (my_strlen(sym) == 2)
        i--;
    elem->pipes[0] = 0;
    elem->pipes[1] = 1;
    if (!sym) {
        elem->value = my_strdup(str);
        elem->left = NULL;
        elem->right = NULL;
        elem->previews = my_strdup(tmp);
    } else {
        elem->value = my_strdup(sym);
        elem->left = malloc(sizeof(node_t));
        elem->right = malloc(sizeof(node_t));
        elem->left->value = left_separation(str, i);
        elem->left->previews = my_strdup(sym);
        elem->right->value = right_separation(str, i, sym);
        elem->right->previews = my_strdup(sym);
    }
    return (elem);
}

node_t *set_arbol(node_t *arbol, char *sym, char *str, char *tmp)
{
    node_t *tmptmpTree;
    node_t *tmpTree;
    node_t *elem = malloc(sizeof(*elem));

    if (!sym) {
        elem = set_elem(sym, str, elem, tmp);
        return (elem);
    } else {
        elem = set_elem(sym, str, elem, tmp);
        arbol = elem;
        tmpTree = arbol;
        tmptmpTree = arbol;
        tmpTree = tmpTree->left;
        tmpTree = recursive_arbol(tmpTree, tmpTree->value);
        tmptmpTree = tmptmpTree->right;
        tmptmpTree = recursive_arbol(tmptmpTree, tmptmpTree->value);
        arbol->left = tmpTree;
        arbol->right = tmptmpTree;
    }
    return (arbol);
}

node_t *recursive_arbol(node_t *arbol, char *str)
{
    char *sym = symbol(str);
    static char *tmp1;

    if (!sym) {
        arbol = set_arbol(arbol, NULL, str, tmp1);
        return (arbol);
    } else {
        tmp1 = my_strdup(sym);
        arbol = set_arbol(arbol, sym, str, NULL);
        return (arbol);
    }
}

node_t *return_arbol(char *str)
{
    node_t *arbol = NULL;

    arbol = recursive_arbol(arbol, str);
    return (arbol);
}
