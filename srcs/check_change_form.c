/*
** check_change_form.c for check_change_form in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Thu Mar  3 22:21:53 2016 Paul Wery
** Last update Fri Mar  4 00:16:54 2016 Paul Wery
*/

#include "tetris.h"

int	moove_or_not(char **map, t_tetris *it, t_start_pos *pos)
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
	  if (map[y][x] == '*' && it->obj.tetrimino[n][i] == '*')
	    return (-1);
	  x += 1;
	  i += 1;
	}
      n += 1;
      y += 1;
    }
  return (0);
}

int	check_side_right(t_events *ev, char **map)
{
  t_start_pos	pos;

  if (ev->pos.end_x == 11)
    return (-1);
  pos.start_x = ev->pos.start_x + 1;
  pos.end_x = ev->pos.end_x + 1;
  pos.start_y = ev->pos.start_y + ev->height_time;
  pos.end_y = ev->pos.end_y + ev->height_time;
  if (moove_or_not(map, ev->it, &pos) == 0)
    return (0);
  return (-1);
}

int	check_side_left(t_events *ev, char **map)
{
  t_start_pos	pos;

  if (ev->pos.start_x == 1)
    return (-1);
  pos.start_x = ev->pos.start_x - 1;
  pos.end_x = ev->pos.end_x - 1;
  pos.start_y = ev->pos.start_y + ev->height_time;
  pos.end_y = ev->pos.end_y + ev->height_time;
  if (moove_or_not(map, ev->it, &pos) == 0)
    return (0);
  return (-1);
}

int		check_change_form(t_events *ev, char **map)
{
  t_tetris	*it;
  t_start_pos	pos;

  it = ev->it->next_form;
  pos.start_x = ev->pos.start_x;
  pos.end_x = ev->pos.start_x + it->obj.width;
  pos.start_y = ev->pos.start_y + ev->height_time;
  pos.end_y = ev->pos.start_y + it->obj.height + ev->height_time;
  if (moove_or_not(map, it, &pos) == 0)
    return (0);
  return (-1);
}
