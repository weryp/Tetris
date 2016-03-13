/*
** aff_next_tetrimino.c for aff_next_tetrimino in /home/wery_p/rendu/PSU_2015_tetris/srcs/interface
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 12 22:04:03 2016 Paul Wery
** Last update Sat Mar 12 23:59:28 2016 Paul Wery
*/

#include <ncurses.h>
#include "print_param.h"

void	aff_tet_in_edge(t_obj obj, int line, int col)
{
  char	c[2];
  int	n;
  int	i;

  n = 0;
  c[1] = '\0';
  while (n < obj.height)
    {
      i = 0;
      while (i < obj.width)
	{
	  c[0] = obj.tetrimino[n][i];
	  attron(COLOR_PAIR(obj.color));
	  if (obj.tetrimino[n][i] == '*')
	    mvprintw(line + n, col + i, c);
	  attroff(COLOR_PAIR(obj.color));
	  i += 1;
	}
      n += 1;
    }
}

void		put_tet_in_edge(t_display_env *data)
{
  t_tetris	*it;
  int		n;

  n = 1;
  it = data->list->next;
  while (n < data->ev->tet_next)
    {
      n += 1;
      it = it->next;
    }
  data->posi.col += (data->posi.max_width + 2) / 2 - it->obj.width / 2;
  data->posi.line += (data->posi.max_height + 2) / 2 - it->obj.height / 2;
  aff_tet_in_edge(it->obj, data->posi.line, data->posi.col);
}
