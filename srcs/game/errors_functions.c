/*
** errors_functions.c for errors_functions in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Thu Mar  3 10:44:40 2016 Paul Wery
** Last update Sun Mar  6 01:42:31 2016 Paul Wery
*/

#include <curses.h>
#include "tetris.h"

int	error_size(t_events *ev)
{
  if (LINES < (ev->lines + 2) || COLS < (ev->cols + 2 + 34))
    {
      mvprintw(LINES / 2, COLS / 2 - 7, "size too small");
      halfdelay(30);
      getch();
      return (-1);
    }
  return (0);
}
