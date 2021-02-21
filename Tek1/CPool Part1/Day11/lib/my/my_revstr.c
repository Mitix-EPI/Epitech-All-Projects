/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** reverse string
*/

int count_char(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    i--;
    return (i);
}

char *put_str_into_str(char *str, char *reverse)
{
    int i = 0;

    while (str[i] != '\0'){
        str[i] = reverse[i];
        i++;
    }
    return (str);
}

char *my_revstr(char *str)
{
    char reverse[count_char(str) + 1];
    int i = count_char(str);
    int n = 0;

    while (i >= 0){
        reverse[n] = str[i];
        n++;
        i--;
    }
    put_str_into_str(str, reverse);
    return (str);
}
