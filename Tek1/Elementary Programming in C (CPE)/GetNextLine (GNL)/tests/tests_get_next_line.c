/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** tests_get_next_line
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>

char *get_next_line(int fd);
char *ending_choice(char *msg, int i, int rd, int *idx);
char *my_realloc(char *str, int n);
char *buff_size_alloc(int *msg_size, char *msg, char *buff, int i);
int reader(int *rd, int *idx, int fd, char *buff);

Test(get_next_line, read_line)
{
    int fd = -1;
    char *expected = "Confidence is so overrated.";
    char *got = NULL;

    fd = open("tests/data.txt", O_RDONLY);
    cr_redirect_stdout();
    got = get_next_line(fd);
    cr_assert_str_eq(got, expected);
    close(fd);
}

Test(reader, return1)
{
    int fd = -1;
    char *expected = "Confidence is so overrated.";
    int got = 0;
    static int rd = 1;
    static int idx = 1;
    static char buff[4];

    fd = open("tests/notexistingfile.txt", O_RDONLY);
    cr_redirect_stdout();
    got = reader(&rd, &idx, fd, buff);
    cr_assert_eq(got, 1);
    close(fd);
}

Test(get_next_line, returnNULL)
{
    int fd = -1;
    char *expected = "Confidence is so overrated.";
    char *got = NULL;

    fd = open("tests/null", O_RDONLY);
    cr_redirect_stdout();
    cr_redirect_stdout();
    printf("%d\n%d\n%d\n", fd, fd, fd);
    got = get_next_line(fd);
    cr_assert_null(got);
    close(fd);
}

Test(get_next_line, read_line2)
{
    char *expected = NULL;
    char *got = get_next_line(-1);
    cr_assert_null(got);
}

Test(ending_choice, should_return_null)
{
    static int a = 3;
    char *msg = "S";
    char *got = ending_choice(msg, 0, 0, &a);
    cr_assert_null(got);
}

Test(ending_choice, should_return_null1)
{
    static int a = 3;
    char *msg = "S";
    char *got = ending_choice(msg, 1, 0, &a);
    cr_assert_not_null(got);
}

Test(my_realloc, should_return_again_null)
{
    char *str = "Salut les amis";

    char *got = my_realloc(str, 1000000000);
    cr_assert_null(got);
}