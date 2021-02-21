/*
** EPITECH PROJECT, 2019
** my_strupcase.c
** File description:
** put every letter
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= 122 && str[i] >= 97)
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}
