/*
** help.c for help in /home/wery_p/rendu/PSU_2015_tetris/srcs/game
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Mar  6 18:10:04 2016 Paul Wery
** Last update Sun Mar 13 01:48:22 2016 Paul Wery
*/

#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	n;

  n = 0;
  while (str[n] != '\0')
    {
      my_putchar(str[n]);
      n += 1;
    }
}


void	aff_help(char *exec)
{
  my_putstr("Usage: ");
  my_putstr(exec);
  my_putstr(" [options]\nOptions:\n");
  my_putstr("  --help\t\tDisplay this help\n");
  my_putstr("  -l --level={num}\tStart Tetris at level num\n");
  my_putstr("  -kl --key-left={K}\tMove tetrimino on LEFT with key K\n");
  my_putstr("  -kr --key-right={K}\tMove tetrimino on RIGHT with key K\n");
  my_putstr("  -kt --key-turn={K}\tTurn tetrimino with key K\n");
  my_putstr("  -kd --key-drop={K}\tSet default DROP on key K\n");
  my_putstr("  -kq --key-quit={K}\tQuit program when press key K\n");
  my_putstr("  -kp --key-pause={K}\tPause and restart game when press key K\n");
  my_putstr("  --map-size={row,col}\tSet game size at row, col\n");
  my_putstr("  -w --without-next\tHide next tetrimino\n");
  my_putstr("  -d --debug\t\tDebug mode\n");
}

int	cstr(char *str, char *src)
{
  int	n;

  n = 0;
  while (str[n] == src[n] && str[n] != '\0' && src[n] != '\0')
    n += 1;
  if (str[n] == '\0' && src[n] == '\0')
    return (1);
  return (0);
}

void	help(int ac, char **av, int state)
{
  int	n;
  int	ret;

  n = 1;
  ret = 0;
  if (ac > 1)
    {
      while (av[n] != NULL && ret == 0)
	{
	  ret = cstr(av[n], "--help");
	  n += 1;
	}
      if (ret == 1 || state == 1)
	{
	  aff_help(av[0]);
	  exit(0);
	}
    }
}
