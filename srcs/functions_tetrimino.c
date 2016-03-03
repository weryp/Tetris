/*
** functions_tetrimino.c for functions_tetrimino in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Wed Mar  2 21:17:56 2016 Paul Wery
** Last update Thu Mar  3 03:12:58 2016 Paul Wery
*/

#include <curses.h>
#include "tetris.h"

void	clear_tetrimino(char **map, t_start_pos *pos, t_obj *obj)
{
  int	x;
  int	y;
  int	n;
  int	i;

  n = 0;
  y = pos->start_y;
  while (y < pos->end_y)
    {
      i = 0;
      x = pos->start_x;
      while (x < pos->end_x)
	{
	  if (map[y][x] == '*' && obj->tetrimino[n][i] == '*')
	    map[y][x] = ' ';
	  x += 1;
	  i += 1;
	}
      n += 1;
      y += 1;
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

void	ini_pos(t_start_pos *pos, t_obj *obj)
{
  pos->start_x = 5;
  pos->end_x = pos->start_x + obj->width;
  pos->start_y = 1;
  pos->end_y = pos->start_y + obj->height;
}

void	ini_events(t_events *ev, t_tetris *list)
{
  ev->nb_tet = 0;
  ev->it = list->next;
  while (ev->it->next != list)
    {
      ev->nb_tet += 1;
      ev->it = ev->it->next;

    }
  ev->tet_start = 0;
  ev->tetrimino = 0;
  ev->form = 0;
  ev->key = 0;
  ev->time_start = 0;
  ev->time_end = 0;
  ev->height_time = 0;
}
