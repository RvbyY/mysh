/*
** EPITECH PROJECT, 2025
** B-PSU-200-STG-2-1-minishell1-bassirou.tall
** File description:
** check_path
*/

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include "../includes/phoenix.h"
#define _GNU_SOURCE
#include <stdlib.h>

int check_command_in_path(char *path, char *command)
{
    DIR *dir = opendir(path);
    struct dirent *d;

    if (!dir || !command)
        return 84;
    d = readdir(dir);
    while (d) {
        if (my_strcmp(d->d_name, command) == 0)
            return 0;
        d = readdir(dir);
    }
    closedir(dir);
    return 84;
}

int check_path(char *command, env_t *env_array)
{
    char *env = my_strdup(my_getenv("PATH", env_array));
    char *str = strtok(env, "PATH=");
    char *path = strtok(str, ":");

    if (!command || !env)
        return 84;
    while (path != NULL) {
        if (check_command_in_path(path, command) == 0)
            return 0;
        path = strtok(NULL, ":");
    }
    return 84;
}
