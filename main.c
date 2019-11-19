/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** main
*/

void bsq(char *);

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    bsq(av[1]);
}