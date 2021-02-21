/*
** EPITECH PROJECT, 2020
** test handling_path
** File description:
** units tests for handling path
*/

#include "lemin.h"
#include <criterion/criterion.h>

Test(init_path, should_return_path_filled)
{
    paths_t *path = malloc(sizeof(paths_t));

    init_path(path);
    cr_assert_null(path->debug[0]);
    cr_assert_eq(path->nb_rooms, 0);
    cr_assert_null(path->nodes[0]);
    cr_assert_null(path->links[0]);
    cr_assert_null(path->start);
    cr_assert_null(path->end);
    cr_assert_eq(path->ants_number, 0);
    free(path->debug);
    free(path->nodes);
    free(path->links);
    free(path);
}

Test(handling_path, should_return_0)
{
    paths_t *path = malloc(sizeof(paths_t));
    int ret = handling_path(path);
    int ret2 = 0;
    int ret3 = 0;
    int ret4 = 0;

    path->start = "Hi";
    ret2 = handling_path(path);
    path->end = "Ho";
    ret3 = handling_path(path);
    path->ants_number = 3;
    ret4 = handling_path(path);
    cr_assert_eq(ret, 0);
    cr_assert_eq(ret2, 0);
    cr_assert_eq(ret3, 0);
    cr_assert_eq(ret4, 0);
    free(path);
}

Test(handling_path, should_return_1)
{
    paths_t *path = malloc(sizeof(paths_t));
    int ret = 0;

    path->start = "Hi";
    path->end = "Ho";
    path->ants_number = 3;
    path->nb_rooms = 3;
    path->nodes = malloc(sizeof(char *) * 1);
    path->nodes[0] = "Holla";
    path->links = malloc(sizeof(char *) * 1);
    path->links[0] = "Hallo";
    ret = handling_path(path);
    cr_assert_eq(ret, 1);
    free(path->links);
    free(path->nodes);
    free(path);
}