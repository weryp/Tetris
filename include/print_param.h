/*
** print_param.h for print_param in /home/wery_p/rendu/PSU_2015_tetris/include
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Feb 29 15:54:56 2016 Paul Wery
** Last update Sat Apr  2 20:13:58 2016 Paul Wery
*/

#ifndef PARAM_H_
# define PARAM_H_

# define STATE_GAME_TOP_BOX "/------------------\\"
# define STATE_GAME_M_BOX "|                  |"

# include <ncurses.h>
# include "tetris.h"

typedef	struct	s_pos
{
  int		line;
  int		col;
  int		max_width;
  int		max_height;
}		t_pos;

typedef	struct	s_display_env
{
  t_events	*ev;
  t_tetris	*list;
  t_pos		posi;
  t_start_pos	pos;
  char		*header;
}		t_display_env;

void		link_with_game(t_events *ev, t_tetris *list, char *title);
int		print_all(t_display_env *data, char *title);
void		print_header(char *header);
void		print_state_game(t_display_env *data);
void		print_score(t_display_env *data, int line, int col);
void		print_level(t_display_env *data, int line, int col);
void		print_timer(int line, int col);
void		print_nbr(int nb, int line, int col);
void		save_high_score(int score_player);
int		get_high_score(void);
void		print_next_tetrimino(t_display_env *data);
void		put_tet_in_edge(t_display_env *data);

#endif /* !PARAM_H_ */
