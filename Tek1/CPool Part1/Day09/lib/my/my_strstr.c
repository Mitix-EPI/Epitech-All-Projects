/*
** EPITECH PROJECT, 2019
** my_strstr.c
** File description:
** reproduce behavior str fonction
*/

int my_count1(char const *to_find)
{
    int i = 0;

    while (to_find[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strstr(char *str, char const *to_find)
{
    int nb = my_count1(to_find);
    int i = 0;
    int c = 0;

    while (str[i] != '\0'){
        c = 0;
        while (to_find[c] == str[i + c] && to_find[c] != '\0'){
            c++;
        }
        if (c == nb){
            return (str + i);
        }
        i++;
    }
    return ((void *)0);
}
