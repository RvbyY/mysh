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
#include <stdbool.h>
#include <dirent.h>
#include <fcntl.h>
#include <signal.h>
#include "amazed.h"
#include "op.h"

#ifndef MY_H_
    #define MY_H_
    #define MAGIC_NUMBER -209458688

typedef struct flags {
    int dump;
    int prog_number;
    int *load_address;
} flags_t;

typedef struct process_s {
    int pc;
    int registers[REG_NUMBER];
    int carry;
    int prog_number;
    int last_live;
    int alive;
    struct process_s *next;
} process_t;

typedef struct champ_s {
    header_t *header;
    flags_t *flag;
    bool live;
    unsigned char **command_buffer;
    int live_cycle;
    unsigned int *cycle;
    int carry;
    int registers[REG_NUMBER];
    struct champ_s *next;
    char *prog_name;
} champ_t;

typedef struct instruction_s {
    int inst;
    void (*fonction)();
} instruction_t;

typedef struct storage {
    champ_t *champ_h;
    int number_live;
    int last_live;
    int dump;
    char **prog_name;
    int cycle;
    int amount_champ;
    int cycle_to_die;
    u_int8_t arena[MEM_SIZE + 1];
} storage_t;

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
char *concat_strings(char *dest, char *src);
char *duplicate_string(char const *src);
char *concat_parameters(int ac, char **av);
char **split_string(char const *str, char *separtor);
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
char *my_strdup(char const *src);
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
int check_command_in_path(char *path, char *command);
void *my_realloc(char **array, int plus_size);
void print_error_message(char *command);
void parse_my_data(data_t *storage, char **array);
void init_tunnel(tunnel_t **tunnel, char *name);
tunnel_t *store_tunnels(tunnel_t *tunnel, char *name);
void parse_tunnels(data_t *storage, char **array, int i);
void get_nb_robots(data_t *storage, char *buffer);
void store_instruc_room(link_t **room, char *name);
link_t *store_room(link_t *room, char *name);
void which_instruc_room(data_t *storage, char *str, char *instruction);
void free_storage(data_t storage);
void store_special_room(link_t *room, char *name);
void free_data(storage_t *data);
storage_t *argument_parsing(int argc, char **argv);
void store_flags(flags_t *flags, char *flag, char *value);
int check_flags(char *str);
int prog_name_finder(FILE *fd, header_t *header, unsigned char buf);
int prog_comment_finder(FILE *fd, header_t *header, unsigned char buf);
int cor_openener(storage_t *data, header_t *header);
void fill_str(char *str, int size);
int command_reader(header_t *data, FILE *fd, char c);
void live(storage_t *data, process_t *proc);
void add(champ_t *head, storage_t *vm, u_int8_t *instruction);
void ld_operator(storage_t *data, process_t *proc);
void st_operator(storage_t *data, process_t *proc);
void sub(champ_t *head, storage_t *vm, u_int8_t *instruction);
void and_operation(storage_t *data, process_t *proc);
void or_operation(storage_t *data, process_t *proc);
void xor_operation(storage_t *data, process_t *proc);
void zjmp(storage_t *data, process_t *proc);
void ldi_operator(storage_t *data, process_t *proc);
void long_ld(storage_t *data, process_t *proc);
void long_ldi(storage_t *data, process_t *proc);
void long_fork(storage_t *data, process_t *proc);
void sti_operator(storage_t *data, process_t *proc);
void fork_operator(storage_t *data, process_t *proc);
void ascii_code(storage_t *data, process_t *proc);
int cor_finder(char *file);
int big_endian_int(FILE *fd);
char **argument_tok(char **argv, int amount);
int argument_sweeper(champ_t *champ, flags_t *flag, char **args);
unsigned char **uchar_toward_array(unsigned char *instr, int size);
int cycler(champ_t *champ);
int type_checker(const op_t *blueprint, unsigned char coding_byte, int index);
int break_conditions(storage_t *data);
int dump_finder(char **argv, int argc);
int champ_ordering(champ_t **head);
void aff(storage_t *data, process_t *proc);
void no_op(storage_t *data, process_t *proc);
process_t *champ_spawner(storage_t *data);
int arg_giver(unsigned char *arena, int local);
champ_t *find_champion(storage_t *data, int prog_number);
int proc_executer(storage_t *data, process_t *head);

#endif /* MY_H_ */
