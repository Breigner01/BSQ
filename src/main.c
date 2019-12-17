/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include "my.h"

int bsq(char *);
int retrieve_number(char *, int *);

int wrong_line_nb(char *filepath)
{
    struct stat stat_info;
    int fd = open(filepath, O_RDONLY);
    int size = 0;
    int i = 0;
    int line = 0;
    int nb = 0;
    char *buffer;

    stat(filepath, &stat_info);
    size = stat_info.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    read(fd, buffer, size);
    i = retrieve_number(buffer, &nb);
    for (; buffer[i] != '\0'; ++i)
        if (buffer[i] == '\n')
            line += 1;
    if (line != nb)
        return (84);
    free(buffer);
    close(fd);
    return (0);
}

int wrong_char(char *filepath)
{
    struct stat stat_info;
    int fd = open(filepath, O_RDONLY);
    int size = 0;
    int i = 0;
    char *buffer;

    stat(filepath, &stat_info);
    size = stat_info.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    read(fd, buffer, size);
    for (; buffer[i] != '\0'; ++i) {
        if ((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '.' &&
            buffer[i] != 'o' && buffer[i] != '\n')
            return (84);
    }
    free(buffer);
    close(fd);
    return (0);
}

int no_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return (84);
    close(fd);
    return (0);
}

int error(char *filepath)
{
    if (no_file(filepath) == 84 || wrong_char(filepath) == 84 ||
        wrong_line_nb(filepath) == 84)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    int check = 0;

    if (ac != 2)
        return (84);
    if (error(av[1]) == 84)
        return (84);
    check = bsq(av[1]);
    return (check);
}