/*
** EPITECH PROJECT, 2025
** B-PSU-200-STG-2-1-minishell2-bassirou.tall
** File description:
** minishell2
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <signal.h>

#ifndef MINI_SH_2
    #define MINI_SH_2
    #define TOKEN_REDIRECT_R '<'
    #define TOKEN_REDIRECT_L '>'

static const char *token_separator_c[] = {"<<", ">>", "<", ">", ";", "|", 0};

typedef enum {
    T_SEMICOLON,         //semicolon type
    T_PIPE,              //pipe type
    T_REDIRECT_R,        //right redirect type
    T_DOUBLE_REDIRECT_R, //double right redirect
    T_REDIRECT_L,        //left redirect type
    T_DOUBLE_REDIRECT_L, //double left redirect
    T_ERROR              //error type (undefined operation)
} type_t;

typedef struct {
    char *token;
    type_t type;
} token_t;

typedef struct {
    char *pre_arg;
    char *next_arg;
    token_t token;
} element_t;

typedef struct list_s {
    type_t node_type;
    char *pre_arg;
    char *next_arg;
    struct list_s *next;
} list_t;

typedef struct {
    type_t type;
    void (*function)();
} function_t;

#endif /* MINI_SH_2 */
