/*
** EPITECH PROJECT, 2019
** my_strcapitalize.c
** File description:
** capitalize the first letter of each word
*/

void condition_majuscule(char *str, int i)
{
    if (str[i] >= 97 && str[i] <= 122){
        if ((str[i-1] >= 32 && str[i-1] <= 47) || i == 0){
            str[i] = str[i] - 32;
        }
    }
    else if (str[i] >= 65 && str[i] <= 90){
        if (str[i - 1] < 32 || str[i] > 47){
            str[i] = str[i] + 32;
        }
    }
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        condition_majuscule(str, i);
        i++;
    }
    return (str);
}
