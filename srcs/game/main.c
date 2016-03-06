/*
** main.c for main in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Feb 28 07:09:19 2016 Paul Wery
** Last update Sun Mar  6 01:55:01 2016 Paul Wery
*/

#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

void	aff_map(char **map, t_events *ev)
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
	  mvprintw((LINES / 2) - (ev->lines / 2 + 1) + n,
		   (COLS / 2) - ((ev->cols + 2 + 34) / 2 - 22)
		   + i, &map[n][i]);
	  i += 1;
	}
      n += 1;
    }
  attroff(COLOR_PAIR(6));
}

char	**create_aff_map(int n, int i, t_events *ev)
{
  char	**map;

  if ((map = malloc((ev->lines + 3) * sizeof(char*))) == NULL)
    return (NULL);
  while (n < (ev->lines + 2))
    {
      i = 0;
      if ((map[n] = malloc(ev->cols + 3)) == NULL)
	return (NULL);
      while (i < (ev->cols + 2))
	{
	  if (n == 0 || n == (ev->lines + 1))
	    map[n][i++] = '-';
	  else if (i == 0 || i == (ev->cols + 1))
	    map[n][i++] = '|';
	  else
	    map[n][i++] = ' ';
	}
      map[n++][i] = '\0';
    }
    map[n] = NULL;
  return (map);
}

char	**ini_tetris(const char *file, t_events *ev)
{
  char	**map;

  newterm(file, stderr, stdin);
  if ((map = create_aff_map(0, 0, ev)) == NULL)
    return (NULL);
  if (error_size(ev) == -1)
    return (NULL);
  aff_map(map, ev);
  return (map);
}

void		start_ncurses(t_tetris *tet, WINDOW *new_win,
			      int ac, char **av)
{
  t_events	ev;
  char		**map;
  int		end;

  end = 0;
  ini_events(&ev, tet);
  ini_game(&ev);
  if (ac > 1)
    load_params_tetris(&ev, av);
  if ((map = ini_tetris((const char*)new_win, &ev)) != NULL)
    while (ev.key != ev.key_quit)
      {
	refresh();
	nodelay(new_win, TRUE);
	ev.key = getch();
	if (end == 0)
	  if ((end = moove_tetrimino(map, tet, &ev, 1)) == -1)
	    end_message(map, &ev);
      }
}

int		main(int ac, char **av)
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
    start_ncurses(tet, new_win, ac, av);
  echo();
  endwin();
  return (0);
}
