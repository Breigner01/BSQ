/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** main
*/

int bsq(char *);

int main(int ac, char **av)
{
    int check = 0;

    if (ac != 2)
        return (84);
    check = bsq(av[1]);
    return (check);
}