##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## my_printf
##

SRC	=	my_putchar.c				\
		my_put_nbr.c				\
		my_putfloat.c			\
		my_putfloat_case.c		\
		my_putfloat_e.c			\
		my_putfloat_e_case.c		\
		my_putfloat_g.c			\
		my_putfloat_g_case.c		\
		call_1.c					\
		call_2.c					\
		print_decimals.c			\
		exposant.c				\
		scientific_style.c		\
		my_putstr.c				\
		my_strlen.c				\
		my_compute_power_it.c	\
		my_printf.c				\
		my_put_nbr_base.c		\
		e_flag_cpy.c				\
		f_flag_cpy.c				\
		print_decimals_cpy.c		\
		e_case_flag_cpy.c		\
		len_pointers.c			\
		my_put_ptr.c				\
		concat_strings.c		\
		free_array.c			\
		my_strcmp.c 			\
		my_strdup.c 			\
		my_strlen.c 			\
		my_strncmp.c			\
		reverse_string.c 		\
		split_string.c 			\
		to_number.c 			\

NAME = libmy.a

OBJ = $(SRC:.c=.o)

all:					$(OBJ)
		gcc -c $(SRC) -g
		ar cr $(NAME) $(OBJ)
		mv libmy.a ..

clean:
	rm -f $(OBJ)
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all
