/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** copying a string with malloc
*/

#include "../../includes/lib.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *copy_src;
    int i = 0;

    if (!src)
        return NULL;
    copy_src = malloc(sizeof(char) * my_strlen(src) + 1);
    while (src[i] != '\0') {
        copy_src[i] = src[i];
        i++;
    }
    copy_src[i] = '\0';
    return copy_src;
}
