/*
** EPITECH PROJECT, 2025
** B-PSU-200-STG-2-1-minishell1-bassirou.tall
** File description:
** my_getenv
*/

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include "../includes/phoenix.h"
#define _GNU_SOURCE
#include <stdlib.h>

char *my_getenv(const char *name, env_t *env)
{
    char *buffer = NULL;
    char *temp = NULL;

    for (int i = 0; env->env_array[i] != NULL; i++) {
        temp = my_strdup(env->env_array[i]);
        buffer = strtok(temp, "=");
        if (my_strcmp(name, buffer) == 0) {
            buffer = strtok(NULL, "\n");
            return buffer;
        }
    }
    return NULL;
}
