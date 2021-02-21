/*
** EPITECH PROJECT, 2020
** history.c
** File description:
** history.c
*/

#include "history/history.h"
#include "environnement/manipulation.h"

void add_node_at_back(char *command, history_t **node)
{
    history_t *new  = malloc(sizeof(history_t));
    history_t *tmp = *node;

    new->command = my_strdup(command);
    new->next = NULL;

    if (*node == NULL) {
        new->previous = NULL;
        *node = new;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
    new->previous = tmp;
}

void add_node_at_front(char *command, history_t **node)
{
    history_t *new = malloc(sizeof(history_t));

    new->command = my_strdup(command);
    new->previous = NULL;
    if (*node == NULL) {
        new->next = NULL;
        *node = new;
        return;
    }
    (*node)->previous = new;
    new->next = *node;
    *node = (*node)->previous;
}

void check_history_file_exist(shell_t *shell)
{
    FILE *fs;
    char *path = shell->history_path;

    if (path == NULL)
        return;
    fs = fopen(path, "rb+");
    if (fs == NULL) {
        fs = fopen(path, "wb");
        if (fs == NULL)
            return;
    }
    if (fs)
        fclose(fs);
}

static void add_history(char *command, shell_t *shell)
{
    FILE *fs;
    time_t timestamp = time(NULL);
    struct tm *t_m = localtime(&timestamp);
    char *path = shell->history_path;

    if (path == NULL)
        return;
    fs = fopen(path, "a");
    if (fs == NULL)
        return;
    fprintf(fs, "%d\t", shell->h_index);
    shell->h_index++;
    fprintf(fs, "%d:%02d\t", t_m->tm_hour, t_m->tm_min);
    fprintf(fs, "%s\n", command);
    fclose(fs);
}

void history(char *command, shell_t *shell)
{
    check_history_file_exist(shell);
    add_history(command, shell);
    add_node_at_back(command, &shell->history);
    shell->cur_history = NULL;
}