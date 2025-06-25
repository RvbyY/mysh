##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## phoenix
##

SRC 	=								src/check_op_in_array.c     \
										src/check_path.c			\
										src/exec_intern_command.c	\
										src/free_my_struct.c		\
										src/main.c					\
										src/my_cd.c					\
										src/my_getenv.c				\
										src/my_pipe.c				\
										src/my_realloc.c			\
										src/my_redirect.c			\
										src/my_error.c				\
										src/my_semicolon.c			\
										src/my_setenv.c				\
										src/my_unsetenv.c			\
										src/print_error_message.c	\
										src/print_list.c			\
										src/token_list.c			\
										src/token_parsing.c			\
										src/token_sort.c			\
										src/token_to_function.c		\
										src/prep_array.c

CC = @gcc

CFLAGS += -Wextra -Werror -g -o

INC = -I includes/

NAME = mysh

all: make_lib $(NAME)

make_lib:
		@$(MAKE) -C lib/my

$(NAME): $(SRC)
		$(CC) $(CFLAGS) $(NAME) $(SRC) lib/libmy.a $(INC)

clean:
		rm -f src/*.o
		rm -f lib/my/*.o
		rm -f lib/my/*~
		rm -f lib/my/#*#
		rm -f *~
		rm -f #*#

fclean:	clean
		rm -f $(NAME)
		rm -f lib/libmy.a

re:	fclean all
