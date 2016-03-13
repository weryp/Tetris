/*
** next_tetrimino.c for next_tetrimino in /home/wery_p/rendu/PSU_2015_tetris/srcs/interface
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 12 18:42:47 2016 Paul Wery
** Last update Sat Mar 12 23:59:51 2016 Paul Wery
*/

#include <ncurses.h>
#include "print_param.h"

void	my_print(int line, int col, char c)
{
  char	ch[2];

  ch[0] = c;
  ch[1] = '\0';
  mvprintw(line, col, ch);
}

void	aff_start_end_edge(int line, int col,
			   int max_width, int n)
{
  int	i;

  i = 0;
  if (n == -1)
    my_print(line + n + 1, col, '/');
  else
    my_print(line + n + 1, col, '\\');
  while (i < max_width)
    {
      my_print(line + n + 1, col + i + 1, '-');
      i += 1;
    }
  if (n == -1)
    my_print(line + n + 1, col + i + 1, '\\');
  else
    my_print(line + n + 1, col + i + 1, '/');
}

void	aff_edge(int line, int col, int max_width, int max_height)
{
  int	n;
  int	i;

  n = 0;
  aff_start_end_edge(line, col, max_width, -1);
  while (n < max_height)
    {
      i = 0;
      my_print(line + n + 1, col, '|');
      while (i < max_width)
	{
	  my_print(line + n + 1, col + i + 1, ' ');
	  i += 1;
	}
      my_print(line + n + 1, col + i + 1, '|');
      n += 1;
    }
  aff_start_end_edge(line, col, max_width, n);
}

void	print_next_tetrimino(t_display_env *data)
{
  int	max_width;
  int	max_height;

  max_width = data->ev->m_w + 2;
  max_height = data->ev->m_h + 2;
  aff_edge(LINES / 2 - (data->ev->lines / 2 + 1),
	   COLS / 2 - ((data->ev->cols + 2 + 26 + data->ev->m_w) / 2
		       - (24 + data->ev->cols + 2)),
	   max_width, max_height);
  data->posi.line = LINES / 2 - (data->ev->lines / 2 + 1);
  data->posi.col = COLS / 2 - ((data->ev->cols + 2 + 26 + data->ev->m_w) / 2
			      - (24 + data->ev->cols + 2));
  data->posi.max_width = max_width;
  data->posi.max_height = max_height;
  put_tet_in_edge(data);
}
