/*
** main.c for main in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Feb 28 07:09:19 2016 Paul Wery
** Last update Sun Mar 13 23:08:43 2016 Paul Wery
*/

#include <ncurses.h>
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
		   (COLS / 2) - ((ev->cols + 2 + 26 +
				  ev->m_w) / 2 - 22)
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

char	**ini_tetris(t_events *ev)
{
  char	**map;

  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);
  start_color();
  ini_colors();
  if ((map = create_aff_map(0, 0, ev)) == NULL)
    return (NULL);
  if ((ev->color_map = create_aff_map(0, 0, ev)) == NULL)
    return (NULL);
  aff_map(map, ev);
  copstr(ev->key, "\0", 0);
  return (map);
}

void	start_ncurses(t_tetris *tet, t_events *ev,
		      SCREEN *scr, int end)
{
  char	**map;
  char	*title;

  title = get_title("datas/title.txt");
  if ((map = ini_tetris(ev)) != NULL && ev->nb_tet > 0 &&
      ev->cols >= ev->m_w && ev->lines >= ev->m_h)
    while (cstr(ev->key, ev->key_quit) == 0)
      {
	copstr(ev->key, "\0", 0);
	if (read(0, ev->key, 4) == -1)
	  return ;
	generate_tetrimino(ev);
	if (end == 0)
	  if ((end = moove_tetrimino(map, tet, ev, 1)) == -1)
	    end_message(map, ev);
	if (end == 0)
	  link_with_game(ev, tet, title);
	refresh();
      }
  save_high_score(ev->score);
  echo();
  free_all(tet, map, ev->color_map);
  endwin();
  delscreen(scr);
}

int	main(int ac, char **av)
{
  t_ini	i;

  help(ac, av, 0);
  if ((i.tet = create_list()) == NULL)
    return (0);
  if (ini_term(&i.num) == -1)
    return (0);
  if (load_tetriminos(i.tet) != 0)
    return (0);
  ini_events(&i.ev, i.tet);
  ini_game(&i.ev, &i.num);
  if (load_params_tetris(&i.ev, av, 1) == -1)
    error_params(ac, av);
  start_debug(&i.ev, i.tet);
  delete_errors_elems(i.tet);
  if ((i.scr = newterm(NULL, stdout, stdin)) == NULL)
    return (0);
  error_size(&i.ev, i.scr, i.tet);
  if (ini_end_read(0) == -1)
    return (0);
  start_ncurses(i.tet, &i.ev, i.scr, 0);
  ini_end_read(1);
  return (0);
}
