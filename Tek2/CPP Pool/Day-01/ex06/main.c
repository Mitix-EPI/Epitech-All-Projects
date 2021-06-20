/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-alexandre.juan
** File description:
** main
*/

#include "drawing.h"
#include "menger.h"
#include "bitmap.h"

void initialize_image(size_t size, unsigned int *buffer, unsigned int **img)
{
    memset(buffer, 0, size * size * sizeof(*buffer));
    for (size_t i = 0; i < size; ++i)
        img[i] = buffer + i * size;
}

void write_bmp_header(int fd, size_t size)
{
    bmp_header_t header;

    make_bmp_header(&header, size);
    write(fd, &header, sizeof(header));
}

void write_bmp_info_header(int fd, size_t size)
{
    bmp_info_header_t info;

    make_bmp_info_header(&info, size);
    write(fd, &info, sizeof(info));
}

void create_bitmap_from_buffer(size_t size, unsigned int *buffer, char *str)
{
    int fd = open(str, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    write_bmp_header(fd, size);
    write_bmp_info_header(fd, size);
    write(fd, buffer, size * size * sizeof(*buffer));
    close(fd);
}

int main(int ac, char **av)
{
    if (ac != 4) {
        write(2, "menger_face file_name size level\n", 34);
        return 84;
    }
    size_t size = (size_t)(atoi(av[2]));
    unsigned int *buffer = malloc(size * size * sizeof(*buffer));
    unsigned int **img = malloc(size * sizeof(*img));
    int sizeSquare = atoi(av[2]);
    int nbLevel = atoi(av[3]);
    point_t point = { 0, 0 };
    initialize_image(size, buffer, img);
    menger(sizeSquare, point, nbLevel, img);
    create_bitmap_from_buffer(size, buffer, av[1]);
    return 0;
}
