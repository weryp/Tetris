/*
** main.c for main in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Feb 28 07:09:19 2016 Paul Wery
** Last update Mon Feb 29 18:08:19 2016 Paul Wery
*/

#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"
#include <stdio.h>
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

int	create_aff_map(char **map, int n, int i)
{
  while (n < 22)
    {
      i = 0;
      while (i < 12)
	{
	  if ((map[n] = malloc(13)) == NULL)
	    return (-1);
	  if (n == 0 || n == 21)
	    map[n][i] = '-';
	  else if (i == 0 || i == 11)
	    map[n][i] = '|';
	  else
	    map[n][i] = ' ';
	  mvprintw((LINES / 2) - 11  + n, (COLS / 2) + 2 + i, &map[n][i]);
	  i += 1;
	}
      map[n++][i] = '\0';
    }
  map[n] = NULL;
  return (0);
}

int	ini_tetris(const char *file, char **map)
{
  newterm(file, stderr, stdin);
  if ((map = malloc(23 * sizeof(char*))) == NULL)
    return (-1);
  if (create_aff_map(map, 0, 0) == -1)
    return (-1);
  if (error_size() == -1)
    return (-1);
  return (0);
}

int		main()
{
  WINDOW	*new_win;
  char		**map;
  int		key;

  key = 0;
  new_win = initscr();
  map = NULL;
  if (ini_tetris((const char*)new_win, map) == 0)
    while (key != 10)
      {
	refresh();
	nodelay(new_win, TRUE);
	key = getch();
      }
  endwin();
  return (0);
}
