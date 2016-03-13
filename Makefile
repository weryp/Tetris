##
## Makefile for makefile in /home/wery_p/rendu/PSU_2015_tetris
##
## Made by Paul Wery
## Login   <wery_p@epitech.net>
##
## Started on  Sun Feb 28 06:27:14 2016 Paul Wery
## Last update Sun Mar 13 00:49:55 2016 Paul Wery
##

NAME	=	tetris

RM	=	rm -f

CC	=	gcc

CFLAGS	=	-W -Wall -Werror -ansi -pedantic -Iinclude

OBJS	=	$(SRCS:.c=.o)

SRCS	=	srcs/game/main.c \
		srcs/game/load_tetriminos.c \
		srcs/game/load_objs.c \
		srcs/game/my_list.c \
		srcs/game/usefull_functions.c \
		srcs/game/create_form_tetriminos.c \
		srcs/game/functions_tetrimino.c \
		srcs/game/moove_tetrimino.c \
		srcs/game/moove_tetrimino_next.c \
		srcs/game/errors_functions.c \
		srcs/game/ini_colors.c \
		srcs/game/check_change_form.c \
		srcs/game/check_ext.c \
		srcs/game/clean_line.c \
		srcs/game/end_game.c \
		srcs/game/params_one.c \
		srcs/game/params_two.c \
		srcs/game/ini_game.c \
		srcs/game/return_fonc.c \
		srcs/game/help.c \
		srcs/game/free_all.c \
		srcs/game/ini_term.c \
		srcs/game/ini_end_read.c \
		srcs/game/debug.c \
		srcs/game/debug_next.c \
		srcs/game/debug_tetrimino.c \
		srcs/game/delete_errors_elems.c \
		srcs/interface/link_with_game.c \
		srcs/interface/print_all.c \
		srcs/interface/display_env.c \
		srcs/interface/elems_state_game.c \
		srcs/interface/save_hight_score.c \
		srcs/interface/next_tetrimino.c \
		srcs/interface/aff_next_tetrimino.c

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) -lncurses

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
