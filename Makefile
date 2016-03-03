##
## Makefile for makefile in /home/wery_p/rendu/PSU_2015_tetris
##
## Made by Paul Wery
## Login   <wery_p@epitech.net>
##
## Started on  Sun Feb 28 06:27:14 2016 Paul Wery
## Last update Wed Mar  2 22:57:27 2016 Paul Wery
##

NAME	=	tetris

RM	=	rm -f

CC	=	gcc

CFLAGS	=	-W -Wall -Werror -ansi -pedantic -Iinclude

OBJS	=	$(SRCS:.c=.o)

SRCS	=	srcs/main.c \
		srcs/load_tetriminos.c \
		srcs/load_objs.c \
		srcs/my_list.c \
		srcs/usefull_functions.c \
		srcs/create_form_tetriminos.c \
		srcs/functions_tetrimino.c \
		srcs/moove_tetrimino.c

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) -lncurses

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
