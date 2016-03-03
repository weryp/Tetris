/*
** moove_tetrimino.c for moove_tetrimino in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Wed Mar  2 16:40:24 2016 Paul Wery
** Last update Thu Mar  3 01:11:48 2016 Paul Wery
*/

#include <curses.h>
#include <stdlib.h>
#include "tetris.h"

int	change_form(char **map, t_tetris *it, t_start_pos *pos)
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
	  if (it->obj.tetrimino[n][i] == '*')
	    map[y][x] = '*';
	  i += 1;
	  x += 1;
	}
      n += 1;
      y += 1;
    }
  aff_map(map);
  return (0);
}

void		moove_tetrimino(char **map, t_tetris *list,
				t_events *ev, int turn)
{
  ev->it = list->next;
  if (ev->tetrimino == 0)
    ev->tetrimino = rand() % (ev->nb_tet - 1) + 1;
  while (turn < ev->tetrimino)
    {
      turn += 1;
      ev->it = ev->it->next;
    }
  turn = 0;
  while (turn < ev->form)
    {
      turn += 1;
      ev->it = ev->it->next_form;
    }
  ini_pos(&ev->pos, &ev->it->obj);
  if (ev->key == KEY_UP)
    ev->form += 1;
  if (ev->form == 4)
    ev->form = 0;
  change_form(map, ev->it, &ev->pos);
  clear_tetrimino(map, &ev->pos, &ev->it->obj);
  ev->tetrimino = 0;
}
