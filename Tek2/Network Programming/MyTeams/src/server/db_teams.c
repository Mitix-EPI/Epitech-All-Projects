/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** db_messages
*/

#include "server/myteams.h"

void save_teams(server_t *s)
{
    int fd = open("teams_teams.db", O_CREAT | O_WRONLY | O_TRUNC, \
S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    list_teams_t *tmp = s->_teams;

    while (tmp) {
        write(fd, &tmp->_team, sizeof(team_t));
        tmp = tmp->next;
    }
    close(fd);
}

void read_teams(server_t *s)
{
    int fd = open("teams_teams.db", O_RDONLY);

    if (fd < 0) {
        printf("No file teams_teams.db\n");
        return;
    }
    team_t team;
    for (int bt = 0, i = 0; (bt = read(fd, &team, sizeof(team_t))) > 0; i++)
        s->_teams = add_team_at_the_end(team, s->_teams);
    close(fd);
}
