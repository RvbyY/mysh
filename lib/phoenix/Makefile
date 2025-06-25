##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## phoenix
##

SRC =	my_putchar.c			\
		show_number.c			\
		show_string.c			\
		reverse_string.c		\
		to_number.c				\
		is_prime_number.c		\
		my_strcpy.c				\
		my_strncmp.c			\
		my_strstr.c				\
		my_strlen.c				\

NAME = libphoenix.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f *.o

fclean:	clean
		rm -f $(NAME)

re:	fclean all
