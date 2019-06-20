##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC		=	gcc

CFLAGS	=	-Wall -Wextra  -W -Iinclude/ -g

SRC		=	main.c						\
			load_minishell.c			\
			create_env.c				\
			tools.c						\
			init.c						\
			exit.c						\
			show_env.c					\
			set_env.c					\
			unset_env.c					\
			make_cd.c					\
			exec_prog1.c				\
			exec_prog2.c				\
			create_tree.c				\
			tree_tools.c				\
			manage_separator.c			\
			manage_separator2.c			\
			manage_separator_tools.c	\
			echo.c						\
			echo2.c						\
			echo_error.c				\
			create_alias.c				\
			path.c						\
			terms.c

OBJ		=	$(SRC:.c=.o)

NAME	=	42sh

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my all
	$(CC) $(OBJ) -L./lib/my -ltermcap -lmy  -o $(NAME) $(FLAGS)

clean:
	make -C lib/my clean
	rm -f $(OBJ)

fclean: clean
	make -C lib/my fclean
	rm -f $(NAME)

re: fclean all
