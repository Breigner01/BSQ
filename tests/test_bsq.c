/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

TestSuite (bsq, .init=redirect_all_stdout, .timeout=2);

Test (bsq, map_100_100)
{
    char *buffer = malloc(sizeof(char) * );
    bsq("tests/mouli_maps/intermediate_map_100_100");
    cr_assert_stdout_eq_str();
}