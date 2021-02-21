/*
** EPITECH PROJECT, 2019
** my_evil_str
** File description:
** reverse string
*/

int my_count(char *str)
{
    int i = 0;
    while(str[i] != '\0'){
        i = i + 1;
    }
    return (i);
}

char *my_evil_str(char *str)
{
    int i = 0;
    int n = 0;
    int max;
    char tab[my_count(str)+1];

    while(str[i] != '\0'){
        i = i + 1;
    }
    i = i - 1;
    while(i >= 0){
        tab[n] = str[i];
        i = i - 1;
        n = n + 1;
    }
    str = tab;
    str[n] = '\0';
    return (str);
}
