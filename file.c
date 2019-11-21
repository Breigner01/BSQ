/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** BSQ
*/

#include <stdio.h>

int compute_j(char **tab, int temp_size, int temp_j)
{
    int k = 0;

    k = temp_j + temp_size;
    while (temp_j <= k) {
        if (tab[k][temp_j] == 'o')
            return (-1);
        temp_j++;
    }
    return (0);
}

int compute_i(char **tab, int temp_size, int temp_i)
{
    int k = 0;

    k = temp_i + temp_size;
    while (temp_i <= k) {
        if (tab[k][temp_i] == 'o')
            return (-1);
        temp_i++;
    }
    return (0);
}