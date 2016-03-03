/*
** moove_tetrimino_next.c for moove_tetrimino_next in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Thu Mar  3 02:39:40 2016 Paul Wery
** Last update Fri Mar  4 00:17:33 2016 Paul Wery
*/

#include <stdlib.h>
#include <curses.h>
#include "tetris.h"

void	my_pause(t_events *ev)
{
  if (ev->key == 32)
    {
      ev->key = 0;
      while (ev->key != 32)
	{
	  ev->key = getch();
	  if (ev->key == 27)
	    {
	      endwin();
	      exit(0);
	    }
	}
    }
}

void	check_border(t_start_pos *pos)
{
  while (pos->start_x < 1)
    {
      pos->start_x += 1;
      pos->end_x += 1;
    }
  while (pos->end_x > 11)
    {
      pos->start_x -= 1;
      pos->end_x -= 1;
    }
  while (pos->start_y < 1)
    {
      pos->start_y += 1;
      pos->end_y += 1;
    }
  while (pos->end_y > 21)
    {
      pos->start_y -= 1;
      pos->end_y -= 1;
    }
}

int	moove_tetrimino_next(char **map, t_events *ev,
			     t_tetris *list)
{
  if (ev->key == KEY_DOWN)
    {
      while (check_moove(map, ev->it, &ev->pos) == 0)
        {
          ev->pos.start_y += 1;
          ev->pos.end_y += 1;
        }
      change_form(map, ev->it, &ev->pos);
      ini_events(ev, list);
      return (-1);
    }
  my_pause(ev);
  return (0);
}
