/*
** ini_colors.c for ini_colors in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Thu Mar  3 11:31:15 2016 Paul Wery
** Last update Sun Mar  6 01:58:03 2016 Paul Wery
*/

#include <curses.h>
#include "tetris.h"

void	clear_map(char **map, t_events *ev)
{
  int	n;
  int	i;

  n = 0;
  while (map[n] != NULL)
    {
      i = 0;
      while (map[n][i] != '\0')
        {
	  if (map[n][i] == ' ')
	    mvprintw((LINES / 2) - (ev->lines / 2 + 1) + n,
		     (COLS / 2) - ((ev->cols + 2 + 34) / 2 - 22)
		     + i, " ");
          i += 1;
        }
      n += 1;
    }
}

void	aff_map_color(char **map, t_tetris *it,
		      t_start_pos *pos, t_events *ev)
{
  int	x;
  int	y;
  int	n;
  int	i;

  n = 0;
  y = pos->start_y;
  attron(COLOR_PAIR(it->obj.color));
  while (y < pos->end_y)
    {
      i = 0;
      x = pos->start_x;
      while (x < pos->end_x)
        {
	  if (map[y][x] == '*' && it->obj.tetrimino[n][i] == '*')
	    mvprintw((LINES / 2) - (ev->lines / 2 + 1) + y,
		     (COLS / 2) - ((ev->cols + 2 + 34) / 2 - 22)
		     + x, "*");
          x += 1;
          i += 1;
        }
      n += 1;
      y += 1;
    }
  attroff(COLOR_PAIR(it->obj.color));
}

void	ini_colors(void)
{
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
}
