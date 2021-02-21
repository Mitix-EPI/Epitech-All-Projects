/*
** EPITECH PROJECT, 2019
** get_nb_digit
** File description:
** return the number of digit in an integer
*/

int get_nb_digit(int number)
{
    int digits = 0;

    do {
        number /= 10;
        ++digits;
    } while (number != 0);
    return (digits);
}

