/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_showmem
*/

int my_strlen(char const *);

int my_showmem(char const *str, int size)
{
    int len = my_strlen(str);

    size += len;
    return size;
}
