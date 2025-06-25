/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** my_strstr
*/

#include "../../includes/lib.h"

char *my_strstr(char *str, char const *to_find)
{
    int len = my_strlen(to_find);
    int i = 0;

    while (my_strncmp(str, to_find, len) != 0 && str[i] != '\0') {
        i++;
        str = &str[i];
    }
    if (my_strncmp(str, to_find, len) == 0)
        return str;
    else
        return NULL;
}
