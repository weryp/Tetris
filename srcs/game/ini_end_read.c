/*
** ini_end_read.c for ini_end_read in /home/wery_p/rendu/PSU_2015_tetris/srcs/game
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Tue Mar  8 21:18:10 2016 Paul Wery
** Last update Thu Mar 10 00:26:57 2016 Paul Wery
*/

#include <sys/ioctl.h>
#include <termios.h>

int			ini_end_read(int state)
{
  struct termios	term;

  if (state == 0)
    {
      if (ioctl(0, TCGETS, &term) == -1)
	return (-1);
      term.c_lflag &= ~ICANON;
      term.c_cc[VMIN] = 0;
      term.c_cc[VTIME] = 0.1;
      if (ioctl(0, TCSETS, &term) == -1)
	return (-1);
    }
  else
    {
      if (ioctl(0, TCGETS, &term) == -1)
	return (-1);
      term.c_lflag = 35387;
      if (ioctl(0, TCSETS, &term) == -1)
	return (-1);
    }
  return (0);
}
