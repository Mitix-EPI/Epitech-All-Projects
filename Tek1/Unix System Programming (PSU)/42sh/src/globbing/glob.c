/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** globbing
*/

#include "globbing/glob.h"

char **check_globbing(char *flag)
{
    glob_t globbuf;
    char **result = NULL;

    if (glob(flag, 0, NULL, &globbuf) == GLOB_NOMATCH)
        return (NULL);
    result = malloc(sizeof(char *) * (globbuf.gl_pathc + 1));
    for (int i = 0; globbuf.gl_pathv[i]; i++)
        result[i] = strdup(globbuf.gl_pathv[i]);
    result[globbuf.gl_pathc] = NULL;
    globfree(&globbuf);
    return (result);
}

int insert_in_array(char ***arr, char **to_insert, int index)
{
    for (int i = 0; to_insert[i]; i++, index++) {
        (*arr) = realloc((*arr), sizeof(char *) * (index + 1));
        (*arr)[index] = to_insert[i];
    }
    return (index);
}

char **proceed_globbing(shell_t *shell, char **arr_command)
{
    char **result = NULL;
    char **new_arr_cmd = malloc(sizeof(char *));
    int index = 0;

    (void)shell;
    for (int i = 0; arr_command[i]; i++) {
        result = check_globbing(arr_command[i]);
        if (result)
            index = insert_in_array(&new_arr_cmd, result, index);
        else {
            new_arr_cmd = realloc(new_arr_cmd, sizeof(char *) * (index + 1));
            new_arr_cmd[index++] = arr_command[i];
        }
    }
    new_arr_cmd = realloc(new_arr_cmd, sizeof(char *) * (index + 1));
    new_arr_cmd[index] = NULL;
    free(arr_command);
    return (new_arr_cmd);
}