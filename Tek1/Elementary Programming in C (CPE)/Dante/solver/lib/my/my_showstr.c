/*
** EPITECH PROJECT, 2019
** show strings
** File description:
** djibril ta3 la street
*/

void my_putchar(char);

int my_putnbr_base(int nbr, char const *base);

void my_showstr(char const *str)
{
    int result;
    int len = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] >= 32 && str[i] < 127)
            my_putchar(str[i]);
        else {
            result = str[i];
            while (result > 0) {
                result = result / 8;
                len += 1;
            }
            my_putchar('\\');
            for (int icr = 0; icr + len < 3; icr += 1)
                my_putchar('0');
            my_putnbr_base(str[i], "01234567");
            len = 0;
        }
    }
}
