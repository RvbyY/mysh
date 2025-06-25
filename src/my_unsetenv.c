/*
** EPITECH PROJECT, 2025
** B-PSU-200-STG-2-1-minishell1-bassirou.tall
** File description:
** my_unsetenv
*/

#include "../includes/phoenix.h"

int end_unsetenv(char **copy, env_t **env, int count)
{
    int i;

    copy[count] = NULL;
    free_char_array((*env)->env_array);
    (*env)->env_array = malloc(sizeof(char *) * (count + 1));
    if (!(*env)->env_array)
        return 84;
    for (i = 0; i < count; i++) {
        (*env)->env_array[i] = my_strdup(copy[i]);
        if (!(*env)->env_array[i])
            return 84;
    }
    (*env)->env_array[i] = NULL;
    free_char_array(copy);
    return 0;
}

int my_unsetenv(const char *name, env_t **env)
{
    char **copy;
    int i = 0, count = 0;
    int new_index = 0;

    if (!name || !env || !(*env) || !(*env)->env_array)
        return 84;
    for (i = 0; (*env)->env_array[i] != NULL; i++) {
        if (my_strncmp((*env)->env_array[i], name, my_strlen(name)) != 0)
            count++;
    }
    copy = malloc(sizeof(char *) * (count + 1));
    if (!copy)
        return 84;
    for (i = 0; (*env)->env_array[i] != NULL; i++) {
        if (my_strncmp((*env)->env_array[i], name, my_strlen(name)) == 0)
            continue;
        copy[new_index++] = my_strdup((*env)->env_array[i]);
    }
    copy[new_index] = NULL;
    return end_unsetenv(copy, env, count);
}
