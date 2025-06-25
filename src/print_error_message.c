/*
** EPITECH PROJECT, 2025
** B-PSU-200-STG-2-1-minishell1-bassirou.tall
** File description:
** print_error_message
*/

#include <errno.h>
#include <error.h>
#include <string.h>
#include "../includes/phoenix.h"

int my_alphanum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122))
            return 84;
    return 0;
}

int print_error_message(char *name, char **argv, env_t **env)
{
    if (!env || !name) {
        my_printf("Not enough argument\n");
        return 84;
    }
    if (my_alphanum(name) != 0) {
        my_printf("Not alphanumeric\n");
        return 84;
    } else if (argv[3]) {
        my_printf("To many argument\n");
        return 84;
    }
    return 0;
}
