/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Cmd of minishell2
*/

#include "minishell2.h"
#include "variables/manipulation.h"

static int    error_handling(char *name)
{
    if (!my_str_isalpha(my_char_tostring(name[0]))) {
        my_putstr("set: Variable name must begin with a letter.\n");
        return (1);
    }
    if (!my_str_isalpha(name) && !my_str_isnum(name) && name[0] != '_') {
        my_putstr("set: Variable name must contain ");
        my_putstr("alphanumeric characters.\n");
        return (1);
    }
    return (0);
}

void    display_vars(shell_t *shell)
{
    var_t *node_var = shell->first_var;
    char *var_str = malloc(sizeof(char) * 1);

    var_str[0] = '\0';
    while (node_var) {
        if (node_var->var != shell->first_var->var)
            var_str = my_strcat2(var_str, "\n", -1, 0);
        var_str = my_strcat2(var_str, node_var->var, -1, 0);
        var_str = my_strcat2(var_str, "\t", -1, 0);
        var_str = my_strcat2(var_str, node_var->value, -1, 0);
        node_var = node_var->next;
    }
    my_printf("%s", var_str);
    if (var_str[0])
        my_printf("\n");
}

int    cmd_set(shell_t *shell, char **argv)
{
    int ac = 0;
    char **values = NULL;

    for (; argv[ac]; ac += 1);
    if (ac == 0) {
        display_vars(shell);
        return (0);
    }
    for (int i = 0; argv[i]; i++) {
        if (argv[i][0] == '=') {
            my_printf("set: Variable name must begin with a letter.\n");
            return (1);
        }
        values = my_split_str(argv[i], "=");
        if (error_handling(values[0]))
            return (1);
        if (!values || !values[0])
            return (1);
        set_var(shell, values[0], values[1]);
    }
    return (0);
}

int    cmd_unset(shell_t *shell, char **argv)
{
    for (int i = 0; argv[i]; i += 1) {
        unset_var(shell, argv[i]);
    }
    return (0);
}