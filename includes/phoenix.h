/*
** EPITECH PROJECT, 2024
** my h
** File description:
** all prototypes of libmy functions
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <signal.h>
#include "minishell2.h"

#ifndef MY_H_
	#define MY_H_

struct info_param {
    int length;
    char *str;
    char *copy;
    char **word_array;
};
typedef struct subflags {
    int show_sign;
    int sharp;
    int precision;
    int zero;
    int minus;
    int plus;
} subflags_t;

typedef struct env_s {
    char **env_array;
    int read;
} env_t;

int my_putchar(char c);
char *reverse_string(char *str);
int show_alphabet(void);
int show_combinations(void);
int show_number(int nb);
int show_string(char const *str);
int iterative_factorial(int nb);
int recursive_power(int nb, int p);
int is_prime_number(int nb);
char *my_strcpy(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
char *my_strcapitalize(char *str);
int my_strlen(char const *str);
char **show_params(int argc, char **argv);
int to_number(char const *str);
char *concat_strings(char const *dest, char const *src);
char *duplicate_string(char const *src);
char *concat_parameters(int ac, char **av);
char **split_string(char const *str, char *separtor);
int show_string_array(char *const *array, char **env);
int my_putchar(char c);
int my_put_nbr(int n);
int my_put_nbr_base(unsigned int n, const char *base);
int make_nbr(int nb, const char *base);
double my_putfloat(double n);
double my_putfloat_case(double n);
int my_putfloat_e(double n);
int my_putfloat_e_case(double n);
double f_flag_cpy(double n);
int e_flag_cpy(double n);
int e_case_flag_cpy(double n);
int prepare_delay(double n);
void display_digits(int int2, int d, double n);
int print_decimals_cpy(int int1, double n, int int2, int pow2);
double my_putfloat_g(double n);
double my_putfloat_g_case(double n);
int calcul_power(int powr, int int1, double n);
int call_nbr(va_list args, char n, char *str);
int call_str(va_list args, char n, char *str);
int call_char(va_list args, char n, char *str);
int call_base(va_list args, char n, char *str);
int call_n_p(va_list args, char n, char *str);
int call_f(va_list args, char n);
int call_case(va_list args, char n);
int call_e(va_list args, char n);
int call_e_case(va_list args, char n);
int call_g(va_list args, char n);
int len_pointers(char *str, int *point);
int print_decimals(int int1, double n, int int2, int pow2);
int exposant(int pow2);
int scientific_style(int powr, int *int1, double n);
int my_isneg(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_it(int nb, int power);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
int type_to_display(char type, char *args);
int mini_printf(const char *format, ...);
int my_putpercentage(float percentage);
int hex_to_dec(char *h);
int call_function_1(char n, va_list args, char *str);
int call_function_2(char n, va_list args);
int my_printf(const char *format, ...);
int my_put_ptr(int ptr, char *str);
char *exec_intern_command(char *command, char **parsing);
char **my_strtowordarray(char *str, char separator);
void free_char_array(char **array);
char *my_strdup(char const *src);
int check_path(char *command, env_t *env_array);
int check_command_in_path(char *path, char *command);
char *my_getenv(const char *name, env_t *env_array);
int my_cd(char *filepath, env_t *env);
int my_setenv(const char *name, const char *value, int overwrite, env_t **env);
env_t *array_into_struct(char **env);
void *my_realloc(char **array, int plus_size);
int my_unsetenv(const char *name, env_t **env);
int print_error_message(char *name, char **argv, env_t **env);
void print_my_list(list_t *my_list);
void free_struct_array(element_t **array);
void free_struct_list(list_t *my_list);
int check_token(char arg);
element_t *determine_type(element_t *data);
void keep_op_args(element_t **token_array, char **argv, int i);
int token_parsing(char **argv, env_t *env);
element_t **token_cmp(element_t **manage, int i, int j);
int token_sort(element_t **array, env_t *env);
list_t *add_node(list_t *head, element_t *data);
list_t *token_list(element_t **token_array);
int check_op_in_array(char **array);
void my_semicolon(char **argv, env_t *env);
void my_redirect(char **argv, env_t *env);
void my_pipe(char **argv, env_t *env);
void token_to_function(list_t *my_list, env_t *ent);
void my_underscore(char **argv, char **env);
char *array_to_string(char **array, int end, int begin);
char **prep_array(char **argv);
void check_extern_command(char *command, char **array, env_t *env);
int minish(char **command_parsed, char *command, env_t *env_array);
void my_redirect_r(char **argv, env_t *env);
void my_redirect_l(char **argv, env_t *env);
void my_double_redirect_r(char **argv, env_t *env);
void my_double_redirect_l(char **argv, env_t *env);
void my_error(char **argv, env_t *env);

#endif /* MY_H_ */
