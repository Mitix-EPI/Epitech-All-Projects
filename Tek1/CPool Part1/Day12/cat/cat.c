/*
** EPITECH PROJECT, 2019
** cat.c
** File description:
** return lecture
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int my_putstr(char const *str);

char *reset_str(char *str, int size)
{
    for (int j = 0; j < size; j++)
        str[j] = '\0';
    return (str);
}

int display_error(char *name_file)
{
    int s = 0;
    char *error_description;

    switch (errno) {
    case 2:
        s = 1;
        error_description = "No such file or directory\n";
        break;
    case 21:
        s = 1;
        error_description = "Is a directory\n";
        break;
    case 13:
        s = 1;
        error_description = "Permission denied\n";
        break;
    default:
        s = 0;
        return (0);
        break;
    }
    if (s > 0) {
        my_putstr("cat: ");
        my_putstr(name_file);
        my_putstr(": ");
        my_putstr(error_description);
        return (84);
    }
}

int cat_read(char *av)
{
    int fd = open(av, O_RDONLY);
    char nb_bytes [30000];
    int size;

    if (fd == -1) {
        return (display_error(av));
    }
    size = read(fd, nb_bytes, 30000);
    if (display_error(av) == 84)
        return (84);
    for (int i = 0; nb_bytes[i] != '\0'; i++)
        write(1, &nb_bytes[i], 1);
    reset_str(nb_bytes, size);
    close(fd);
    return (0);
}

int cat(int argc, char **argv)
{
    char file[30000];
    int size, test;
    int res = 0;

    if (argc == 1) {
        for (int j = 0; j >= 0; j++) {
            size = read(0, file, 30000);
            for (int k = 0; file[k] != '\0'; k++)
                write(1, &file[k], 1);
            reset_str(file, size);
        }
        return (0);
    }
    for (int i = 1; i < argc; i++) {
        test = cat_read(argv[i]);
        if (test == 84)
            res = 84;
        test = 0;
    }
    return (res);
}
