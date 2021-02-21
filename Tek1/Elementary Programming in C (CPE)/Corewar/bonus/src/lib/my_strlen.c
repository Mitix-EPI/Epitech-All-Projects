/*
** EPITECH PROJECT, 2020
** my strlen
** File description:
** return length of a str
*/

int my_strlen(char *str)
{
    int len = 0;

    for (; str && str[len]; len += 1);
    return (len);
}