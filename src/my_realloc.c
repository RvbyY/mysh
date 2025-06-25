/*
** EPITECH PROJECT, 2025
** B-PSU-200-STG-2-1-minishell1-bassirou.tall
** File description:
** my_realloc
*/

#include "../includes/phoenix.h"

void *my_realloc(char **array, int lines)
{
    char **copy;
    int i = 0;

    if (!array || !lines)
        return NULL;
    copy = malloc(sizeof(char *) * (lines + 2));
    for (i; array[i] != NULL; i++) {
        copy[i] = my_strdup(array[i]);
        free(array[i]);
    }
    copy[i] = NULL;
    return copy;
}
