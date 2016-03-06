/*
** clean_line.c for clean_line in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Fri Mar  4 01:08:20 2016 Paul Wery
** Last update Sun Mar  6 01:56:25 2016 Paul Wery
*/

#include <curses.h>
#include <unistd.h>
#include "tetris.h"

void	aff_content_map(char **map, t_events *ev)
{
  int	n;
  int	i;
  char	c[2];

  n = 1;
  c[1] = '\0';
  while (map[n + 1] != NULL)
    {
      i = 1;
      while (map[n][i] != '|' && map[n][i] != '\0')
        {
	  attron(COLOR_PAIR(7));
	  c[0] = map[n][i];
	  mvprintw((LINES / 2) - (ev->lines / 2 + 1) + n,
                   (COLS / 2) - ((ev->cols + 2 + 34) / 2 - 22)
                   + i, c);
          i += 1;
	  attroff(COLOR_PAIR(7));
        }
      n += 1;
    }
}

void	moove_lines(char **map, int n, t_events *ev)
{
  int	y;
  int	i;

  y = n - 1;
  while (y > 0)
    {
      i = 1;
      while (map[y][i] != '|' && map[y][i] != '\0')
	{
	  map[y + 1][i] = map[y][i];
	  i += 1;
	}
      y -= 1;
    }
  aff_content_map(map, ev);
}

void	destroy_line(char **map, int n, t_events *ev)
{
  int	i;

  i = 1;
  ev->level += 0.1;
  while (map[n][i] != '|' && map[n][i] != '\0')
    map[n][i++] = ' ';
  moove_lines(map, n, ev);
}

void	clean_line(char **map, t_events *ev)
{
  int	n;
  int	i;
  int	width;

  n = 0;
  width = 1;
  while (map[1][width] != '|' && map[1][width] != '\0')
    width += 1;
  while (map[n] != NULL)
    {
      i = 1;
      while (map[n][i] != '\0' && map[n][i] == '*')
	i += 1;
      if (i == width)
	destroy_line(map, n, ev);
      n += 1;
    }
}
