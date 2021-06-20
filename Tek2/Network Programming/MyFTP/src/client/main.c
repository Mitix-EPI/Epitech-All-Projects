/*
** EPITECH PROJECT, 2021
** my_ftp
** File description:
** main
*/

#include "client/my_ftp.h"

struct sockaddr_in init_struct(int port)
{
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    return serv_addr;
}

void send_message(int sock)
{
    char buffer[1024] = {0};
    char message[1024] = {0};

    read(sock, buffer, 1024);
    printf("Message from buffer: %s\n", buffer);
    printf(">");
    fgets(message, 1024, stdin);
    write(sock, message, sizeof(message));
    printf("Message sent\n");
}

int main(int ac, char **av)
{
    (void) ac;
    printf("I'm CLIENT\n");
    int sock = 0;
    struct sockaddr_in serv_addr = init_struct(atoi(av[2]));

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\nSocket creation error\n");
        exit(EXIT_ERROR);
    }
    if (inet_pton(AF_INET, av[1], &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported\n");
        exit(EXIT_ERROR);
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection failed\n");
        exit(EXIT_ERROR);
    }
    send_message(sock);
    return 0;
}
