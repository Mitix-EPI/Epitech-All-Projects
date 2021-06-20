/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** help
*/

#include "client/myteams.h"

void help_func(client_t *cli, char **command)
{
    (void) cli;
    (void) command;
    char str[] = "/login [“user_name”] : set the user_name used by client\n\
/logout : disconnect the client from the server\n\
/users : get the list of all users that exist on the domain\n\
/user [“user_uuid”] : get information about a user\n\
/send [“user_uuid”] [“message_body”] : send a message to a user\n\
/messages [“user_uuid”] : list all messages exchange with an user\n\
/subscribe [“team_uuid”] : subscribe to the event of a team and its sub\
directories (enable reception\nof all events from a team)\n\
/subscribed ?[“team_uuid”] : list all subscribed teams or list all users \
subscribed to a team\n/unsubscribe [“team_uuid”] : unsubscribe from a team\n\
/use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”] : \
use specify a context team/channel/thread\n\
/create : based on what is being used create the sub resource (see below)\n\
/list : based on what is being used list all the sub resources (see below)\n\
/info : based on what is being used list the current (see below)\n";
    printf("%s", str);
}
