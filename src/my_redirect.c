/*
** EPITECH PROJECT, 2025
** B-PSU-200-STG-2-1-minishell2-bassirou.tall
** File description:
** my_redirect
*/

#include "../includes/minishell2.h"
#include "../includes/phoenix.h"
#include <stdbool.h>


void my_redirect_r(char **argv, env_t *env)
{
    int to_text = 0;
    int saved_stdout = dup(STDOUT_FILENO);
    char **command_array = split_string(argv[0], " ");
    char *to_exec = NULL;

    if (!command_array)
        return;
    to_exec = exec_intern_command(command_array[0], command_array);
    to_text = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY);
    dup2(to_text, STDOUT_FILENO);
    close(to_text);
    if (to_exec)
        minish(command_array, to_exec, env);
    else
        check_extern_command(command_array[0], command_array, env);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);
    free(to_exec);
    free_char_array(command_array);
    return;
}

void my_redirect_l(char **argv, env_t *env)
{
    int to_text = 0;
    int saved_stdout = dup(STDOUT_FILENO);
    char **command_array = split_string(argv[1], " ");
    char *to_exec = NULL;

    if (!command_array)
        return;
    to_exec = exec_intern_command(command_array[0], command_array);
    to_text = open(argv[0], O_CREAT | O_TRUNC | O_WRONLY);
    dup2(to_text, STDOUT_FILENO);
    close(to_text);
    if (to_exec)
        minish(command_array, to_exec, env);
    else
        check_extern_command(command_array[0], command_array, env);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);
    free(to_exec);
    free_char_array(command_array);
    return;
}

void my_double_redirect_r(char **argv, env_t *env)
{
    int to_text = 0;
    int saved_stdout = dup(STDOUT_FILENO);
    char **command_array = split_string(argv[0], " ");
    char *to_exec = NULL;

    if (!command_array)
        return;
    to_exec = exec_intern_command(command_array[0], command_array);
    to_text = open(argv[1], O_WRONLY | O_CREAT | O_APPEND);
    dup2(to_text, STDOUT_FILENO);
    close(to_text);
    if (to_exec)
        minish(command_array, to_exec, env);
    else
        check_extern_command(command_array[0], command_array, env);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);
    free(to_exec);
    free_char_array(command_array);
    return;
}

void my_double_redirect_l(char **argv, env_t *env)
{
    int to_text = 0;
    int saved_stdout = dup(STDOUT_FILENO);
    char **command_array = split_string(argv[1], " ");
    char *to_exec = NULL;

    if (!command_array)
        return;
    to_exec = exec_intern_command(command_array[0], command_array);
    to_text = open(argv[0], O_WRONLY | O_CREAT | O_APPEND);
    dup2(to_text, STDOUT_FILENO);
    close(to_text);
    if (to_exec)
        minish(command_array, to_exec, env);
    else
        check_extern_command(command_array[0], command_array, env);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);
    free(to_exec);
    free_char_array(command_array);
    return;
}
