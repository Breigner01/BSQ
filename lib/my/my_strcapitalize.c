/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** capitalizes the first letter of each word
*/

char *my_strcapitalize(char *str)
{
    if (str[0] > 96 && str[0] < 123)
        str[0] -= 32;
    return (str);
}
