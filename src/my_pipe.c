/*
** EPITECH PROJECT, 2025
** B-PSU-200-STG-2-1-bsminishell2-bassirou.tall
** File description:
** my_pipe
*/

#include "../includes/minishell2.h"
#include "../includes/phoenix.h"

int work_process(int fd[], char **argv, char **env, int type)
{
    if (!fd || !argv)
        return 84;
    dup2(fd[type], type);
    close(fd[0]);
    close(fd[1]);
    execve(argv[0], argv, env);
    return 84;
}

static void launch_child(int fd[], char *cmd, char **env, int type)
{
    char **args = split_string(cmd, " ");

    if (!args)
        exit(84);
    work_process(fd, args, env, type);
    free_char_array(args);
    exit(84);
}

static int fork_commands(char **argv, char **env, int fd[], int *pid2)
{
    int pid1 = fork();

    if (pid1 < 0)
        return 84;
    if (pid1 == 0)
        launch_child(fd, argv[0], env, STDOUT_FILENO);
    *pid2 = fork();
    if (*pid2 < 0)
        return 84;
    if (*pid2 == 0)
        launch_child(fd, argv[1], env, STDIN_FILENO);
    return 0;
}

void my_pipe(char **argv, env_t *env)
{
    int fd[2];
    int pid2 = fork();

    if (!argv || !env || pipe(fd) == -1)
        return;
    if (fork_commands(argv, env->env_array, fd, &pid2) == 84)
        return;
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);
}
