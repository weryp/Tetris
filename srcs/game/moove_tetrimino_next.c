/*
** moove_tetrimino_next.c for moove_tetrimino_next in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Thu Mar  3 02:39:40 2016 Paul Wery
** Last update Wed Mar  9 06:49:14 2016 Paul Wery
*/

#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include "tetris.h"

void	my_pause(t_events *ev, t_tetris *list, char **map)
{
  int	ret;

  ret = 0;
  if (cstr(ev->key, ev->key_pause) == 1)
    {
      ev->key[0] = '\0';
      while (cstr(ev->key, ev->key_pause) == 0)
	{
	  copstr(ev->key, "\0", 0);
	  if (read(0, ev->key, 4) == -1)
	    ret = -1;
	  if (cstr(ev->key, ev->key_quit) == 1 || ret == -1)
	    {
	      endwin();
	      ini_end_read(1);
	      free_all(list, map);
	      exit(0);
	    }
	}
    }
}

void	check_border(t_start_pos *pos, t_events *ev)
{
  while (pos->start_x < 1)
    {
      pos->start_x += 1;
      pos->end_x += 1;
    }
  while (pos->end_x > (ev->cols + 1))
    {
      pos->start_x -= 1;
      pos->end_x -= 1;
    }
  while (pos->start_y < 1)
    {
      pos->start_y += 1;
      pos->end_y += 1;
    }
  while (pos->end_y > (ev->lines + 1))
    {
      pos->start_y -= 1;
      pos->end_y -= 1;
    }
}

int	moove_tetrimino_next(char **map, t_events *ev,
			     t_tetris *list)
{
  if (cstr(ev->key, ev->key_drop) == 1)
    {
      while (check_moove(map, ev->it, &ev->pos) == 0)
        {
          ev->pos.start_y += 1;
          ev->pos.end_y += 1;
        }
      change_form(map, ev->it, &ev->pos, ev);
      ini_events(ev, list);
      clean_line(map, ev);
      return (-1);
    }
  my_pause(ev, list, map);
  return (0);
}
