/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** create_core_file
*/

#include "asm.h"

static const char *arr[] = {"live", "zjmp", "fork", "lfork", NULL};
static const char *exception[] = {
    "zjmp",
    "ldi",
    "sti",
    "fork",
    "lldi",
    "lfork",
    NULL
};

int calc_size_cob(char *arg)
{
    for (int i = 0; arr[i]; i += 1) {
        if (my_strcmp(arg, arr[i]) == 0)
            return (1);
    }
    return (2);
}

int calc_size_dir(char *arg)
{
    for (int i = 0; exception[i]; i += 1)
        if (my_strcmp(arg, exception[i]) == 0)
            return (IND_SIZE);
    return (DIR_SIZE);
}

void calc_prog_size(asm_t *asm_c)
{
    int calc = 0;
    node_t *tmp = asm_c->head;

    while (tmp) {
        calc += calc_size_cob(tmp->line.type);
        for (int i = 0; tmp->line.arg && tmp->line.arg[i] != NULL; i++) {
            if (tmp->line.arg[i][0] == 'r')
                calc += 1;
            else if (tmp->line.arg[i][0] == '%')
                calc += calc_size_dir(tmp->line.type);
            else
                calc += 2;
        }
        tmp = tmp->next;
    }
    asm_c->header.prog_size = little_to_big(calc);
}

void create_cor_file(node_t *head, char *path, asm_t *asm_c)
{
    int fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, \
    S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    node_t *tmp = head;

    calc_prog_size(asm_c);
    write_header(fd, asm_c->header.prog_name, asm_c->header.comment, \
    asm_c->header.prog_size);
    while (tmp) {
        write_instruc(fd, tmp->line, asm_c->label);
        tmp = tmp->next;
    }
    close(fd);
}