/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-alexandre.juan
** File description:
** port
*/

#include "server/my_ftp.h"

int init_active_mode(ip_t infos, client_ftp_t *client, serv_ftp_t *serv)
{
    (void) serv;
    struct sockaddr_in sa;
    socklen_t size = sizeof(sa);
    sa.sin_port = htons(infos.port);
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(infos.ip);
    client->socket_mode = socket(AF_INET, SOCK_STREAM, 0);
    if (client->socket_mode < 0)
        return 0;
    if (connect(client->socket_mode, (struct sockaddr *)&sa, size) < 0)
        return 0;
    send_response(client->socket, 200, "Connection Etablished.");
    client->state = ACTIVE;
    return 1;
}

void port_func(client_ftp_t *client, char **command, serv_ftp_t *serv)
{
    (void) serv;
    int fd = client->socket;
    if (!is_client_logged_in(client)) {
        send_response(fd, 530, "Authentification required.");
        return;
    }
    if (count_arg_command(command) < 2) {
        send_response(fd, 501, "Not enough argument.");
        return;
    }
    ip_t infos = parse_ip(command[1]);
    if (!infos.ip)
        send_response(fd, 502, "Not good argument.");
    else if (init_active_mode(infos, client, serv) != 1) {
        send_response(fd, 550, "Error initializing active mode.");
    }
}

ip_t parse_ip(char *arg)
{
    ip_t infos;
    infos.ip = NULL;
    uint16_t port = 0;
    int pos_port = 0;
    int count = 0;

    if (count_char(arg, ',') != 5)
        return infos;
    arg = change_char_from_str(arg, ',', '.');
    for (pos_port = strlen(arg) - 1; pos_port > 0 && count < 2; pos_port--)
        if (arg[pos_port - 1] == '.')
            count++;
    char *port_str = &arg[pos_port];
    port = calc_port(port_str);
    for (int i = pos_port, size = strlen(arg); i < size; i++)
        arg[i] = 0;
    if (!is_valid_ip_address(arg))
        return infos;
    infos.ip = strdup(arg);
    infos.port = port;
    return infos;
}

char *change_char_from_str(char *str, char c_origin, char new_c)
{
    for (int i = 0; str && str[i]; i++) {
        if (str[i] == c_origin)
            str[i] = new_c;
    }
    return str;
}
