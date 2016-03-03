/*
** main.c for main in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Feb 28 07:09:19 2016 Paul Wery
** Last update Fri Mar  4 00:42:46 2016 Paul Wery
*/

#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

void	aff_map(char **map)
{
  int	n;
  int	i;

  n = 0;
  attron(COLOR_PAIR(6));
  while (map[n] != NULL)
    {
      i = 0;
      while (map[n][i] != '\0')
	{
	  mvprintw((LINES / 2) - 11  + n, (COLS / 2) + 2 + i, &map[n][i]);
	  i += 1;
	}
      n += 1;
    }
  attroff(COLOR_PAIR(6));
}

char	**create_aff_map(int n, int i)
{
  char	**map;

  if ((map = malloc(23 * sizeof(char*))) == NULL)
    return (NULL);
  while (n < 22)
    {
      i = 0;
      if ((map[n] = malloc(13)) == NULL)
	return (NULL);
      while (i < 12)
	{
	  if (n == 0 || n == 21)
	    map[n][i++] = '-';
	  else if (i == 0 || i == 11)
	    map[n][i++] = '|';
	  else
	    map[n][i++] = ' ';
	}
      map[n++][i] = '\0';
    }
    map[n] = NULL;
  return (map);
}

char	**ini_tetris(const char *file)
{
  char	**map;

  newterm(file, stderr, stdin);
  if ((map = create_aff_map(0, 0)) == NULL)
    return (NULL);
  if (error_size() == -1)
    return (NULL);
  aff_map(map);
  return (map);
}

void		start_ncurses(t_tetris *tet, WINDOW *new_win)
{
  t_events	ev;
  char		**map;

  ini_events(&ev, tet);
  if ((map = ini_tetris((const char*)new_win)) != NULL)
    while (ev.key != 27)
      {
	refresh();
	nodelay(new_win, TRUE);
	ev.key = getch();
	moove_tetrimino(map, tet, &ev, 1);
      }
}

int		main()
{
  WINDOW	*new_win;
  t_tetris	*tet;

  new_win = initscr();
  noecho();
  keypad(new_win, TRUE);
  curs_set(0);
  start_color();
  ini_colors();
  if ((tet = create_list()) == NULL)
    return (0);
  if (load_tetriminos(tet) == 0)
    start_ncurses(tet, new_win);
  echo();
  endwin();
  return (0);
}
