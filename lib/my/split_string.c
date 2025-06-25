/*
** EPITECH PROJECT, 2024
** split_string
** File description:
** split string
*/

#include "../../includes/lib.h"
#include <stdio.h>

int is_alphanumeric(char letter, char *separator)
{
    for (int i = 0; separator[i] != '\0'; i++)
        if (letter == separator[i])
            return 1;
    return 0;
}

int space_of_string(char const *str, char *separator)
{
    int space = 0;

    if (!str || !separator)
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alphanumeric(str[i], separator) == 1)
            space++;
    }
    return space;
}

char **malloc_my_array(const char *str, int space, char *separator)
{
    char **array = malloc(sizeof(char *) * (space + 2));
    int len = 0;

    if (!str || !separator)
        return 0;
    for (int j = 0; str[j] != '\0'; j++) {
        if (is_alphanumeric(str[j], separator) == 0)
            len++;
    }
    for (int i = 0; i < space + 1; i++)
        array[i] = malloc(sizeof(char) * (len + 2));
    return array;
}

char **split_string(char const *str, char *separator)
{
    char **array;
    int space = space_of_string(str, separator);
    int n = 0;
    int k = 0;

    if (!str || !separator)
        return 0;
    array = malloc_my_array(str, space, separator);
    for (int j = 0; str[j] != '\0'; j++) {
        if (is_alphanumeric(str[j], separator) == 1 && n != 0) {
            array[k][n] = '\0';
            k++;
            n = 0;
        }
        if (is_alphanumeric(str[j], separator) == 0) {
            array[k][n] = str[j];
            n++;
        }
    }
    array[k][n] = '\0';
    array[k + 1] = NULL;
    return array;
}
