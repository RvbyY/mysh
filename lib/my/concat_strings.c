/*
** EPITECH PROJECT, 2024
** concat_string
** File description:
** concat_string
*/

#include "../../includes/lib.h"

char *concat_strings(char *dest, char *src)
{
    int len = my_strlen(dest);
    char *temp = malloc(sizeof(char) * (len + my_strlen(src) + 1));
    int i = 0;

    for (int j = 0; dest && dest[j] != '\0'; j++)
        temp[j] = dest[j];
    for (i; src && src[i] != '\0'; i++)
        temp[len + i] = src[i];
    temp[len + i] = '\0';
    return temp;
}
