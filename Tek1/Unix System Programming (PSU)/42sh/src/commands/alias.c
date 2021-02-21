/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** Cmd of minishell2
*/

#include "minishell2.h"
#include "aliases/aliases.h"

void    display_aliases(shell_t *shell)
{
    alias_t *node_alias = shell->alias;
    char *var_str = malloc(sizeof(char) * 1);

    var_str[0] = '\0';
    while (node_alias) {
        if (node_alias->name != shell->alias->name)
            var_str = my_strcat2(var_str, "\n", -1, 0);
        var_str = my_strcat2(var_str, node_alias->name, -1, 0);
        var_str = my_strcat2(var_str, "\t", -1, 0);
        var_str = my_strcat2(var_str, node_alias->command, -1, 0);
        node_alias = node_alias->next;
    }
    my_printf("%s", var_str);
    if (var_str[0])
        my_printf("\n");
}

int    cmd_alias(shell_t *shell, char **argv)
{
    int ac = 0;
    char *args = NULL;

    for (; argv[ac]; ac += 1);
    if (ac == 0) {
        display_aliases(shell);
        return (0);
    } else if (ac < 2)
        return (0);
    args = my_arr_join(argv + 1, " ");
    if (!strcmp(argv[0], "alias"))
        printf("alias: Too dangerous to alias that.\n");
    else
        add_alias(args, argv[0], &shell->alias);
    return (0);
}

int    cmd_unalias(shell_t *shell, char **argv)
{
    for (int i = 0; argv[i]; i += 1) {
        unset_alias(shell, argv[i]);
    }
    return (0);
}