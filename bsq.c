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
    (*tab) = malloc(sizeof(char *) * ((*nb) + 1));
    k++;
    return (k);
}

void fill_tab(char ***tab, char *buffer)
{
    int j = 0;
    int k = 0;
    int len = 0;
    int nb = 0;

    k = retrieve_nb(tab, buffer, &nb);
    for (int i = k; buffer[i] != '\n'; i++)
        len++;
    for (int i = 0; i < nb; i++) {
        (*tab)[i] = malloc(sizeof(char) * (len + 1));
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

void bsq(char *filepath)
{
    struct stat stat_info;
    int  fd = open(filepath, O_RDONLY);
    int size;
    int check = 0;
    char *buffer;
    char **tab;

    stat(filepath, &stat_info);
    size = stat_info.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    check = read(fd, buffer, size);
    if (check == -1)
        exit(84);
    fill_tab(&tab, buffer);
}