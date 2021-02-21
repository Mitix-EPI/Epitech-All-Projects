/*
** EPITECH PROJECT, 2020
** my_isalnum
** File description:
** return 1 if a char is a digit
*/

int my_isalnum(char c)
{
    if (c < 48 || c > 57)
        return (0);
    return (1);
}