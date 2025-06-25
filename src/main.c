/*
** EPITECH PROJECT, 2025
** B-PSU-200-STG-2-1-minishell1-bassirou.tall
** File description:
** we_lied_to_you
*/

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include "../includes/phoenix.h"
#define _GNU_SOURCE
#include <stdlib.h>
#include <errno.h>
#include <error.h>
#include <stdbool.h>

env_t *array_into_struct(char **env)
{
    env_t *final_array = malloc(sizeof(env_t));
    int j = 0;

    if (!final_array || !env)
        return NULL;
    for (j; env[j] != NULL; j++);
    final_array->env_array = malloc(sizeof(char *) * (j + 1));
    for (j = 0; env[j] != NULL; j++) {
        final_array->env_array[j] = my_strdup(env[j]);
    }
    final_array->env_array[j] = NULL;
    return final_array;
}

static void my_perror(const char *input)
{
    int err = errno;

    if (!input)
        return;
    if (err == ENOENT) {
        write(2, input, strlen(input));
        write(2, ": Command not found.\n", 21);
        return;
    }
}

int minish(char **command_parsed, char *command, env_t *env_array)
{
    pid_t pid;
    int sig;
    int status;

    if (!command_parsed || !command)
        return 84;
    pid = fork();
    if (pid == 0) {
        if (check_path(command_parsed[0], env_array) == 84 &&
            my_strcmp(command_parsed[0], "cd") != 0) {
                if (execve(command_parsed[0], command_parsed, env_array->env_array) < 0) {
                    //my_perror(command_parsed[0]);
                    exit(1);
                }
            }
        else if (execve(command, command_parsed, env_array->env_array) < 0) {
            my_perror(command_parsed[0]);
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
        if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV) {
            write(2, "Segmentation fault", 19);
            return 84;
        } else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGFPE) {
            write(2, "Floating exception", 18);
            return 84;
        }
    }
    return WIFEXITED(status) ? WEXITSTATUS(status) : 84;
}

void check_extern_command(char *command, char **array, env_t *env)
{
    if (!command || !env)
        return;
    if (my_strcmp(command, "cd") == 0)
        my_cd(array[1], env);
    if (my_strcmp(command, "setenv") == 0)
        if (!array[1] || array[1] == NULL) {
            free(command);
            command = my_strdup("/bin/env");
            minish(array, command, env);
        } else
            my_setenv(array[1], array[2], 1, &env);
    if (my_strcmp(command, "unsetenv") == 0)
        my_unsetenv(array[1], &env);
}

static int handle_input(char **array, env_t *env)
{
    char *command;

    if (check_op_in_array(array) == 0) {
        token_parsing(array, env);
        return env->read;
    }
    command = my_strdup(exec_intern_command(array[0], array));
    check_extern_command(array[0], array, env);
    minish(array, command, env);
    free_char_array(array);
    free(command);
    return env->read;
}

char *trim_str(char *str, char *copy, size_t i, size_t j)
{
    bool seen_space = false;

    for (; str[i] != '\0'; i++) {
        if ((str[i] == ' ' || str[i] == '\t') && !seen_space) {
            copy[j] = ' ';
            seen_space = true;
        } else {
            copy[j] = str[i];
            seen_space = false;
        }
        j++;
    }
    if (j > 0 && copy[j - 1] == ' ')
        j--;
    copy[j] = '\0';
    return copy;
}

char *check_spaces(char *str)
{
    char *copy = NULL;
    size_t i = 0;
    size_t j = 0;

    if (!str)
        return NULL;
    for (i; str[i] == ' ' || str[i] == '\t'; i++);
    copy = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (!copy)
        return NULL;
    copy = trim_str(str, copy, i, j);
    free(str);
    return copy;
}

int infinity_loop(char *line, env_t *env, char *command, char **array)
{
    size_t len = 0;
    char *copy;

    if (isatty(0) != 0)
        my_printf("$> ");
    env->read = getline(&line, &len, stdin);
    copy = my_strdup(line);
    strtok(copy, "\n");
    copy = check_spaces(copy);
    array = split_string(copy, " ");
    if (my_strncmp(copy, "exit", 4) == 0)
        exit(0);
    for (size_t i = 0; array[i]; i++)
    {
        dprintf(1, "%ld: %s", i, array[i]);
    }
    
    env->read = handle_input(array, env);
    free(copy);
    return env->read;
}

int main(int argc, char **argv, char **env)
{
    char *line = NULL;
    FILE *fp;
    int read = 0;
    char *command = NULL;
    char **array = NULL;
    env_t *env_array = array_into_struct(env);

    if (!argc || !argv || !env)
        return 84;
    while (read != -1) {
        read = infinity_loop(line, env_array, command, array);
    }
    free(line);
    return 0;
}
