/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** launch_server4
*/

#include "server/myteams.h"

void display_reading_from_client(server_t *s, int i)
{
    printf("[<-]Reading from client %s:%d: %s", \
inet_ntoa(s->_c_list[i]._addr.sin_addr), \
ntohs(s->_c_list[i]._addr.sin_port), s->_buffer);
}

void *my_malloc(size_t size)
{
    void *res = malloc(size);
    memset(res, 0, size);
    return (res);
}

int read_from_client(server_t *s, int i)
{
    s->_buffer = my_malloc(sizeof(char) * (4096 + 1));
    if (strlen(s->_c_list[i]._cmd) == 0)
        render_command(s->_c_list[i]._prev_cmd, s->_c_list[i]._cmd);
    for (char buff[2] = {0}; 1;) {
        int nbBytes = read(s->_c_list[i]._socket, buff, 1);
        if (nbBytes < 0) {
            printf("BUFFER: [%s]\n", s->_buffer);
            perror("Error reading incoming stream");
            exit(EXIT_ERROR);
        } else if (nbBytes == 0) {
            disconnect_client(&(s->_c_list[i]), s);
            return (-1);
        }
        s->_buffer = strcat(s->_buffer, buff);
        if (buff_ends(s->_buffer))
            break;
    }
    display_reading_from_client(s, i);
    render_command(s->_c_list[i]._cmd, s->_buffer);
    free(s->_buffer);
    return (1);
}

void handle_activity(server_t *s)
{
    if (FD_ISSET(s->_sfd, &s->_read_fds)) {
        handle_new_connection(s);
    }
    if (FD_ISSET(s->_sfd, &s->_except_fds))
        clean_shutdown(s, "Exception on reading in handle activity\n");
    for (int i = 0; i < s->_max_client; i++) {
        handle_activity_2(s, i);
    }
}

void check_activity(server_t *server)
{
    int activity = select(server->_max_fd + 1, &server->_read_fds, \
&server->_write_fds, &server->_except_fds, NULL);

    if (activity == -1) {
        clean_shutdown(server, "[X]Error: check_activity: select\n");
    } else if (activity == 0) {
        clean_shutdown(server, "[?] Select return 0 in check activity\n");
    } else {
        handle_activity(server);
    }
}
