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

int compute_j(char **, unsigned int, unsigned int *, unsigned int *);
int compute_i(char **, unsigned int, unsigned int *, unsigned int *);

int retrieve_nb(char ***tab, char *buffer, unsigned int (*len)[2])
{
    unsigned int k = 0;
    char *nb_str;

    while (buffer[k] != '\n')
        k += 1;
    nb_str = malloc(sizeof(char) * (k + 1));
    for (unsigned int i = 0; i < k; ++i)
        nb_str[i] = buffer[i];
    (*len)[0] = my_getnbr(nb_str);
    free(nb_str);
    (*tab) = malloc(sizeof(char *) * ((*len)[0] + 1));
    k += 1;
    return (k);
}

void fill_tab(char ***tab, char *buffer, unsigned int (*len)[2])
{
    int j = 0;
    int k = 0;

    k = retrieve_nb(tab, buffer, len);
    for (int i = k; buffer[i] != '\n'; ++i)
        (*len)[1] += 1;
    for (unsigned int i = 0; i < (*len)[0]; ++i) {
        (*tab)[i] = malloc(sizeof(char) * ((*len)[1] + 2));
        while (buffer[k] != '\n' && buffer[k] != '\0') {
            (*tab)[i][j] = buffer[k];
            j += 1;
            k += 1;
        }
        (*tab)[i][j] = '\0';
        k += 1;
        j = 0;
    }
}

void find_bsq(char **tab, unsigned int (*i)[2], unsigned int (*coords)[2],
                unsigned int *size, unsigned int *len)
{
    unsigned int temp_size = 1;
    unsigned int temp_i[2] = {0, 0};

    temp_i[0] = (*i)[0];
    temp_i[1] = (*i)[1];
    for (; ((*i)[0] + (*size)) <= len[0] && ((*i)[1] + (*size)) <= len[1] &&
        tab[(*i)[0]][(*i)[1]] == '.'; ++temp_size) {
        if (compute_i(tab, temp_size, temp_i, len) == -1 ||
        compute_j(tab, temp_size, temp_i, len) == -1) {
            printf("tab[%d][%d] = %c, size = %d\n", temp_i[0], temp_i[1], tab[temp_i[0]][temp_i[1]], temp_size);
            break;
        }
    }
    if (temp_size > (*size)) {
        (*coords)[0] = (*i)[0];
        (*coords)[1] = (*i)[1];
        (*size) = temp_size;
    }
}

void cover_bsq(char **tab, unsigned int *len)
{
    unsigned int size = 0;
    unsigned int coords[2] = {0 ,0};
    unsigned int i[2] = {0, 0};

    for (; i[0] < len[0]; ++i[0])
        for (i[1] = 0; i[1] < len[1]; ++i[1])
            find_bsq(tab, &i, &coords, &size, len);
    for (unsigned int j = coords[0]; j < coords[0] + size; ++j)
        for (unsigned int k = coords[1]; k < coords[1] + size && k < len[1];
        ++k)
            tab[j][k] = 'x';
    for (unsigned int j = 0; j < len[0]; ++j) {
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
    unsigned int len[2] = {0, 0};

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
