/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** create_success
*/

#include "client/myteams.h"

void create_team(char **command)
{
    if (strcmp(command[1], "team") == 0 && strcmp(command[2], "event") == 0)
        client_event_team_created(remove_quote(command[3]), \
        remove_quote(command[4]), remove_quote(command[5]));
    if (strcmp(command[1], "team") == 0 && strcmp(command[2], "success") == 0)
        client_print_team_created(remove_quote(command[3]), \
        remove_quote(command[4]), remove_quote(command[5]));
}

void create_channel(char **command)
{
    if (strcmp(command[1], "channel") == 0 && strcmp(command[2], \
    "event") == 0) {
        client_event_channel_created(remove_quote(command[3]), \
        remove_quote(command[4]), remove_quote(command[5]));
    }
    if (strcmp(command[1], "channel") == 0 && strcmp(command[2], \
    "success") == 0) {
        client_print_channel_created(remove_quote(command[3]), \
        remove_quote(command[4]), remove_quote(command[5]));
    }
}

void create_thread(char **command)
{
    if (strcmp(command[1], "thread") == 0 && strcmp(command[2], \
    "event") == 0) {
        client_event_thread_created(remove_quote(command[3]), \
        remove_quote(command[4]), atoi(command[5]), \
        remove_quote(command[6]), remove_quote(command[7]));
    }
    if (strcmp(command[1], "thread") == 0 && strcmp(command[2], \
    "success") == 0) {
        client_print_thread_created(remove_quote(command[3]), \
        remove_quote(command[4]), atoi(command[5]), \
        remove_quote(command[6]), remove_quote(command[7]));
    }
}

void create_reply(char **command)
{
    if (strcmp(command[1], "reply") == 0 && strcmp(command[2], \
    "event") == 0) {
        printf("Test3\n");
        client_event_thread_reply_received(command[6], \
        remove_quote(command[3]), remove_quote(command[4]), \
        remove_quote(command[5]));
        printf("Test4\n");
    }
    if (strcmp(command[1], "reply") == 0 && strcmp(command[2], \
    "success") == 0) {
        client_print_reply_created(remove_quote(command[3]), \
        remove_quote(command[4]), atoi(command[5]), \
        remove_quote(command[6]));
    }
}