/*
** EPITECH PROJECT, 2025
** B-PSU-200-STG-2-1-minishell2-bassirou.tall
** File description:
** token_to_function
*/

#include "../includes/minishell2.h"
#include "../includes/phoenix.h"

void token_to_function(list_t *my_list, env_t *env)
{
    function_t array[] = {
        {T_SEMICOLON, &my_semicolon}, {T_PIPE, &my_pipe},
        {T_REDIRECT_R, &my_redirect_r},
        {T_DOUBLE_REDIRECT_R, &my_double_redirect_r},
        {T_REDIRECT_L, &my_redirect_l},
        {T_DOUBLE_REDIRECT_L, &my_double_redirect_l}, {T_ERROR, &my_error}
    };
    char *str;
    char **argv;

    if (!my_list)
        return;
    str = concat_strings(my_list->pre_arg, "\n");
    str = concat_strings(str, my_list->next_arg);
    argv = split_string(str, "\n");
    for (int i = 0; i < 6; i++)
        if (array[i].type == my_list->node_type)
            array[i].function(argv, env);
    free_char_array(argv);
    free(str);
}
