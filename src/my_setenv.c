/*
** EPITECH PROJECT, 2024
** my_setenv
** File description:
** my_setenv
*/

#include "../includes/phoenix.h"

char *env_strcat(char const *dest, char const *src)
{
    int len = my_strlen(dest) + 1;
    char *temp;
    int i = 0;
    int j = 0;

    if (!src)
        return concat_strings(dest, "=");
    temp = malloc(sizeof(char) * (len + my_strlen(src) + 2));
    for (j; dest[j] != '\0'; j++)
        temp[j] = dest[j];
    temp[j] = '=';
    for (i; src[i] != '\0'; i++)
        temp[len + i] = src[i];
    temp[len + i] = '\0';
    return temp;
}

int end_setenv(env_t **env, int i, char *total_value)
{
    (*env)->env_array = my_realloc((*env)->env_array, i);
    (*env)->env_array[i] = my_strdup(total_value);
    (*env)->env_array[i + 1] = NULL;
    free(total_value);
}

int my_setenv(const char *name, const char *value, int overwrite, env_t **env)
{
    int i = 0;
    char *total_value;
    char *new_value;

    if (!name || !env)
        return 84;
    total_value = my_strdup(env_strcat(name, value));
    new_value = my_strdup(total_value);
    for (i; (*env)->env_array[i] != NULL; i++) {
        if (!my_strncmp((*env)->env_array[i], name, my_strlen(name))
            && overwrite == 0)
            return 0;
        if (!my_strncmp((*env)->env_array[i], name, my_strlen(name))
            && overwrite != 0) {
            free((*env)->env_array[i]);
            (*env)->env_array[i] = new_value;
            return 0;
        }
    }
    end_setenv(env, i, total_value);
}
