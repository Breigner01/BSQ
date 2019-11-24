/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** BSQ
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void limit_check()
{

}

int retrieve_number(char *buffer, int *nb)
{
    int k = 0;
    char *nb_str;

    while (buffer[k] != '\n')
        k++;
    nb_str = malloc(sizeof(char) * (k + 1));
    for (int i = 0; i < k; i++)
        nb_str[i] = buffer[i];
    (*nb) = my_getnbr(nb_str);
    free(nb_str);
    k++;
    return (k);
}

int compute_j(char **tab, unsigned int temp_size, unsigned int *temp_i,
                unsigned int *len)
{
    unsigned int k = temp_i[1] + temp_size;
    unsigned int i = temp_i[0] + temp_size;

    if (k >= len[1] || i >= len[0])
        return (-1);
    while (temp_i[0] <= i) {
        if (tab[temp_i[0]][k] == 'o' || tab[temp_i[0]][k] == '\0')
            return (-1);
        temp_i[0]++;
    }
    return (0);
}

int compute_i(char **tab, unsigned int temp_size, unsigned int *temp_i,
                unsigned int *len)
{
    unsigned int k = temp_i[0] + temp_size;
    unsigned int i = temp_i[1] + temp_size;

    if (k >= len[0] || i >= len[1])
        return (-1);
    while (temp_i[1] <= i) {
        if (tab[k][temp_i[1]] == 'o' || tab[k][temp_i[1]] == '\0')
            return (-1);
        temp_i[1]++;
    }
    return (0);
}