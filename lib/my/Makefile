##
## EPITECH PROJECT, 2018
## paolo reant libmy
## File description:
## Makefile
##

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -W -Iinclude/ -g

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:  fclean all
