/*
** errors_functions.c for errors_functions in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Thu Mar  3 10:44:40 2016 Paul Wery
** Last update Sat Mar 12 03:24:17 2016 Paul Wery
*/

#include <stdlib.h>
#include <curses.h>
#include "tetris.h"

void	str_debug(char *str)
{
  int	n;

  n = 0;
  while (str[n] != '\0')
    {
      if (str[n] == 27)
	my_putstr("^E");
      else if (str[n] == ' ')
	my_putstr("(space)");
      else
	my_putchar(str[n]);
      n += 1;
    }
}

int		error_size(t_events *ev, SCREEN *scr, t_tetris *list)
{
  t_tetris	*it;

  it = list->next;
  ev->m_w = 0;
  while (it != list)
    {
      if (it->obj.width > ev->m_w)
	ev->m_w = it->obj.width;
      it = it->next;
    }
  if (LINES < (ev->lines + 14) || COLS < (ev->cols + 14 + 26 + ev->m_w)
     || LINES < 25 || COLS < 58)
    {
      mvprintw(LINES / 2, COLS / 2 - 7, "size too small");
      halfdelay(30);
      getch();
      endwin();
      delscreen(scr);
      exit(0);
    }
  return (0);
}
