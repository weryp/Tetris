/*
** end_game.c for end_game in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Fri Mar  4 03:25:34 2016 Paul Wery
** Last update Sun Mar 13 19:54:00 2016 Paul Wery
*/

#include <ncurses.h>
#include "tetris.h"

void	end_message(char **map, t_events *ev)
{
  int	n;
  int	i;

  n = 1;
  while (map[n + 1] != NULL)
    {
      i = 1;
      while (map[n][i] != '|' && map[n][i] != '\0')
        {
	  mvprintw(((LINES / 2) - (ev->lines / 2 + 1) + n),
                   ((COLS / 2) - ((ev->cols + 2 + 26 + ev->m_w) / 2 - 22) + i),
		   " ");
          i += 1;
        }
      n += 1;
    }
  init_pair(1, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  mvprintw((LINES / 2),
	   ((COLS / 2) - ((ev->cols + 2 + 26 + ev->m_w) / 2 - 22) +
	    (ev->cols / 2 - 3)),
	   "GAME OVER");
  attroff(COLOR_PAIR(1));
}

int	end_game(char **map, t_start_pos *pos, t_obj *obj)
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
            return (-1);
          x += 1;
          i += 1;
        }
      n += 1;
      y += 1;
    }
  return (0);
}
