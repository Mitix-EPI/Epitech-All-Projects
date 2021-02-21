/*
** EPITECH PROJECT, 2020
** display_history.c
** File description:
** display_history.c
*/

#include "minishell2.h"
#include "history/display_history.h"

int print_history(shell_t *shell, char __attribute((__unused__))**command)
{
    FILE *fs = NULL;
    struct stat st;
    char *buf = NULL;
    char *path = shell->history_path;

    if (path == NULL)
        return (1);
    stat(path, &st);
    fs = fopen(path, "r");
    if (fs == NULL || st.st_size <= 0)
        return (1);
    buf = malloc(sizeof(char) * (st.st_size + 1));
    fread(buf, st.st_size + 1, 1, fs);
    buf[st.st_size - 1] = 0;
    printf("%s\n", buf);
    free(buf);
    fclose(fs);
    return (0);
}

int is_historyable(char *command)
{
    int i = 0;

    for (; command[i]; i++) {
        if (command[i] != '\t' && command[i] != ' ' && command[i] != '\n')
            return (0);
    }
    return (1);
}
