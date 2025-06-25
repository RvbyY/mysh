/*
** EPITECH PROJECT, 2025
** B-PSU-200-STG-2-1-minishell2-bassirou.tall
** File description:
** token_parsing
*/

#include "../includes/minishell2.h"
#include "../includes/phoenix.h"

int check_token(char arg)
{
    if (!arg)
        return 84;
    for (int j = 0; token_separator_c[j] != 0; j++)
        if (arg == token_separator_c[j][0])
            return 0;
    return 84;
}

element_t *determine_type(element_t *data)
{
    token_t array[] = {
        {";", T_SEMICOLON},
        {"|", T_PIPE},
        {"<", T_REDIRECT_R},
        {"<<", T_DOUBLE_REDIRECT_R},
        {">", T_REDIRECT_L},
        {">>", T_DOUBLE_REDIRECT_L},
        {"ERR", T_ERROR}
    };

    for (int i = 0; array[i].type != T_ERROR; i++)
        if (my_strcmp(data->token.token, array[i].token) == 0) {
            data->token.type = array[i].type;
            return data;
        }
    data->token.type = T_ERROR;
    return data;
}

char *array_to_string(char **array, int end, int begin)
{
    char *string;
    int total_len = 0;

    if (!array || begin >= end)
        return NULL;
    for (int i = begin; i < end; i++)
        if (array[i])
            total_len += my_strlen(array[i]);
    total_len += (end - begin - 1);
    total_len += 1;
    string = malloc(sizeof(char) * total_len);
    if (!string)
        return NULL;
    string[0] = '\0';
    for (int i = begin; i < end; i++) {
        if (array[i]) {
            string = concat_strings(string, array[i]);
            if (i + 1 < end && array[i + 1])
                string = concat_strings(string, " ");
        }
    }
    return string;
}


static int detetct_next_op(char **argv, int begin)
{
    int index = begin;

    for (index; argv[index] != NULL; index++) {
        if (check_token(argv[index][0]) == 0)
            return index;
    }
    return index;
}

void keep_op_args(element_t **token_array, char **argv, int i)
{
    static int index = 0;
    int second_arg = 0;

    if (!token_array || !argv[i])
        return;
    (*token_array)->pre_arg = array_to_string(argv, i, index);
    second_arg = detetct_next_op(argv, i + 1);
    (*token_array)->next_arg = array_to_string(argv,
        second_arg, i + 1);
    index = i + 1;
}

static element_t **process_tokens(char **argv, int token_count)
{
    element_t **token_array = malloc(sizeof(element_t *) * (token_count + 1));
    int n = 0;

    for (int i = 0; argv[i] != NULL; i++) {
        if (check_token(argv[i][0]) == 0) {
            token_array[n] = malloc(sizeof(element_t));
            token_array[n]->token.token = my_strdup(argv[i]);
            token_array[n] = determine_type(token_array[n]);
            keep_op_args(&token_array[n], argv, i);
            n++;
        }
    }
    token_array[n] = NULL;
    return token_array;
}

int token_parsing(char **array, env_t *env)
{
    char **argv = prep_array(array);
    int token_count = 0;
    element_t **token_array = NULL;

    for (int i = 0; argv[i] != NULL; i++) {
        if (check_token(argv[i][0]) == 0)
            token_count++;
    }
    token_array = process_tokens(argv, token_count);
    token_sort(token_array, env);
    return 0;
}
