/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** scripting handle file
*/

#include "scripting/handle_file.h"
#include "commands.h"
#include "parser/parser.h"
#include "environnement/manipulation.h"
#include "tree.h"
#include "parser/exec_commands.h"

int handle_file(shell_t *shell, char *path)
{
    FILE *fp;
    char *buffer = NULL;
    size_t len = 0;
    ssize_t read = 0;
    int first = 1;

    if (path == NULL || (fp = fopen(path , "r")) == NULL)
        return (-1);
    while ((read = getline(&buffer, &len, fp)) != -1) {
        if (buffer[read - 1] == '\n')
            buffer[read - 1] = '\0';
        if (first && !my_strstr(buffer, "#!") && !my_strstr(buffer, "42sh"))
            return (-1);
        first = 0;
        if (my_str_to_word_array(buffer)[0][0] == '#')
            continue;
        exec_commands_from_tree(shell, parse_command(shell, buffer));
    }
    return (first == 1 ? -1 : 0);
}