/*
** print_param.h for print_param in /home/wery_p/rendu/PSU_2015_tetris/include
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Feb 29 15:54:56 2016 Paul Wery
** Last update Wed Mar  2 00:26:51 2016 Paul Wery
*/

#ifndef PARAM_H_
# define PARAM_H_

# define MAX_SCORE_SIZE (12)

#include "tetris.h"

typedef	struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef	struct	s_scorebox
{
  int		level;
  int		player_score;
  int		best_score;
  int		time;
  t_pos		pos;
  t_pos		size;
}		t_scorebox;

typedef	struct	s_title
{
  char		*title;
  t_pos		pos;
}		t_title;

typedef	struct	s_nextbox
{
  struct s_obj	*obj;
  t_pos		pos;
  t_pos		size;
}		t_nextbox;

typedef	struct	s_display_game_param
{
  t_pos		term_size;
  t_scorebox	scorebox;
  t_nextbox	nextbox;
  t_title	title;
}		t_display_game_param;

int check_terminal_size(t_display_game_param*);
int update_display_game(t_display_game_param*);
int init_display_param(t_display_game_param*);

#endif /* !PARAM_H_ */
