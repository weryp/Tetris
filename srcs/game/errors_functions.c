/*
** errors_functions.c for errors_functions in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Thu Mar  3 10:44:40 2016 Paul Wery
** Last update Fri Mar 11 17:17:46 2016 Paul Wery
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

int	error_size(t_events *ev, SCREEN *scr)
{
  if (LINES < (ev->lines + 2) || COLS < (ev->cols + 2 + 34))
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
