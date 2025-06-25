/*
** EPITECH PROJECT, 2025
** B-PSU-200-STG-2-1-minishell1-bassirou.tall
** File description:
** exec_intern_command
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../includes/phoenix.h"

char *exec_intern_command(char *command, char **parsing)
{
    char *command_path = my_strdup("/bin/");

    if (!parsing || my_strcmp(command, "cd") == 0 ||
    my_strcmp(command, "setenv") == 0 || my_strcmp(command, "unsetenv") == 0)
        return NULL;
    if (my_strncmp(command_path, command, 4) == 0)
        return command;
    command_path = concat_strings(command_path, command);
    return command_path;
}
