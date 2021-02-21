/*
** EPITECH PROJECT, 2020
** parsing
** File description:
** function to parse every lines
*/

#include "asm.h"

char *parse_type(char *str, int *i)
{
    char *type = malloc(sizeof(char) * (5 + 1));
    fill_str(type, 5, '\0');

    for (int index = 0; str[*i] && str[*i] != ' ' && str[*i] != '\t' &&
    str[*i] != ','; *i += 1)
        type[index++] = str[*i];
    return (type);
}

char *get_arg(char *str, int *i)
{
    char *argument = NULL;
    int index_start = *i;
    int len = 0;

    for (; str[*i] && str[*i] != ' ' && str[*i] != '\t' && str[*i] != ',';
    *i += 1);
    len = *i - index_start;
    argument = malloc(sizeof(char) * (len + 1));
    fill_str(argument, len, '\0');
    len = 0;
    for (; index_start < *i; index_start += 1)
        argument[len++] = str[index_start];
    return (argument);
}

char **parse_args(char *str, int *i)
{
    char **args = malloc(sizeof(char *) * (4 + 1));
    int j = 0;

    fill_arr_null(args, 4);
    for (; str && str[*i]; *i += 1) {
        if (str[*i] != ' ' && str[*i] != '\t' && str[*i] != ',') {
            args[j] = get_arg(str, i);
            j++;
        }
    }
    return (args);
}

void parse_line_for_node(asm_t *asm_c, char *line, int line_ind, label_t **lab)
{
    line_t new_line;
    int i = 0;

    new_line.line = line_ind + 1;
    for (; line[i] && (line[i] == '\t' || line[i] == ' ' ||
    line[i] == ','); i += 1);
    if (i = check_label(line))
        create_label(line, &i, &asm_c->label, asm_c);
    for (; line[i] && (line[i] == '\t' || line[i] == ' ' ||
    line[i] == ','); i += 1);
    new_line.type = parse_type(line, &i);
    for (; line[i] && (line[i] == '\t' || line[i] == ' ' ||
    line[i] == ','); i += 1);
    new_line.arg = parse_args(line, &i);
    give_bytepos(asm_c, &new_line);
    add_element(&asm_c->head, new_line);
}

void debug_disp(node_t *head)
{
    node_t *tmp = head;

    while (tmp) {
        printf("line : %d\n", tmp->line.line);
        printf("type : %s\n", tmp->line.type);
        for (int i = 0; tmp->line.arg && tmp->line.arg[i] != NULL; i++)
            printf("arg[%d] : %s\n", i, tmp->line.arg[i]);
        tmp = tmp->next;
    }
}

void parse_instructions(asm_t *asm_c, char **arr, int i)
{
    int ret = 0;

    asm_c->label = NULL ;
    asm_c->head = NULL;
    for (; arr && arr[i] != NULL; i += 1) {
        if (!arr[i][0] || arr[i][0] == '\n' || check_empty_line(arr[i]))
            continue;
        if (ret = line_parser(arr[i]) != 0)
            my_exit(ret);
        if (ret = is_label_without_instruction(arr[i])) {
            create_label(arr[i], &ret, &asm_c->label, asm_c);
            continue;
        }
        parse_line_for_node(asm_c, arr[i], i, &asm_c->label);
    }

    // debug_disp(asm_c->head);
}
