/*
** print_param.h for print_param in /home/wery_p/rendu/PSU_2015_tetris/include
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Feb 29 15:54:56 2016 Paul Wery
** Last update Sat Mar 12 02:34:01 2016 Paul Wery
*/

#ifndef PARAM_H_
# define PARAM_H_

# include <curses.h>
# include "tetris.h"

typedef	struct	s_state_game
{
  int		level;
  int		timer;
  int		player_score;
  int		hight_score;
}		t_state_game;

typedef	struct	s_display_env
{
  t_events	*ev;
  t_tetris	*list;
  t_state_game	state;
  t_start_pos	pos;
}		t_display_env;

void		link_with_game(t_events *ev, t_tetris *list);
int		print_all(t_display_env *data);
void		print_title(void);
void		print_state_game(t_display_env *data);
void		print_score(t_display_env *data, int line, int col);
void		print_level(t_display_env *data, int line, int col);
void		print_timer(int line, int col);
void		print_nbr(int nb, int line, int col);

#endif /* !PARAM_H_ */
