/*
** main.c for main in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Feb 28 07:09:19 2016 Paul Wery
** Last update Thu Mar  3 01:02:51 2016 Paul Wery
*/

#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

int	error_size()
{
  if (LINES < 20 || COLS < 44)
    {
      mvprintw(LINES / 2, COLS / 2 - 7, "size too small");
      halfdelay(30);
      getch();
      return (-1);
    }
  return (0);
}

void	aff_map(char **map)
{
  int	n;
  int	i;

  n = 0;
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

int		main()
{
  WINDOW	*new_win;
  char		**map;
  t_tetris	*tet;
  t_events	ev;

  new_win = initscr();
  keypad(new_win, TRUE);
  curs_set(0);
  if ((tet = create_list()) == NULL)
    return (0);
  if (load_tetriminos(tet) == 0)
    {
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
  endwin();
  return (0);
}
