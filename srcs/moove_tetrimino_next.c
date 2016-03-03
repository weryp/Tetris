/*
** moove_tetrimino_next.c for moove_tetrimino_next in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Thu Mar  3 02:39:40 2016 Paul Wery
** Last update Thu Mar  3 03:55:30 2016 Paul Wery
*/

#include <curses.h>
#include "tetris.h"

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
  return (0);
}
