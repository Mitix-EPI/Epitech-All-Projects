/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_my_name
*/

#include <criterion/criterion.h>
#include "../../include/my.h"
#include <criterion/redirect.h>

Test(mysh, return_0_bcs_exit)
{
    char *env[2];
    env[0] = "PATH=/usr/sbin:/sbin:/usr/bin:/bin";
    env[1] = NULL;
    FILE *f_stdin = cr_get_redirected_stdin();
    cr_redirect_stdout();
    fprintf(f_stdin, "exit\n");
    fclose(f_stdin);
    cr_assert_eq(mysh(env), 0);
}

Test(mysh, return_0_bcs_ls)
{
    char *env[2];
    env[0] = "PATH=/usr/sbin:/sbin:/usr/bin:/bin";
    env[1] = NULL;
    FILE *f_stdin = cr_get_redirected_stdin();
    cr_redirect_stdout();
    fprintf(f_stdin, "/bin/ls\nexit\n");
    fclose(f_stdin);
    cr_assert_eq(mysh(env), 0);
}

Test(mysh, return_0_bcs_cd)
{
    char *env[2];
    env[0] = "PATH=/usr/sbin:/sbin:/usr/bin:/bin";
    env[1] = NULL;
    FILE *f_stdin = cr_get_redirected_stdin();
    cr_redirect_stdout();
    fprintf(f_stdin, "cd include\ncd -\ncd ..\nexit\n");
    fclose(f_stdin);
    cr_assert_eq(mysh(env), 0);
}

Test(mysh, return_0_bcs_envs)
{
    char *env[5];
    env[0] = "PATH=/usr/sbin:/sbin:/usr/bin:/bin";
    env[1] = "YOLO=coucou";
    env[2] = "UICHARD=nope";
    env[3] = "NOPE=uichard";
    env[4] = NULL;
    FILE *f_stdin = cr_get_redirected_stdin();
    cr_redirect_stdout();
    fprintf(f_stdin, "setenv TEST coucou\nunsetenv TEST\nenv\nexit\n");
    fclose(f_stdin);
    cr_assert_eq(mysh(env), 0);
}

Test(mysh, return_0_bcs_setenv_errors)
{
    char *env[5];
    env[0] = "PATH=/usr/sbin:/sbin:/usr/bin:/bin";
    env[1] = "YOLO=coucou";
    env[2] = "UICHARD=nope";
    env[3] = "NOPE=uichard";
    env[4] = NULL;
    FILE *f_stdin = cr_get_redirected_stdin();
    cr_redirect_stdout();
    fprintf(f_stdin, "setenv 567 neff\nsetenv TOTO [jodde\nexit\n");
    fclose(f_stdin);
    cr_assert_eq(mysh(env), 0);
}