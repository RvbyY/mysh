/*
** EPITECH PROJECT, 2024
** my_cd
** File description:
** my_cd
*/

#include "../includes/phoenix.h"

int my_cd(char *filepath, env_t *env)
{
    size_t size = sizeof(filepath);
    char buffer[size];

    if (!env)
        return 84;
    if (!filepath)
        chdir(my_getenv("HOME", env));
    else if (my_strncmp("~", filepath, 1) == 0) {
        chdir(my_getenv("HOME", env));
    } else
        chdir(filepath);
    return 0;
}
