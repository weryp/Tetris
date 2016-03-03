/*
** errors_functions.c for errors_functions in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Thu Mar  3 10:44:40 2016 Paul Wery
** Last update Thu Mar  3 10:46:30 2016 Paul Wery
*/

#include <curses.h>

int	error_size(void)
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
