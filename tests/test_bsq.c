/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

TestSuite (bsq, .init=redirect_all_stdout, .timeout=2);

Test (bsq, map_100_100)
{
    char const *filepath = "tests/mouli_maps/intermediate_map_100_100";
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * ((100 + 1) * 100));

    read(fd, buffer, ((100 + 1) *100));
    bsq(filepath);
    cr_assert_stdout_eq_str(buffer);
}