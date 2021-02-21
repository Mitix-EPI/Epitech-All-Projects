/*
** EPITECH PROJECT, 2020
** create label
** File description:
** function to create label into struct label_t
*/

#include "asm.h"

int give_nb_bytes(line_t *new_line)
{
    char *args = check_type_arg(new_line->arg);
    char *hex = binary_to_hex(args);
    char c = getnum(hex[0]) * 16 + getnum(hex[1]);
    int pos = 0;

    pos += calc_size_arg(new_line->type);
    pos += calc_coding_byte(c, new_line->type);
    for (int i = 0; new_line->arg[i]; i += 1)
        pos += calc_args(new_line->arg[i], new_line->type);
    return (pos);
}

void add_label(asm_t *asm_file, char *label, label_t **list)
{
    node_t *tmp = asm_file->head;
    int i = 0;
    int size = 0;

    for (; tmp && tmp->next; tmp = tmp->next);
    size = (!tmp) ? calc_size_header(&asm_file->header) : tmp->line.nb_byte;
    i = (!tmp) ? 0 : give_nb_bytes(&tmp->line);
    add_element_label(list, size + i, label);
}

void create_label(char *line, int *i, label_t **label, asm_t *asm_file)
{
    char *tmp = malloc(sizeof(char) * (*i + 1));
    int index = 0;

    for (; index < *i; index += 1)
        tmp[index] = line[index];
    tmp[index] = '\0';
    add_label(asm_file, tmp, label);
    *i += 1;
}