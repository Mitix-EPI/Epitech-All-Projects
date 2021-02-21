/*
** EPITECH PROJECT, 2020
** move_inside_linked_list.c
** File description:
** move_inside_linked_list.c
*/

#include "minishell2.h"
#include "history/history.h"
#include "history/move_inside_linked_list.h"

char *get_history_next(shell_t *shell)
{
    if (!shell->cur_history)
        return (NULL);
    if (shell->cur_history->next) {
        shell->cur_history = shell->cur_history->next;
        return (shell->cur_history->command);
    }
    shell->cur_history = NULL;
    return ("");
}

char *get_history_previous(shell_t *shell)
{
    if (!shell->cur_history) {
        for (history_t *tmp = shell->history; tmp; tmp = tmp->next)
            shell->cur_history = tmp;
        if (shell->cur_history)
            return (shell->cur_history->command);
        else
            return (NULL);
    }
    if (shell->cur_history->previous) {
        shell->cur_history = shell->cur_history->previous;
        return (shell->cur_history->command);
    }
    return (NULL);
}