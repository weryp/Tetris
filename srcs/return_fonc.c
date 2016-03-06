/*
** return_fonc.c for return_fonc in /home/wery_p/rendu/PSU_2015_tetris/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Fri Mar  4 15:57:47 2016 Paul Wery
** Last update Sat Mar  5 23:29:59 2016 Paul Wery
*/

#include "tetris.h"

int	check_src(char *str, char *src, int n, int i)
{
  int	turn;

  turn = 0;
  while (src[n] != '\0')
    {
      i = 0;
      while (str[i] == src[n] && src[n] != ';')
	{
	  i += 1;
	  n += 1;
	}
      if (src[n] == ';' && ((str[i - 1] == '=' && i > 6) || str[i] == '\0'))
	return ((turn / 2));
      while (src[n] != ';' && src[n] != '\0')
	n += 1;
      if (src[n] != '\0')
	n += 1;
      turn += 1;
    }
  return (-1);
}
int	opt(char *str, char *src_one,
	    char *src_two, char *src_three)
{
  int	fonc;

  fonc = -1;
  fonc = check_src(str, src_one, 0, 0);
  if (fonc == -1)
    {
      fonc = check_src(str, src_two, 0, 0);
      if (fonc != -1)
	fonc += 3;
    }
  if (fonc == -1)
    {
      fonc = check_src(str, src_three, 0, 0);
      if (fonc != -1)
	fonc += 6;
    }
  return (fonc);
}
