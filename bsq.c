/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** find the biggest square in a map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include "my.h"

int compute_j(char **, int, int);
int compute_i(char **, int, int);

int retrieve_nb(char ***tab, char *buffer, int *nb)
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
    (*tab) = malloc(sizeof(char *) * ((*nb) + 1));
    k++;
    return (k);
}

void fill_tab(char ***tab, char *buffer, int (*len)[2])
{
    int j = 0;
    int k = 0;

    k = retrieve_nb(tab, buffer, &(*len)[1]);
    for (int i = k; buffer[i] != '\n'; i++)
        (*len)[0]++;
    for (int i = 0; i < (*len)[1]; i++) {
        (*tab)[i] = malloc(sizeof(char) * ((*len)[0] + 2));
        while (buffer[k] != '\n' && buffer[k] != '\0') {
            (*tab)[i][j] = buffer[k];
            j++;
            k++;
        }
        (*tab)[i][j] = '\0';
        k++;
        j = 0;
    }
}

void find_bsq(char **tab, int *i, int (*coords)[2], int *size)
{
    int temp_size = 1;
    int temp_i = i[0];
    int temp_j = i[1];
    int check;

    for (; tab[i[0]][i[1]] == '.'; temp_size++) {
        check = compute_j(tab, temp_size, temp_j);
        if (check == -1)
            break;
        check = compute_i(tab, temp_size, temp_i);
        if (check == -1)
            break;
    }
    if (temp_size > (*size)) {
        (*coords)[0] = i[0];
        (*coords)[1] = i[1];
        (*size) = temp_size;
    }
}

void cover_bsq(char **tab, int *len)
{
    int size = 0;
    int coords[2] = {0 ,0};
    int i[2] = {0, 0};

    for (; i[0] + 1 < len[0]; i[0]++) {
        for (i [1] = 0; i[1] + 1 < len[1]; i[1]++)
            find_bsq(tab, i, &coords, &size);
    }
    for (int j = coords[0]; j < coords[0] + size; j++) {
        for (int k = coords[1]; k < coords[1] + size && k < (*len); k++)
            tab[j][k] = 'x';
    }
    for (int j = 0; j < (*len); j++) {
        my_putstr(tab[j]);
        my_putchar('\n');
        free(tab[j]);
    }
    free(tab);
}

int bsq(char *filepath)
{
    struct stat stat_info;
    int  fd = open(filepath, O_RDONLY);
    int size;
    int check = 0;
    char *buffer;
    char **tab;
    int len[2] = {0, 0};

    stat(filepath, &stat_info);
    size = stat_info.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    if (buffer == NULL)
        return (84);
    check = read(fd, buffer, size);
    if (check == -1)
        return (84);
    fill_tab(&tab, buffer, &len);
    cover_bsq(tab, len);
    free(buffer);
    return (0);
}