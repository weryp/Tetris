/*
** print_param.h for print_param in /home/wery_p/rendu/PSU_2015_tetris/include
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Feb 29 15:54:56 2016 Paul Wery
** Last update Sun Mar  6 02:26:48 2016 Paul Wery
*/

#ifndef PARAM_H_
# define PARAM_H_

# define MAX_SCORE_SIZE (12)

# define T_MIN_WIDHT (50)
# define T_MIN_HEIGHT (30)

# define SCOREBOX_POSX(data) (0)
# define SCOREBOX_POSY(data) (data->title.size.y + 2)
# define TITLE_POSX(data) (0)
# define TITLE_POSY(data) (0)
# define NEXTBOX_POSX(data) (data->term_size.x - data->nextbox.size.x)
# define NEXTBOX_POSY(data) (0)

# include <curses.h>
# include "tetris.h"

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
  WINDOW	*term;
  t_pos		term_size;
  t_scorebox	scorebox;
  t_nextbox	nextbox;
  t_title	title;
}		t_display_game_param;

#endif /* !PARAM_H_ */
