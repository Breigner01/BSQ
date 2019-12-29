/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** BSQ
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int retrieve_number(char *buffer, int *nb)
{
    int k = 0;
    char *nb_str;

    while (buffer[k] != '\n')
        k += 1;
    nb_str = malloc(sizeof(char) * (k + 1));
    for (int i = 0; i < k; ++i)
        nb_str[i] = buffer[i];
    nb_str[k] = '\0';
    (*nb) = my_getnbr(nb_str);
    free(nb_str);
    k += 1;
    return (k);
}

int compute_i(char **tab, unsigned int temp_size, unsigned int *i,
                unsigned int *len)
{
    unsigned int temp_i[2] = {i[0], i[1]};
    unsigned int k = temp_i[1] + temp_size;
    unsigned int j = temp_i[0] + temp_size;

    if (k > len[1] || j >= len[0]) {
        return (-1);
    }
    while (temp_i[0] <= j) {
        if (tab[temp_i[0]][k] != '.') {
            return (-1);
        }
        temp_i[0] += 1;
    }
    return (0);
}

int compute_j(char **tab, unsigned int temp_size, unsigned int *i,
                unsigned int *len)
{
    unsigned int temp_i[2] = {i[0], i[1]};
    unsigned int k = temp_i[0] + temp_size;
    unsigned int j = temp_i[1] + temp_size;

    if (k >= len[0] || j > len[1]) {
        return (-1);
    }
    while (temp_i[1] <= j) {
        if (tab[k][temp_i[1]] != '.') {
            return (-1);
        }
        temp_i[1] += 1;
    }
    return (0);
}