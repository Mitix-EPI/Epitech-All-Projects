/*
** EPITECH PROJECT, 2020
** fill_linked_list_on_start.c
** File description:
** fill_linked_list_on_start.c
*/

#include "history/history.h"
#include "history/fill_linked_list_on_start.h"
#include "environnement/manipulation.h"

int get_index(char *buf)
{
    int i = 0;
    char *nb = malloc(sizeof(char) * 40);
    int j = 0;
    int nbr = 0;

    for (; buf[i]; i++);
    i -= 2;
    for (; i > 0 && buf[i] != '\n'; i--);
    for (; buf[i] && buf[i] != '\t'; i++) {
        nb[j++] = buf[i];
    }
    nb[j] = 0;
    nbr = atoi(nb);
    free(nb);
    nbr += 1;
    return (nbr);
}

static char *get_file_content(shell_t *shell)
{
    FILE *fs;
    struct stat st;
    char *buf = NULL;
    size_t readed = 0;

    if (shell->history_path == NULL)
        return (NULL);
    if (stat(shell->history_path, &st) == -1)
        return (NULL);
    fs = fopen(shell->history_path, "r");
    if (fs == NULL || st.st_size <= 0)
        return (NULL);
    buf = malloc(sizeof(char) * (st.st_size + 1));
    readed = fread(buf, st.st_size + 1, 1, fs);
    if (readed == 0 && ferror(fs))
        return (NULL);
    buf[st.st_size] = 0;
    shell->h_index = get_index(buf);
    fclose(fs);
    return (buf);
}

char *get_command(char *str)
{
    char *buf = malloc(sizeof(char) * strlen(str));
    int i = 0;
    int nb = 0;
    int j = 0;

    for (; str[i] && nb < 2; i++) {
        if (str[i] == '\t')
            nb++;
    }
    for (; str[i]; i++) {
        buf[j++] = str[i];
    }
    buf[j] = 0;
    return (buf);
}

static void fill_linked_list(shell_t *shell, char *tab[])
{
    int i = 0;
    char *line = NULL;

    for (; tab[i]; i++) {
        line = get_command(tab[i]);
        add_node_at_back(line, &shell->history);
        free(line);
    }
    for (int j = 0; tab[j]; j++) {
        free(tab[j]);
    }
    free(tab);
}

void fill_history_linked_list(shell_t *shell)
{
    char *buf = NULL;
    char **tab = NULL;

    check_history_file_exist(shell);
    buf = get_file_content(shell);
    if (buf == NULL)
        return;
    tab = my_split(buf, '\n');
    if (tab == NULL)
        return;
    fill_linked_list(shell, tab);
    free(buf);
}