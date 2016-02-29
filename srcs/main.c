/*
** main.c for main in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Feb 28 07:09:19 2016 Paul Wery
** Last update Mon Feb 29 15:27:09 2016 Paul Wery
*/

#include "tetris.h"
#include "curses.h"

int	main()
{
  int	key;

  key = 0;
  initscr();
  newterm(NULL, stderr, stdin);
  while (key != 10)
    key = getch();
  endwin();
  return (0);
}
