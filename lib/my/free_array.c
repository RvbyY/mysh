/*
** EPITECH PROJECT, 2025
** B-PSU-200-STG-2-1-minishell1-bassirou.tall
** File description:
** free_array
*/

/*
** EPITECH PROJECT, 2024
** free_array
** File description:
** bassirou
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "../../includes/lib.h"

void free_int_array(int **array, int lines)
{
    for (int i = 0; i < lines - 1; i++)
        free(array[i]);
}

void free_char_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
