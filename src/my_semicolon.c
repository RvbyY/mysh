/*
** EPITECH PROJECT, 2025
** B-PSU-200-STG-2-1-minishell2-bassirou.tall
** File description:
** my_semicolon
*/

#include "../includes/minishell2.h"
#include "../includes/phoenix.h"

void my_semicolon(char **argv, env_t *env)
{
    int status;
    char **command_array = NULL;
    char *to_exec = NULL;

    for (size_t i = 0; i < 2; i++) {
        if (!argv[i])
            continue;
        command_array = split_string(argv[i], " ");
        if (!command_array || !command_array[0])
            continue;
        to_exec = exec_intern_command(command_array[0], command_array);
        if (to_exec)
            minish(command_array, to_exec, env);
        else
            check_extern_command(command_array[0], command_array, env);
        free(to_exec);
        free_char_array(command_array);
    }
    return;
}
