/*
** functions_tetrimino.c for functions_tetrimino in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Wed Mar  2 21:17:56 2016 Paul Wery
** Last update Sun Mar 13 03:21:37 2016 Paul Wery
*/

#include <ncurses.h>
#include <stdlib.h>
#include "tetris.h"

void	clear_tetrimino(char **map, t_start_pos *pos, t_obj *obj,
			t_events *ev)
{
  t_co	c;

  c.n = 0;
  c.y = pos->start_y;
  while (c.y < pos->end_y)
    {
      c.i = 0;
      c.x = pos->start_x;
      while (c.x < pos->end_x)
	{
	  if (map[c.y][c.x] == '*' && obj->tetrimino[c.n][c.i] == '*')
	    {
	      map[c.y][c.x] = ' ';
	      ev->color_map[c.y][c.x] = 0;
	    }
	  c.x += 1;
	  c.i += 1;
	}
      c.n += 1;
      c.y += 1;
    }
}

int	check_moove(char **map, t_tetris *it, t_start_pos *pos)
{
  int	x;
  int	y;
  int	n;
  int	i;

  n = 0;
  y = pos->start_y + 1;
  while (y < (pos->end_y + 1))
    {
      i = 0;
      x = pos->start_x;
      while (x < pos->end_x)
	{
	  if ((map[y][x] == '*' && it->obj.tetrimino[n][i] == '*')
	      || map[y][x] == '-')
	    return (-1);
	  x += 1;
	  i += 1;
	}
      n += 1;
      y += 1;
    }
  return (0);
}

void	ini_pos(t_start_pos *pos, t_events *ev)
{
  pos->start_x = (ev->cols / 2) - (ev->it->obj.width / 2);
  pos->end_x = pos->start_x + ev->it->obj.width;
  pos->start_y = 1;
  pos->end_y = pos->start_y + ev->it->obj.height;
}

void		ini_events(t_events *ev, t_tetris *list)
{
  static int	turn = 0;

  if (turn == 0)
    ev->tet_next = 1;
  put_in_order(list);
  ev->nb_tet = 1;
  ev->it = list->next;
  if (ev->it == list)
    {
      ev->nb_tet = 0;
      my_putstr("There is no valid tetrimino !\n");
    }
  while (ev->it->next != list)
      {
	ev->nb_tet += 1;
	ev->it = ev->it->next;
      }
  ev->tet_start = 0;
  ev->tetrimino = 0;
  ev->form = 0;
  ev->key[0] = '\0';
  ev->time_end = 0;
  ev->height_time = 0;
  turn = 1;
}

void		generate_tetrimino(t_events *ev)
{
  if (ev->tetrimino == 0)
    {
      ev->tetrimino = ev->tet_next;
      ev->tet_next = rand() % (ev->nb_tet) + 1;
    }
}
