/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** prompt
*/

#include "minishell2.h"
#include "prompt.h"
#include "commands.h"
#include "parser/parser.h"
#include "environnement/manipulation.h"
#include "tree.h"
#include "parser/exec_commands.h"
#include "history/history.h"
#include "ncurses/ncurses.h"

void    disp_error(char *msg, int error)
{
    if (error == ENOEXEC)
        my_printf("%s: Exec format error. Wrong Architecture.\n", msg);
    else
        my_printf("%s: %s.\n", msg, strerror(error));
}

void    give_branch(void)
{
    char *branch = malloc(sizeof(char) * 200);
    char *line = NULL;
    int i = 0;
    size_t len = 0;
    int j = 0;
    ssize_t read;
    FILE *fp = fopen(".git/HEAD", "r");

    if (!fp)
        return;
    while ((read = getline(&line, &len, fp)) != -1)
        line[read - 1] = 0;
    for (; line[i]; i++);
    i--;
    for (; i >= 0 && line[i] != '/'; i--)
        branch[j++] = line[i];
    branch[j] = 0;
    my_printf(" [%s] ", my_revstr(branch));
    free(branch);
}

void    disp_prompt(void)
{
    char path[4096];

    getcwd(path, 4095);
    my_printf("%s", path);
    give_branch();
    my_printf("> ");
}

char *get_buffer(shell_t *shell, int enable_ncurse)
{
    static int i = 0;
    char *buffer = NULL;
    size_t len = 0;
    ssize_t read = 0;

    if (isatty(0) && enable_ncurse == 1) {
        if (i++ < 1)
            system("clear");
        buffer = ncurse(shell);
    } else {
        if ((read = getline(&buffer, &len, stdin)) == -1)
            return (NULL);
        if (buffer[read - 1] == '\n')
            buffer[read - 1] = '\0';
    }
    return (buffer);
}

void    read_input(shell_t *shell, int enable_ncurse)
{
    char *buffer = NULL;
    node_t *head = NULL;

    while (1) {
        if (!enable_ncurse)
            disp_prompt();
        buffer = get_buffer(shell, enable_ncurse);
        if (!buffer)
            break;
        (is_historyable(buffer) == 0) ? history(buffer, shell) : 0;
        head = parse_command(shell, buffer);
        shell->last_exit_code = 0;
        check_done();
        exec_commands_from_tree(shell, head);
    }
    if (isatty(0) > 0)
        my_printf("exit\n");
}